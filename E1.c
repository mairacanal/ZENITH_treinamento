#include <stdio.h>
#include <math.h>

int main (){
    int a1, a2, a3, soma;
    float med, desv;
    scanf("%d %d %d", &a1, &a2, &a3);
    soma = a1 + a2 + a3;
    med = (float) soma/3;
    desv = sqrt ((pow ((a1 - med), 2) + pow ((a2 - med), 2) + pow ((a3 - med), 2))/3);
    printf("Soma: %d\nMedia: %.3f\nDesvio padrao: %.3f\n", soma, med, desv);
    return 0;

}