#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#define MAX 100
 
void menu();
void insert_before(char*s1, char*s2, int count);
void erase(char*s);
void rekurs(char*s, char*res,FILE*out);
void empty(char*s, char*res);
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    FILE * in;
    FILE* out;
    int cmd,count=0;
    in = fopen("input.txt", "r");
    out = fopen("output.txt", "w");
    char *s = (char*)malloc(MAX*sizeof(char));
    char* res = (char*)malloc(MAX * sizeof(char));
        menu();
        printf("�������� �������:");
        if (!scanf("%d", &cmd)) {
            printf("������������ ����.���������� ������ �����.\n");
            exit(EXIT_FAILURE);
        }
        switch (cmd) {
        case 1: {
            if (in == NULL) {//�������� �� ��������
                printf("�� ������� ������� ���� input.txt");
                exit(EXIT_FAILURE);
            }
            if (out == NULL) {//�������� �� ��������
                printf("�� ������� ������� ���� output.txt");
                exit(EXIT_FAILURE);
            }
            empty(s, res);//������� ������ �� ������
            fprintf(out, "������� ������(�������� �������): ");
            printf("������� ������(�������� �������): ");
            fscanf(in, "%s", s);
            fprintf(out, "%s\n", s);
            printf("%s\n", s);
            printf("\n�������������� ���������� ������...\n\n");
            fprintf(out, "\n�������������� ���������� ������...\n\n");
            rekurs(s, res,out);//���������� �������
            printf("\n�������������� ���������!\n");
            printf("���������� ��������: ");
            fprintf(out,"���������� ��������: ");
            printf("%s%s\n\n", s, res);
            fprintf(out, "%s%s\n", s, res);
            break; }
        case 2:
        {
            empty(s, res);//������� ������ �� ������
            printf("������� ������:");
            scanf("%s", s);
            printf("\n�������������� ���������� ������...\n\n");
            fprintf(out, "\n��������������  ���������� ������...\n\n");
            rekurs(s, res, out);//���������� �������
            printf("\n�������������� ���������!\n");
            printf("���������� ��������������:");
            printf("%s%s\n\n", s, res);
            fprintf(out,"���������� ��������������:");
            fprintf(out,"%s%s\n\n", s, res);
            break;
        }
        case 3: {
            exit(EXIT_SUCCESS);
            break; }
        default: {
            printf("������������ �������\n");
            fprintf(out, "������������ �������\n");
            break;
        }
        }
    free(res);
    free(s);
    fclose(in);
    fclose(out);
    system("pause");
    return 0;
 
}
 
void rekurs(char*s, char*res,FILE*out) {
    if (strchr(s, '/')) {//���� ���� ���� "/"
        printf("������� ������ ��������� ������� \"/\"");
        int kol = strlen(s) - strlen(strchr(s, '/'));
        insert_before(res, s, kol);//�������� ������������ ���������
        erase(s);//������� �
        printf("%s%s", s, res);//����� ������������� ������
        fprintf(out,"%s%s", s, res);
        fprintf(stdout, "\n��������� �� ��������� ��������� ������� \"/\"\n");
        fprintf(out, "\n��������� �� ��������� ��������� ������� \"/\"\n");
        rekurs(s, res,out);//����������� �����
       
    }
    else {
        printf("������� ��������������� ������ �� �������� ������� \"/\"\n");
    }
}
void erase(char*s) {
    int m = strlen(strchr(s, '/'));
    int kol = strlen(s) - strlen(strchr(s, '/'));
    char*p = s;
    if (kol) {
        for (int i = 0; i < m; i++) {
            p[i] = p[i + kol];
            p[i + kol] = '\0';
        }
        p[m] = '\0';
    }
    for (int i = 0; i < m; ++i)
        p[i] = p[i + 1];
}
void empty(char*s, char*res) {
    for (int i = 0; i < MAX; i++) {
        res[i] = '\0';
        s[i] = '\0';
    }
}
void insert_before(char*s1, char*s2, int count) {
    if (s1[0] == '\0') {//���� ������
        strncpy(s1, s2, count);
        printf(", �� ���� ����� ��������� [");
        for (int i = 0; i < count; i++)
        {
            printf("%c",s1[i]);
        }
        printf("], ��������� � � ����� ��� �� ������������ ������\n");
        return;
    }
    for (int i = strlen(s1) - 1; i >= 0; i--)
        s1[i + count] = s1[i];
        strncpy(s1, s2, count);
        printf(", �� ���� ����� ��������� [");
        for (int i = 0; i < count; i++)
        {
            printf("%c", s1[i]);
        }
        printf("], ��������� � � ����� ��� �� ������������ ������\n");
}
void menu()
{
    printf("------------------------------\n");
    printf("�������� ������ ������ 7381,���. ������ 1\n");
    printf("------------------------------\n");
    printf("1.������ ������ �� �����\n");
    printf("2.������ ������ � ����������\n");
    printf("3.����� �� ����\n");
    printf("------------------------------\n");
}