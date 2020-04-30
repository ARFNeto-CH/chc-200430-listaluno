#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nome[20];
    int  cod;
    int  turma;
}Aluno;

int main(int argc, char** argv)
{
    // apenas le o arquivo ate o fim e mostra
    char linha[40];
    FILE* entrada = fopen("turmas.txt", "r");
    fgets(linha, 20, entrada);
    while (!(feof(entrada)))
    {
        printf("%s", linha);
        fgets(linha, 20, entrada);
    }
    fclose(entrada);
    return 0;
};  // fase1()
