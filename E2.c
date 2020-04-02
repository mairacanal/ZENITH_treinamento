#include <stdio.h>
#include <math.h>

/**************** PROTÓTIPOS **************/
int soma (int N, int vector[]);
float med (int res_soma, int N);
float devp (int N, int vector[], float res_med);
/****************** FIM *******************/

/*************** MAIN FUNCTION ************/
int main(void){
    int N, i, res_soma;
    float res_med, res_devp;
    printf("Numero de valores: ");
    scanf("%d", &N);
    int vector [N];
    for (i = 0; i < N; i++){
        scanf("%d", &vector[i]);
    }
    res_soma = soma(N, vector);
    res_med = med(res_soma, N);
    res_devp = devp (N, vector, res_med);
    printf("\nSoma = %d\nMedia = %.3f\nDesvio padrao = %.3f\n", res_soma, res_med, res_devp);
    return 0;
}
/************* FIM MAIN FUNCTION **********/

/*************** SUBFUNÇÕES ***************/
int soma (int N, int vector[]){
    int i, res_soma;
    res_soma = 0;
    for (i = 0; i < N; i++) res_soma = res_soma + vector[i];
    return (res_soma);
}

float med (int res_soma, int N){
    float res_med;
    res_med = (float) res_soma/N;
    return (res_med);
}

float devp (int N, int vector[], float res_med){
    int i;
    float soma_dev, res_devp;
    soma_dev = 0;
    for (i = 0; i < N; i++){
        soma_dev = soma_dev + ((vector[i] - res_med)*(vector[i] - res_med));
    }
    res_devp = sqrt((float) soma_dev/N);
    return (res_devp);
}
/*************** FIM SUBFUNÇÕES ***************/