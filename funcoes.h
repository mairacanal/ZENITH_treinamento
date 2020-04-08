#ifndef FUNCOES_H
#include FUNCOES_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define COLUNAS 3

//OPERAÇÕES BÁSICAS

int soma (int N, int vector[]);
//Soma de um vetor com N elementos

float med (int vector[], int N);
//Média de um vetor com N elementos

float desviopadrao (int N, int vector[], float res_med);
//Desvio padrão de um vetor com N elementos

int divisao (int n[3], double* res);
//Divisão de n[0]/n[2] e de n[1]/n[2]


//ARQUIVOS

int num_linhas_arquivo (FILE* arquivo);
//Retorna o número de linhas de um arquivo

void ler_arquivo (FILE* arquivo, int N, int vetor[N][COLUNAS]);
//Lê um arquivo de N linhas e 3 colunas e coloca os dados inteiros no vetor[N][COLUNAS]

void gerar_arquivo (FILE* arquivo, int N, float soma[], float med[], float desv[]);
//Gera um arquivo de N linhas e 3 colunas, sendo os vetores (soma, med, desv) posionados lado a lado em cada linha

#endif
