#include <stdio.h>
#include <math.h>
#define N 5

int main(){
    int vector[N];
    int i;
    float med, somaes, desv, desv1,soma;
    soma = somaes = 0;
    for (i = 0; i < N; i++){
        scanf("%d", &vector[i]);
        soma = soma + vector[i]; 
    }
    med = (float) soma/N;
    for (i = 0; i < N; i++){
        somaes = somaes + ((vector[i] - med)*(vector[i] - med));
    }
    desv = sqrt((float)somaes/N);
    printf("%.0f\n%.3f\n%.3f\n", soma, med, desv);
    return 0;
}