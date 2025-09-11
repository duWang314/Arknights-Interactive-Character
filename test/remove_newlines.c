#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "用法：%s <文件名>.txt\n", argv[0]);
        return 1;
    }

    /* 构造输出文件名：原文件名前部 + "_output.txt" */
    const char *in_name  = argv[1];
    size_t base_len = strlen(in_name);

    /* 简单安全检查：确保以 .txt 结尾 */
    if (base_len < 4 || strcmp(in_name + base_len - 4, ".txt") != 0) {
        fprintf(stderr, "错误：输入文件必须是 .txt 后缀\n");
        return 1;
    }

    size_t out_len = base_len + 8;                 /* "_output" + '\0' */
    char *out_name = malloc(out_len);
    if (!out_name) {
        perror("malloc");
        return 1;
    }
    snprintf(out_name, out_len, "%.*s_output.txt", (int)(base_len - 4), in_name);

    FILE *fin  = fopen(in_name, "r");
    if (!fin) {
        perror("无法打开输入文件");
        free(out_name);
        return 1;
    }

    FILE *fout = fopen(out_name, "w");
    if (!fout) {
        perror("无法创建输出文件");
        fclose(fin);
        free(out_name);
        return 1;
    }

    int ch;
    while ((ch = fgetc(fin)) != EOF) {
        if (ch != '\n') fputc(ch, fout);
    }

    fclose(fin);
    fclose(fout);

    printf("处理完成，结果已写入 %s\n", out_name);
    free(out_name);
    return 0;
}
