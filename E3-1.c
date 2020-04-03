#include <stdio.h>
#include <stdlib.h>
#define COLUNAS 3

// --------------------- PROTÓTIPOS -------------------
int num_linhas_arquivo ();
void ler_arquivo (int N, int vetor[N][COLUNAS]);
void gerar_arquivo (int N, float soma[], float med[], float desv[]);
// --------------------- FIM DOS PROTÓTIPOS -----------


// ------------------ MAIN FUNCTION -------------------
int main (){
    int N, i;
    N = num_linhas_arquivo();
    int vetor[N][COLUNAS];
    float soma[N];
    float med[N];
    float desv[N];
    float soma_dev[N];
    ler_arquivo(N, vetor);
    for (i = 0; i < N; i++) {
        soma[i] = (vetor[i][0] + vetor[i][1] + vetor[i][2]);
        med [i] = ((float) soma[i]/3);
        soma_dev[i] = (pow((med[i] - vetor[i][0]), 2) + pow((med[i] - vetor[i][1]), 2) + pow((med[i] - vetor[i][2]), 2));
        desv[i] = sqrt(((float)soma_dev[i]/3));
    }
    gerar_arquivo(N, soma, med, desv);
    return 0;
}
// ------------------ FIM FUNCTION --------------------


// ------------------ FUNÇÕES AUX ---------------------
int num_linhas_arquivo (){
    int N;
    char ch;
    N = 0;
    FILE* arquivo = fopen("dados2.csv", "r");
    while (!feof(arquivo)) {
        ch = fgetc(arquivo);
        if (ch == '\n') N++;
    }
    fclose(arquivo);
    return(N); 
}
void ler_arquivo (int N, int vetor[N][COLUNAS]){
    int i;
    FILE* arquivo = fopen("dados2.csv", "r");
    if (arquivo == NULL){
        printf("Erro ao abrir o arquivo.");
        exit (0);
    }
    else{
        for (i = 0; i < N; i++) fscanf (arquivo, "%d, %d, %d\n", &vetor[i][0], &vetor[i][1], &vetor[i][2]);
        fclose (arquivo);
    }
}
void gerar_arquivo (int N, float soma[], float med[], float desv[]){
    int i;
    FILE* arquivo = fopen("resultados2.csv", "w");
    for (i = 0; i < N; i++){
        fprintf (arquivo, "%.0f, %.3f, %.3f\n", soma[i], med[i], desv[i]);
    }
    fclose (arquivo);
}
