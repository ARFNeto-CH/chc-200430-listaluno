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

void    exibeAluno(Aluno*);
void    leAluno(Aluno*);

int main(int argc, char** argv)
{
    int N = 0;
    char linha[40];
    char turma[2][20];
    char nome[20];
    int cod;
    int criterio = 0;   // zero = cod nao zero classifica por nome
    FILE* entrada = fopen("turmas.txt", "r");

    // le a primeira turma
    fgets(&turma[0][0], 20, entrada);
    turma[0][strlen(turma[0]) - 1] = 0;
    // fgets() le o '\n' do fim da linha!
    fgets(linha, 5, entrada);
    linha[strlen(linha) - 1] = 0; // mesma coisa: tirar o '\n'
    printf("Primeira Turma: \"%s\" com %s alunos\n", turma[0], linha);
    N = atoi(linha); // precisamos de um int
    // agora le os alunos da primeira turma
    for (int i = 0; i < N; i += 1)
    {
        fscanf(entrada, "%s%d", nome, &cod);
        printf("aluno '%s' %d\n", nome, cod);
    };  // for()

    linha[0] = fgetc(entrada); // le o '\n' da ultima linha da turma

    // le a segunda turma
    fgets(&turma[1][0], 20, entrada);
    turma[1][strlen(turma[1]) - 1] = 0;
    // fgets() le o '\n' do fim da linha!
    fgets(linha, 5, entrada);
    linha[strlen(linha) - 1] = 0; // mesma coisa: tirar o '\n'
    printf("Segunda Turma: \"%s\" com %s alunos\n", turma[1], linha);
    N = atoi(linha); // precisamos de um int
    // agora le os alunos da primeira turma
    for (int i = 0; i < N; i += 1)
    {
        fscanf(entrada, "%s%d", nome, &cod);
        printf("aluno '%s' %d\n", nome, cod);
    };  // for()

    linha[0] = fgetc(entrada); // le o '\n' da ultima linha da turma 2
    fgets(linha, 5, entrada);
    linha[strlen(linha) - 1] = 0; // mesma coisa: tirar o '\n'
    printf("Ordem: \"%s\"\n", linha);
    // se nao era 'cod' classifica por nome do aluno
    if (linha[0] != 'c') criterio = 1;

    // antes de sair mostra as turmas
    printf("Turmas: \"%s\" e \"%s\"\n", turma[0], turma[1]);

    fclose(entrada);
    return 0;
};  // main()

void    exibeAluno(Aluno* a)
{
    //exibir nome da turma 
    printf("\nNome: %s\n", a->nome);
    printf("ID: %d\n", a->cod);
};

void    leAluno(Aluno* a) {
    printf("Digite o nome:\n");
    scanf("%s", a->nome);
    printf("Digite o ID:\n");
    scanf("%d", &a->cod);
};

// fim