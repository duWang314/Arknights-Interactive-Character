#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Base64 编码表
const char b64_table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

/**
 * @brief 对数据进行 Base64 编码
 *
 * @param input 输入数据的指针
 * @param input_len 输入数据的长度（字节）
 * @param output_len 输出编码后字符串的长度指针
 * @return 返回编码后的字符串（需要手动释放内存）
 */
char* base64_encode(const unsigned char *input, size_t input_len, size_t *output_len) {
    // 计算编码后的大致长度
    *output_len = 4 * ((input_len + 2) / 3);
    char *output = (char *)malloc(*output_len + 1); // 为空终止符'\0'额外分配空间
    if (output == NULL) {
        return NULL;
    }

    size_t i, j;
    for (i = 0, j = 0; i < input_len;) {
        // --- 处理3个字节（24位）的数据块 ---
        unsigned int octet_a = i < input_len ? input[i++] : 0;
        unsigned int octet_b = i < input_len ? input[i++] : 0;
        unsigned int octet_c = i < input_len ? input[i++] : 0;

        // 组合成一个24位的整数
        unsigned int triple = (octet_a << 16) + (octet_b << 8) + octet_c;

        // --- 从24位中提取4个6位的索引 ---
        output[j++] = b64_table[(triple >> 18) & 0x3F];
        output[j++] = b64_table[(triple >> 12) & 0x3F];
        output[j++] = b64_table[(triple >> 6) & 0x3F];
        output[j++] = b64_table[triple & 0x3F];
    }

    // --- 处理填充字符 '=' ---
    // 根据输入数据的长度，将末尾的'A'替换为'='
    // input_len % 3 == 1, 表示最后剩1个字节，需要2个'='填充
    // input_len % 3 == 2, 表示最后剩2个字节，需要1个'='填充
    int padding_count = (3 - (input_len % 3)) % 3;
    for (i = 0; i < padding_count; i++) {
        output[*output_len - 1 - i] = '=';
    }
    
    output[*output_len] = '\0'; // 添加字符串结束符

    return output;
}

int main(int argc, char *argv[]) {
    // --- 1. 验证命令行参数 ---
    if (argc != 2) {
        fprintf(stderr, "用法: %s <文件名>\n", argv[0]);
        return 1;
    }

    const char *input_filename = argv[1];
    
    // --- 2. 打开输入文件 ---
    FILE *input_file = fopen(input_filename, "rb"); // "rb" 表示以二进制只读方式打开
    if (input_file == NULL) {
        perror("错误：无法打开输入文件");
        return 1;
    }

    // --- 3. 读取文件内容 ---
    // 将文件指针移动到文件末尾
    fseek(input_file, 0, SEEK_END);
    // 获取文件大小
    size_t file_size = ftell(input_file);
    // 将文件指针移回文件开头
    rewind(input_file);

    // 分配内存以存储整个文件内容
    unsigned char *file_buffer = (unsigned char *)malloc(file_size);
    if (file_buffer == NULL) {
        fprintf(stderr, "错误：无法分配内存读取文件\n");
        fclose(input_file);
        return 1;
    }

    // 读取文件到缓冲区
    size_t bytes_read = fread(file_buffer, 1, file_size, input_file);
    if (bytes_read != file_size) {
        fprintf(stderr, "错误：读取文件时发生错误\n");
        fclose(input_file);
        free(file_buffer);
        return 1;
    }
    fclose(input_file);

    // --- 4. 进行 Base64 编码 ---
    size_t output_len;
    char *encoded_data = base64_encode(file_buffer, file_size, &output_len);
    free(file_buffer); // 释放原始文件数据缓冲区

    if (encoded_data == NULL) {
        fprintf(stderr, "错误：Base64 编码失败\n");
        return 1;
    }

    // --- 5. 构建输出文件名 ---
    char *output_filename = (char *)malloc(strlen(input_filename) + strlen("_output.txt") + 1);
    if (output_filename == NULL) {
        fprintf(stderr, "错误：无法为输出文件名分配内存\n");
        free(encoded_data);
        return 1;
    }
    strcpy(output_filename, input_filename);
    strcat(output_filename, "_output.txt");

    // --- 6. 打开并写入输出文件 ---
    FILE *output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        perror("错误：无法创建输出文件");
        free(encoded_data);
        free(output_filename);
        return 1;
    }

    fprintf(output_file, "%s", encoded_data);
    
    // --- 7. 清理和收尾 ---
    fclose(output_file);
    free(encoded_data);
    
    printf("文件 '%s' 已成功编码为 '%s'\n", input_filename, output_filename);
    free(output_filename);

    return 0;
}