#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#define NUM 3

// --------------------- PROTÓTIPOS -------------------
void ler_arquivo (uint8_t num[NUM]);
void gerar_arquivo(int soma, double med, double desv);
// --------------------- FIM DOS PROTÓTIPOS -----------


// ------------------ MAIN FUNCTION -------------------
int main(){
    uint8_t num[NUM];
    int i;
    int soma;
    double med, desv;
    soma = 0;
    ler_arquivo (num);
    for (i = 0; i < NUM; i++){
        soma = soma + num [i];
    }
    med = (double) soma/3;
    desv = sqrt ((pow((med - num[0]), 2) + pow((med - num[1]), 2) + pow((med - num[2]), 2))/3);
    gerar_arquivo(soma, med, desv);

    return 0;
}
// ------------------ FIM FUNCTION --------------------


// ------------------ FUNÇÕES AUX ---------------------
void ler_arquivo (uint8_t num[NUM]){
    FILE *arquivo = fopen("dados3.bin", "rb");
    if (arquivo == NULL){
        printf("Erro ao abrir o arquivo.");
        exit (0);
    }
    else{
        fread(num, sizeof(uint8_t), 3, arquivo);
    }
    fclose(arquivo);
}
void gerar_arquivo(int soma, double med, double desv){
    FILE* arquivo = fopen("resultados3.bin", "wb");
    if (arquivo == NULL){
        printf("Erro ao abrir o arquivo.");
        exit (0);
    }
    else{
        fwrite(&soma, sizeof(int), 1, arquivo);
        fwrite(&med, sizeof(double), 1, arquivo);
        fwrite(&desv, sizeof(double), 1, arquivo);
    }
    fclose(arquivo);
}

