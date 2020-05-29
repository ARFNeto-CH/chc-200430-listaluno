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

int		bubble_sort(Aluno[], int, int);
int     compara(int, int, int, Aluno[]);
void    exibeAluno(Aluno*);
void    leAluno(Aluno*);

void    le_uma_turma(FILE*, int*, Aluno[], char[]);
void    mostra_alunos(const int, const Aluno[], const char[][20], const char*);

int main(int argc, char** argv)
{
    Aluno   alunos[200];   // os alunos
    int     criterio = 0;   // zero = cod nao zero classifica por nome
    FILE*   entrada = fopen("turmas.txt", "r");
    char    linha[20];
    int     N = 0;
    int     n_alunos = 0;
    char    turma[2][20]; // as turmas

    turma[0][0] = 0; // avisa la
    le_uma_turma(entrada, &n_alunos, alunos, turma[0]);
    turma[1][0] = 1; // avisa la: turma 1
    le_uma_turma(entrada, &n_alunos, alunos, turma[1]);

    fgets(linha, 5, entrada);
    linha[strlen(linha) - 1] = 0; // mesma coisa: tirar o '\n'
    printf("Ordem: \"%s\"\n", linha);
    // se nao era 'cod' classifica por nome do aluno
    if (linha[0] != 'c') criterio = 1;

    mostra_alunos(n_alunos, alunos, turma, "\nOs alunos\n\n");
    // antes de classificar mostra as turmas
    printf("\nTurmas: \"%s\" e \"%s\" Total de %d alunos\n",
        turma[0], turma[1], n_alunos);
    // poe em ordem
    bubble_sort(alunos, n_alunos, criterio);
    //  mostra os alunos
    mostra_alunos(n_alunos, alunos, turma, "\nOs alunos na ordem\n\n");
    fclose(entrada);
    return 0;
};

int		bubble_sort(Aluno aluno[], int N, int criterio)
{
    int passo, elemento;
    Aluno temp;
    int n = 0;
    for (passo = 0; passo < N - 1; passo = passo + 1)
    {
        int mudou_algo = 0;	// se nao muda nada no passo ja terminou
        for (elemento = 0; elemento < (N - 1 - passo); elemento = elemento + 1)
        {
            n = compara(elemento, elemento + 1, criterio, aluno);
            if (n)
            {   // fora de ordem: inverte os caras
                temp = aluno[elemento];
                aluno[elemento] = aluno[elemento + 1];
                aluno[elemento + 1] = temp;
                mudou_algo = 1;
            }	// if
        }	// for
        if (mudou_algo == 0)
            return passo + 1;	// economizou uns passos
    }	// for
    return passo + 1;
};

int     compara(int primeiro, int segundo, int criterio, Aluno aluno[])
{
    int n = 0;
    // criterio 0 classifica pela ordem de codigo do aluno
    if (criterio == 0)
        return(aluno[primeiro].cod > aluno[segundo].cod);
    // criterio nao zero vai usar a ordem de nome
    return (strcmp(aluno[primeiro].nome, aluno[segundo].nome) > 0);
};  // compara()

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

void    le_uma_turma(FILE* entrada, int* n_alunos, Aluno alunos[], char turma[])
{
    // le uma turma
    // jeitinho: a turma vem no primeiro char de turma
    int n_turma = turma[0];
    char linha[20];
    fgets(turma, 20, entrada);
    turma[strlen(turma) - 1] = 0;
    // fgets() le o '\n' do fim da linha!
    fgets(linha, 5, entrada);
    linha[strlen(linha) - 1] = 0; // mesma coisa: tirar o '\n'
    printf("Turma \"%s\" com %s alunos \n", turma, linha);
    int N = atoi(linha); // precisamos de um int
    // agora le os alunos e grava no vetor
    for (int i = 0; i < N; i += 1)
    {
        fscanf(entrada, "%s%d",
            alunos[*n_alunos].nome,
            &alunos[*n_alunos].cod);
        alunos[*n_alunos].turma = n_turma; // sem frescura. sao so 2
        *n_alunos += 1;
    };  // for()
    linha[0] = fgetc(entrada); // le o '\n' da ultima linha da turma
    return;
};  // le_uma_turma()

void    mostra_alunos(
    const int n_alunos,
    const Aluno alunos[],
    const char turma[][20],
    const char* titulo)
{
    printf("%s", titulo);
    for (int i = 0; i < n_alunos; i += 1)
    {
        printf("%3d: %6d, %15s, %s\n",
            i, alunos[i].cod, alunos[i].nome,
            turma[alunos[i].turma]);
    };  // for()
    return;
}
