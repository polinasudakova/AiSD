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
        printf("Выберите команду:");
        if (!scanf("%d", &cmd)) {
            printf("Неккоректный ввод.Попробуйте ввести цифру.\n");
            exit(EXIT_FAILURE);
        }
        switch (cmd) {
        case 1: {
            if (in == NULL) {//проверка на открытие
                printf("Не удалось открыть файл input.txt");
                exit(EXIT_FAILURE);
            }
            if (out == NULL) {//проверка на открытие
                printf("Не удалось открыть файл output.txt");
                exit(EXIT_FAILURE);
            }
            empty(s, res);//очищаем массив от мусора
            fprintf(out, "Входные данные(аргумент функции): ");
            printf("Входные данные(аргумент функции): ");
            fscanf(in, "%s", s);
            fprintf(out, "%s\n", s);
            printf("%s\n", s);
            printf("\nАнализирование полученной строки...\n\n");
            fprintf(out, "\nАнализирование полученной строки...\n\n");
            rekurs(s, res,out);//вычисление функции
            printf("\nАнализирование завершено!\n");
            printf("Полученное значение: ");
            fprintf(out,"Полученное значение: ");
            printf("%s%s\n\n", s, res);
            fprintf(out, "%s%s\n", s, res);
            break; }
        case 2:
        {
            empty(s, res);//очищаем массив от мусора
            printf("Введите строку:");
            scanf("%s", s);
            printf("\nАнализирование полученной строки...\n\n");
            fprintf(out, "\nАнализирование  полученной строки...\n\n");
            rekurs(s, res, out);//вычисление функции
            printf("\nАнализирование завершено!\n");
            printf("Полученное преобразование:");
            printf("%s%s\n\n", s, res);
            fprintf(out,"Полученное преобразование:");
            fprintf(out,"%s%s\n\n", s, res);
            break;
        }
        case 3: {
            exit(EXIT_SUCCESS);
            break; }
        default: {
            printf("Некорректная команда\n");
            fprintf(out, "Некорректная команда\n");
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
    if (strchr(s, '/')) {//если есть знак "/"
        printf("Найдено первое вхождение символа \"/\"");
        int kol = strlen(s) - strlen(strchr(s, '/'));
        insert_before(res, s, kol);//копируем отработанную подстроку
        erase(s);//удаляем её
        printf("%s%s", s, res);//вывод промежуточных данных
        fprintf(out,"%s%s", s, res);
        fprintf(stdout, "\nПроверяем на следующее вхождение символа \"/\"\n");
        fprintf(out, "\nПроверяем на следующее вхождение символа \"/\"\n");
        rekurs(s, res,out);//рекурсивный вызов
       
    }
    else {
        printf("Текущая рассматриваемая строка не содержит символа \"/\"\n");
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
    if (s1[0] == '\0') {//если пустая
        strncpy(s1, s2, count);
        printf(", до него стоит подстрока [");
        for (int i = 0; i < count; i++)
        {
            printf("%c",s1[i]);
        }
        printf("], вставляем её в конец еще не обработанной строки\n");
        return;
    }
    for (int i = strlen(s1) - 1; i >= 0; i--)
        s1[i + count] = s1[i];
        strncpy(s1, s2, count);
        printf(", до него стоит подстрока [");
        for (int i = 0; i < count; i++)
        {
            printf("%c", s1[i]);
        }
        printf("], вставляем её в конец еще не обработанной строки\n");
}
void menu()
{
    printf("------------------------------\n");
    printf("Судакова Полина группа 7381,лаб. работа 1\n");
    printf("------------------------------\n");
    printf("1.Ввести строку из файла\n");
    printf("2.Ввести строку с клавиатуры\n");
    printf("3.Выход из меню\n");
    printf("------------------------------\n");
}