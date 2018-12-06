#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "API.h"

#define MAX_SIZE 1024

int main()
{

    int format; // format of input
    int isSymm = 1;
    int isEqual = 1;
    BinTree firstTree[MAX_SIZE] = { 0 };
    char treeStr1[MAX_SIZE * 2] = { 0 };
    BinTree secTree[MAX_SIZE] = { 0 };
    char treeStr2[MAX_SIZE * 2] = { 0 };

    printf("Hello! This is binary tree comparator. I define two binary trees as similar, equal, mirrored or  symmetric.\nEnter trees in bracket short form without spaces. Note: <empty tree> = '(#)'. Rules of short form:\n(<root> <tree> <#>) = (<root> <tree>)\n(<root> ##) = (<root>)\n");
    printf("Type '1', if you want input data from file input.txt, '2' - from the keyboard: ");
    scanf("%d", &format);
    char c = getchar(); // takes '\n'

    if (format != 1 && format != 2) {
        printf("Wrong input format!\n");
        return 0;
    }
    else if (format == 1) { // input from file
        FILE* f;

        if ((f = fopen("input.txt", "r")) == NULL) {
            printf("Couldn't open input.txt\n");
            return 0;
        }
        fgets(treeStr1, MAX_SIZE * 2, f);
        fgets(treeStr2, MAX_SIZE * 2, f);
        fclose(f);
    }
    else if (format == 2) {

        printf("1 tree: ");

        fgets(treeStr1, MAX_SIZE * 2, stdin);

        if (treeStr1[strlen(treeStr1) - 1] == '\n') // deleting '\n' if it exists
            treeStr1[strlen(treeStr1) - 1] = '\0';

        if (!(isCorrect(treeStr1))) // check for correctness
            return 0;

        printf("2 tree: ");
        fgets(treeStr2, MAX_SIZE * 2, stdin);

        if (treeStr2[strlen(treeStr2) - 1] == '\n') // deleting '\n' if it exists
            treeStr2[strlen(treeStr2) - 1] = '\0';

        if (!isCorrect(treeStr2))  // check for correctness
            return 0;
    }

    printf("\nYou entered: %s\n             %s\n", treeStr1, treeStr2);

    createTree(firstTree, treeStr1, 0, 0);  // creating trees
    createTree(secTree, treeStr2, 0, 0);

    printf("\nTree 1: \n");
    for (int i = 0; i < MAX_SIZE; i++) {  // showing trees
        if (firstTree[i].data != 0)
            printf("   %d: left = %d, '%c', right = %d\n", i, firstTree[i].left, firstTree[i].data, firstTree[i].right);
    }

    printf("Tree 2:\n");
    for (int i = 0; i < MAX_SIZE; i++) {
        if (secTree[i].data != 0)
            printf("   %d: left = %d, '%c', right = %d\n", i, secTree[i].left, secTree[i].data, secTree[i].right);
    }

    FILE *f = fopen("output.txt", "w");

    fprintf(f, "Input:\n  %s\n  %s\n\nOutput:\n", treeStr1, treeStr2);

    if (isSimilar(firstTree, secTree, 0, &isEqual) == 1)
        fprintf(f, "  are similar\n");
    else
        fprintf(f, "  aren't similar\n");

    if (isEqual == 1)
        fprintf(f, "  are equal\n");
    else
        fprintf(f, "  aren't equal\n");

    if (isMirrored(firstTree, secTree, 0, &isSymm) == 1)
        fprintf(f, "  are mirrored\n");
    else
        fprintf(f, "  aren't mirrored\n");

    if (isSymm == 1)
        fprintf(f, "  are symmetrical\n");
    else
        fprintf(f, "  aren't symmetrical\n");

    fclose(f);
    return 0;
}