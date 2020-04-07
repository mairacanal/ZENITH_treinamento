#include <stdio.h>
#include <stdlib.h>

// --------------------- PROTÓTIPOS -------------------
int divisao (int n[3], double* res);
// --------------------- FIM DOS PROTÓTIPOS -----------


// ------------------ MAIN FUNCTION -------------------
int main (){
    int n[3];
    double res[2];
    double* ptr;
    ptr = res;

    scanf("%d %d %d", &n[0], &n[1], &n[2]);
   
    if (divisao(n, res) == -1){
        printf("ERRO");
    }
    else{
        divisao(n, res);
        printf("%.3lf %.3lf", res[0], res[1]);
    }
    
    return 0;
}
// ------------------ FIM FUNCTION --------------------


// ------------------ FUNÇÕES AUX ---------------------
int divisao (int n[3], double* res){
    if (n[2] == 0) return (-1);
    else{
        *res = (double) n[0]/n[2];
        res++;
        *res = (double) n[1]/n[2];
        return 0;
    }
}