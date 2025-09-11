#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "�÷���%s <�ļ���>.txt\n", argv[0]);
        return 1;
    }

    /* ��������ļ�����ԭ�ļ���ǰ�� + "_output.txt" */
    const char *in_name  = argv[1];
    size_t base_len = strlen(in_name);

    /* �򵥰�ȫ��飺ȷ���� .txt ��β */
    if (base_len < 4 || strcmp(in_name + base_len - 4, ".txt") != 0) {
        fprintf(stderr, "���������ļ������� .txt ��׺\n");
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
        perror("�޷��������ļ�");
        free(out_name);
        return 1;
    }

    FILE *fout = fopen(out_name, "w");
    if (!fout) {
        perror("�޷���������ļ�");
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

    printf("������ɣ������д�� %s\n", out_name);
    free(out_name);
    return 0;
}
