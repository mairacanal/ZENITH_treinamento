#ifndef FUNCOESFINAL_H
#include FUNCOESFINAL_H

#include <stdio.h>
#include <math.h>

#ifdef __cplusplus
extern "C" {
#endif

//SOMA
//type soma (type)(int N, type vector[])
#define declare_soma(T)\
T soma (T)(int N, T vector[]);

#define define_soma(T)\
T soma (T)(int N, T vector[]){\
    T res_soma = 0;\
    for (int i = 0; i < N; i++) res_soma = res_soma + vector[i];\
    return (res_soma);\
}

declare_soma(int);
declare_soma(double);
declare_soma(float);
//---------------------------------------

//MÉDIA
//type media (type)(int N, type vector[])
#define declare_media(T)\
T media (T)(int N, T vector[]);

#define define_media(T)\
T media (T)(int N, T vector[]){\
    T res_soma = 0;\
    for (int i = 0; i < N; i++) res_soma = res_soma + vector[i];\
    T res_med;\
    res_med = (T) res_soma/N;\
    return (res_med);\
}

declare_media(int);
declare_media(double);
declare_media(float);
//---------------------------------------

//DESVIO PADRÃO
//type desvio_padrao (type)(int N, T vector[])
#define declare_desvp(T)\
T desvio_padrao (T)(int N, T vector[]);

#define define_desvp(T)\
T desvio_padrao (T)(int N, T vector[]){\
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

declare_desvp(int);
declare_desvp(float);
declare_desvp(double);
//----------------------------------------

//DIVISÃO
//int divisao (int n[3], T* res)
#define declare_divisao(T)\
int divisão (T)(int n[3], T* res);

#define define_divisao(T)\
int divisão (T)(int n[3], T* res){\
    if (n[2] == 0) return (-1);\
    else{\
        *res = (T) n[0]/n[2];\
        res++;\
        *res = (T) n[1]/n[2];\
        return 0;\
    }\
}

declare_divisao(int);
declare_divisao(float);
declare_divisao(double);
//----------------------------------------


#ifdef __cplusplus
}
#endif
#endif
