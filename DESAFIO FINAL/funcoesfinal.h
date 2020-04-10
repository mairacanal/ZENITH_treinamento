#ifndef FUNCOESFINAL_H
#include FUNCOESFINAL_H

#include <stdio.h>
#include <math.h>

#ifdef __cplusplus
extern "C" {
#endif

//SOMA
//type soma (type)(int N, type vector[])
#define soma(T) soma_##T

#define declare_soma(T)\
T soma(T)(int N, T vector[]);

declare_soma(int);
declare_soma(double);
declare_soma(float);
//---------------------------------------

//MÉDIA
//type media (type)(int N, type vector[])
#define media(T) media_##T

#define declare_media(T)\
T media(T)(int N, T vector[]);

declare_media(int);
declare_media(double);
declare_media(float);
//---------------------------------------

//DESVIO PADRÃO
//type desvio_padrao (type)(int N, T vector[])
#define desvio_padrao(T) desvio_padrao_##T

#define declare_desvio_padrao(T)\
T desvio_padrao(T)(int N, T vector[]);

declare_desvio_padrao(int);
declare_desvio_padrao(float);
declare_desvio_padrao(double);
//----------------------------------------

//DIVISÃO
//int divisao (int n[3], T* res)
#define divisao(T) divisao_##T

#define declare_divisao(T)\
int divisão(T)(int n[3], T* res);

declare_divisao(int);
declare_divisao(float);
declare_divisao(double);
//----------------------------------------


#ifdef __cplusplus
}
#endif
#endif
