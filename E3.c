#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define LINHAS 10
#define COLUNAS 3

// --------------------- PROTÓTIPOS -------------------
void ler_arquivo (int vetor[][COLUNAS]);
void gerar_arquivo (float soma[], float med[], float desv[]);

// --------------------- FIM DOS PROTÓTIPOS -----------

// ------------------ MAIN FUNCTION -------------------
int main (){
    int vetor[LINHAS][COLUNAS];
    int i;
    float soma[LINHAS];
    float med[LINHAS];
    float desv[LINHAS];
    float soma_dev[LINHAS];

    ler_arquivo(vetor);
    for (i = 0; i < LINHAS; i++) {
        soma[i] = (vetor[i][0] + vetor[i][1] + vetor[i][2]);
        med [i] = ((float) soma[i]/3);
        soma_dev[i] = (pow((med[i] - vetor[i][0]), 2) + pow((med[i] - vetor[i][1]), 2) + pow((med[i] - vetor[i][2]), 2));
        desv[i] = sqrt(((float)soma_dev[i]/3));
    }
    gerar_arquivo (soma, med, desv);

    return 0;
}

// ------------------ FIM FUNCTION --------------------

// ------------------ FUNÇÕES AUX ---------------------
void ler_arquivo (int vetor[][COLUNAS]){
    int i;
    FILE* arquivo = fopen("dados1.csv", "r");
    for (i = 0; i < LINHAS; i++) {
        fscanf (arquivo, "%d, %d, %d\n", &vetor[i][0], &vetor[i][1], &vetor[i][2]);
    }
    fclose (arquivo);
}
void gerar_arquivo (float soma[], float med[], float desv[]){
    int i;
    FILE* arquivo = fopen("resultados1.csv", "w");
    for (i = 0; i < LINHAS; i++){
        fprintf (arquivo, "%.0f, %.3f, %.3f\n", soma[i], med[i], desv[i]);
    }
    fclose (arquivo);
}
