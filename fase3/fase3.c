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
    Aluno   alunos[200];   // os alunos
    int     cod;
    int     criterio = 0;   // zero = cod nao zero classifica por nome
    FILE* entrada = fopen("turmas.txt", "r");
    char    linha[40];
    int     N = 0;
    char    nome[20];
    int     n_alunos = 0;
    char    turma[2][20]; // as turmas

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
        alunos[n_alunos].cod = cod;
        strcpy(alunos[n_alunos].nome, nome);
        alunos[n_alunos].turma = 0; // sem frescura. sao so 2
        n_alunos += 1;
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
        alunos[n_alunos].cod = cod;
        strcpy(alunos[n_alunos].nome, nome);
        alunos[n_alunos].turma = 1; // sem frescura. sao so 2
        n_alunos += 1;
    };  // for()

    linha[0] = fgetc(entrada); // le o '\n' da ultima linha da turma 2
    fgets(linha, 5, entrada);
    linha[strlen(linha) - 1] = 0; // mesma coisa: tirar o '\n'
    printf("Ordem: \"%s\"\n", linha);
    // se nao era 'cod' classifica por nome do aluno
    if (linha[0] != 'c') criterio = 1;

    // antes de sair mostra as turmas
    printf("Turmas: \"%s\" e \"%s\" Alunos: %d\n",
        turma[0], turma[1], n_alunos);

    //  final: mostra os alunos
    printf("\nOs alunos\n\n");
    for (int i = 0; i < n_alunos; i += 1)
    {
        printf("%3d: %6d, %15s, %s\n",
            i, alunos[i].cod, alunos[i].nome,
            turma[alunos[i].turma]);
    };  // for()

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