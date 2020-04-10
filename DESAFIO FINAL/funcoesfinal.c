#include "funcoesfinal.h"

#define define_soma(T)\
T soma(T)(int N, T vector[]){\
    T res_soma = 0;\
    for (int i = 0; i < N; i++) res_soma = res_soma + vector[i];\
    return (res_soma);\
}
define_soma (int);
define_soma(float);
define_soma(double);


#define define_media(T)\
T media(T)(int N, T vector[]){\
    T res_soma = 0;\
    for (int i = 0; i < N; i++) res_soma = res_soma + vector[i];\
    T res_med;\
    res_med = (T) res_soma/N;\
    return (res_med);\
}
define_media(int);
define_media(float);
define_media(double);

#define define_desvio_padrao(T)\
T desvio_padrao(T)(int N, T vector[]){\
    T res_soma = 0;\
    for (int i = 0; i < N; i++) res_soma = res_soma + vector[i];\
    T res_med;\
    res_med = (T) res_soma/N;\
    T res_devp;\
    T soma_dev = 0;\
    for (int i = 0; i < N; i++) soma_dev = soma_dev + ((vector[i] - res_med)*(vector[i] - res_med));\
    res_devp = sqrt((float) soma_dev/N);\
    return (res_devp);\
}
define_desvio_padrao(int);
define_desvio_padrao(float);
define_desvio_padrao(double);


#define define_divisao(T)\
int divisão (T)(int n[3], T *res){\
    if (n[2] == 0) return (-1);\
    else{\
        *res = (T) n[0]/n[2];\
        res++;\
        *res = (T) n[1]/n[2];\
        return 0;\
    }\
}
define_divisao(int);
define_divisao(float);
define_divisao(double);
