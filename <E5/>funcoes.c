#include "funcoes.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define COLUNAS 3


//OPERAÇÕES BÁSICAS
int soma (int N, int vector[]){
    int i, res_soma;
    res_soma = 0;
    for (i = 0; i < N; i++) res_soma = res_soma + vector[i];
    return (res_soma);
}

float med (int vector[], int N){
    int i, res_soma;
    res_soma = 0;
    for (i = 0; i < N; i++) res_soma = res_soma + vector[i];
    float res_med;
    res_med = (float) res_soma/N;
    return (res_med);
}

float desviopadrao (int N, int vector[], float res_med){
    int i;
    float soma_dev, res_devp;
    soma_dev = 0;
    for (i = 0; i < N; i++){
        soma_dev = soma_dev + ((vector[i] - res_med)*(vector[i] - res_med));
    }
    res_devp = sqrt((float) soma_dev/N);
    return (res_devp);
}
int divisao (int n[3], double* res){
    if (n[2] == 0) return (-1);
    else{
        *res = (double) n[0]/n[2];
        res++;
        *res = (double) n[1]/n[2];
        return 0;
    }
}

//ARQUIVOS CSV
int num_linhas_arquivo (FILE* arquivo){
    int N;
    char ch;
    N = 0;
    while (!feof(arquivo)) {
        ch = fgetc(arquivo);
        if (ch == '\n') N++;
    }
    fclose(arquivo);
    return(N); 
}
void ler_arquivo (FILE* arquivo, int N, int vetor[N][COLUNAS]){
    int i;
    if (arquivo == NULL){
        printf("Erro ao abrir o arquivo.");
        exit (0);
    }
    else{
        for (i = 0; i < N; i++) fscanf (arquivo, "%d, %d, %d\n", &vetor[i][0], &vetor[i][1], &vetor[i][2]);
        fclose (arquivo);
    }
}
void gerar_arquivo (FILE* arquivo, int N, float soma[], float med[], float desv[]){
    int i;
    for (i = 0; i < N; i++){
        fprintf (arquivo, "%.0f, %.3f, %.3f\n", soma[i], med[i], desv[i]);
    }
    fclose (arquivo);
}
