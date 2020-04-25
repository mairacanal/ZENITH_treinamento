/*
Paint no Terminal

Desenvolvido por Maíra Canal
ZENITH - EESC/USP - 2020

*/

#include <stdio.h>
#include <stdlib.h>                   //Biblioteca para alocação dinâmica
#include <string.h>                   //Biblioteca para lidar com as strings

#define NUM_P_5 5
#define NUM_P_4 4

/*
O usuário tem acesso a 6 funções para manipular a sua imagem:
CREATE <width> <height>: permite a manipulação de uma imagem com tais dimensões
EXPORT <name>: salva a imagem no diretório presente com o nome "name"
LINE <x1> <y1> <x2> <y2> <color>: cria-se uma linha entre os pixels de coordenada (x1, y1) e (x2, y2) de cor "color"
CIRCLE <x> <y> <radius> <color>: cria-se um círculo de raio "radius" e centro (x, y) com cor "color"
DISK <x> <y> <radius> <color>: cria-se um disco de raio "radius" e centro (x, y) com cor "color"
RECT <x> <y> <width> <heigth> <color>: cria -se um retângulo centrado em (x, y), com as dimensões mencionadas e cor "color"
*/


// PRÓTOTIPOS
int** create (int* dimensoes);                                        //Cria a matriz responsável pela imagem PGM e aloca a matriz 
void export(int** imagem, int* dimensoes);                            //Cria e salva o arquivo PGM
void line (int** imagem, int* dimensoes);                             //Cria a linha e a posiciona na matriz
void circle (int** imagem, int* dimensoes);                           //Cria o círculo e o posiciona na matriz
void disk (int** imagem, int* dimensoes);                             //Cria o disco e o posiciona na matriz
void rect (int** imagem, int* dimensoes);                             //Cria o retângulo e o posiciona na matriz
// FIM DOS PRÓTOTIPOS

// MAIN FUNCTION

int main (){
    char comando[50];                          // Recebe o comando digitado pelo usuário
    int **imagem = NULL;                       // Recebe a matriz da imagem 
    int dimensoes[2] = {0, 0};                 // Recebe as dimensões da imagem
    

    // Loop do Menu Principal até que o comando seja "Export"
    while (comando[0] != 'E' || comando[1] != 'X' || comando[2] != 'P' || comando[3] != 'O' || comando[4] != 'R' || comando[5] != 'T'){
        scanf("%s", comando);
        for (int i = 0; i <= strlen (comando); i++) comando[i] = toupper(comando[i]);          // Eleva todos os caracteres do comando para letra maiúscula, para que seja possível receber os comandos com letra maiúscula ou minúscula

        // Atribui-se a cada comando uma função auxiliar

        if (comando[0] == 'C' && comando[1] == 'R' && comando[2] == 'E' && comando[3] == 'A' && comando[4] == 'T' && comando[5] == 'E'){ 
            imagem = create (dimensoes);
        }
        else if (comando[0] == 'E' && comando[1] == 'X' && comando[2] == 'P' && comando[3] == 'O' && comando[4] == 'R' && comando[5] == 'T'){ 
            export (imagem, dimensoes);
        }
        else if (comando[0] == 'L' && comando[1] == 'I' && comando[2] == 'N' && comando[3] == 'E'){ 
            line (imagem, dimensoes);
        }
        else if (comando[0] == 'C' && comando[1] == 'I' && comando[2] == 'R' && comando[3] == 'C' && comando[4] == 'L' && comando[5] == 'E'){ 
            circle (imagem, dimensoes);
        }
        else if (comando[0] == 'D' && comando[1] == 'I' && comando[2] == 'S' && comando[3] == 'K'){ 
            disk (imagem, dimensoes);
        }
        else if (comando[0] == 'R' && comando[1] == 'E' && comando[2] == 'C' && comando[3] == 'T'){ 
            rect (imagem, dimensoes);
        }
        else printf("ERRO! Opcao invalida. Tente novamente.\n");
    }
    return 0;
}
// END MAIN

// AUX FUNCTIONS

// CREATE <width> <height>
int** create (int* dimensoes){
    scanf("%d %d", &dimensoes[0], &dimensoes[1]);
    // Entende-se que width é o comprimento da imagem (COLUNAS) e height é a altura da imagem (LINHAS)
    // Comprimento (width) = COLUNAS = dimensoes[0]
    // Altura (height) = LINHAS = dimensoes[1]
    if (dimensoes[0] < 1 || dimensoes[1] < 1) printf("ERRO! Parametro invalido.\n");       // Impede que o usuário crie uma imagem com dimensões negativas

    else{                                      // Alocação dinâmica da matriz que hospeda a imagem
        int** imagem = (int **) calloc (dimensoes[1], sizeof(int *));
        for (int i = 0; i < dimensoes[1]; i++){
            imagem[i] = (int *) calloc (dimensoes[0], sizeof(int));
        }
        if (imagem == NULL) printf("ERRO! Memória insuficiente.\n");
        else return imagem;                    // Retorna a matriz imagem
    }
}

// Tem um erro: tem que achar o maior de cada linha e fazer o espaçamento
// EXPORT <name>
void export (int** imagem, int* dimensoes){
    char name[15];
    scanf("%s", name);
    strcat (name, ".pgm");
    FILE* arquivo = fopen (name, "w");
    if (arquivo != NULL){
        fprintf(arquivo, "P2\n");
        fprintf(arquivo, "%d %d\n", dimensoes[0], dimensoes[1]);
        fprintf(arquivo, "255\n");

        for (int j = 0; j < dimensoes[0]; j++){
            for (int i = 0; i < dimensoes[1]; i++){
                if (j == (dimensoes[0] - 1)) fprintf(arquivo, "%d\n", imagem [i][j]);
                else {
                    fprintf(arquivo, "%d ", imagem[i][j]);
                }
            }
        }
        fclose(arquivo);
    }
    else printf("ERRO na criação do arquivo.");
    for (int i = 0; i < dimensoes[1]; i++) free(imagem[i]);
    free(imagem);
}

// LINE <x1> <y1> <x2> <y2> <color>
// Utilização do algoritmo de reta "Midpoint algoritm"
void line (int** imagem, int* dimensoes){
    int parametro[5];

    // X1 = parametro[0]
    // Y1 = parametro[1]
    // X2 = parametro[2]
    // Y2 = parametro[3]
    // Cor = parametro[4]

    for (int i = 0; i < NUM_P_5; i++) scanf("%d", &parametro[i]);          //Recebe os 5 parâmetros
    
    if (parametro[0] < 0 || parametro[1] < 0 || parametro[2] < 0 || parametro[3] < 0 || parametro[4] < 0 || parametro[0] >= dimensoes[0] || parametro[2] >= dimensoes[0] || parametro[1] >= dimensoes[1] || parametro[3] >= dimensoes[1]) {
        printf ("ERRO! Parametros invalidos.\n");                // Averigua se algum dos parâmetros inserido pelo usuario é inválido
    }
    else {
        int x1, x2, y1, y2;
        if (parametro[0] > parametro[2]) {                       // Para a utilização do Midpoint Algoritm, é necessário determinar qual x é maior        
            x1 = parametro[2];                                   // Para tanto, determina-se o maior x e atribui o valor do maior x à x2
            y1 = parametro[3]; 
            x2 = parametro[0];
            y2 = parametro[1];
        }
        else{
            x1 = parametro[0];
            y1 = parametro[1];
            x2 = parametro[2];
            y2 = parametro[3];
        }
        /* Sabe-se que o Midpoint Algoritm não funciona para retas em que x1 = x2 ou que y1 = y2, logo, 
        foram criadas tais condição para possibilitar a criação de retângulos de altura 1 ou de retângulos
        de comprimento 1, por meio da função LINE */
        if (x1 == x2){                                     
            for (int j = y1; j <= y2; j++) imagem [j][x1] = parametro[4];
        }
        else if (y1 == y2){
            for (int i = x1; i <= x2; i++) imagem[y1][i] = parametro[4];
        }
        /* Utilização do "Midpoint Algoritm", isto é, determinação da variação dos pontos x (dx) e pontos y (dy)
        e, por meio dessa variação, determinação se a reta corta acima ou abaixo da metade do pixel, de forma a 
        possibilitar a criação de retas com pixels. */
        else{
            int dx = (x2 - x1);
            int dy = (y2 - y1);
            int d = (2*dy) - dx;
            int x = x1;
            int y = y1;
            imagem[y][x] = parametro[4];
            for (x = x1; x <= x2; x++){
                if (d <= 0){
                    d = d + (2*dy);
                }
                else{
                    d = d + 2*(dy - dx);
                    y++;
                }
                imagem[y][x] = parametro[4];
            }
        }
    }
}

// CIRCLE <x> <y> <radius> <color>
// Utilização do algoritmo de circunferência "Midpoint algoritm"
void circle (int** imagem,  int* dimensoes){
    int parametro[4];

    // X = parametro[0]
    // Y = parametro[1]
    // Raio = parametro[2]
    // Cor = parametro[3]

    for (int i = 0; i < NUM_P_4; i++) scanf("%d", &parametro[i]);
    // Verifica se algum dos parêmetros inseridos pelo usuário 
    if (parametro[0] < 0 || parametro[1] < 0 || parametro[2] < 0 || parametro[3] < 0 || parametro[4] < 0) printf ("ERRO! Parametros invalidos.\n");
    else if ((parametro[0] - parametro[2]) < 0 || (parametro[1] - parametro[2]) < 0 || (parametro[0] + parametro[2]) > dimensoes[0] || (parametro[1] + parametro[2]) > dimensoes[1]){
        printf("ERRO! Impossivel imprimir essa imagem!\n");
    }

    // Utiliza-se o segmentação do círculo em 8 partes para a construção da circuferência
    else {
        int cx = parametro[0];
        int cy = parametro[1];
        int r = parametro[2];
        int d = (1 - r);
        int x = 0;
        int y = r;
        imagem[cy + y][cx + x] = parametro[3];
        imagem[cy - y][cx - x] = parametro[3];
        imagem[cy - y][cx + x] = parametro[3];
        imagem[cy + y][cx - x] = parametro[3];
        imagem[cy + x][cx + y] = parametro[3];
        imagem[cy - x][cx - y] = parametro[3];
        imagem[cy - x][cx + y] = parametro[3];
        imagem[cy + x][cx - y] = parametro[3];
        for (x = 0; x < y; x++){
            if (d < 0){
                d = d + (2*x) + 3;
            }
            else {
                d = d + (2*(x - y)) + 4;   //Pequena modificação no algoritmo clássico, visando arrendondar mais a circuferência
                y--;
            }
            imagem[cy + y][cx + x] = parametro[3];
            imagem[cy - y][cx + x] = parametro[3];
            imagem[cy + y][cx - x] = parametro[3];
            imagem[cy - y][cx - x] = parametro[3];
            imagem[cy + x][cx + y] = parametro[3];
            imagem[cy - x][cx - y] = parametro[3];
            imagem[cy - x][cx + y] = parametro[3];
            imagem[cy + x][cx - y] = parametro[3];
        }
    }
}

// DISK <x> <y> <radius> <color>
// Utilização do algoritmo de circunferência "Midpoint algoritm"
void disk (int** imagem, int* dimensoes){
    int parametro[4];

    // X = parametro[0]
    // Y = parametro[1]
    // Raio = parametro[2]
    // Cor = parametro[3]

    for (int i = 0; i < NUM_P_4; i++) scanf("%d", &parametro[i]);
    // Verifica se algum dos parêmetros inseridos pelo usuário 
    if (parametro[0] < 0 || parametro[1] < 0 || parametro[2] < 0 || parametro[3] < 0 || parametro[4] < 0) printf ("ERRO! Parametros invalidos.\n");
    else if ((parametro[0] - parametro[2]) < 0 || (parametro[1] - parametro[2]) < 0 || (parametro[0] + parametro[2]) > dimensoes[0] || (parametro[1] + parametro[2]) > dimensoes[1]){
        printf("ERRO! Impossivel imprimir essa imagem!\n");
    }

    // Mesmo princípio da função circle, mas dessa vez o interior da circunferência é preenchido por meio de laços for
    else {
        int cx = parametro[0];
        int cy = parametro[1];
        int r = parametro[2];
        int d = (1 - r);
        int x = 0;
        int y = r;
        for (int j = (cx - x); j <= (cx + x); j++) {
            imagem[cy + y][j] = parametro[3];
            imagem[cy - y][j] = parametro[3];
        }
        for (int i = (cy - y); i <= (cy + y); i++){
            imagem[i][cx + x] = parametro[3];
            imagem[i][cx - x] = parametro[3];
        }
        for (int j = (cx - y); j <= (cx + y); j++) {
            imagem[cy + x][j] = parametro[3];
            imagem[cy - x][j] = parametro[3];
        }
        for (int i = (cy - x); i <= (cy + x); i++){
            imagem[i][cx + y] = parametro[3];
            imagem[i][cx - y] = parametro[3];
        }
        for (x = 0; x < y; x++){
            if (d < 0){
                d = d + (2*x) + 3;
            }
            else {
                d = d + (2*(x - y)) + 4;   //Pequena modificação no algoritmo clássico, visando arrendondar mais a circuferência
                y--;
            }
            for (int j = (cx - x); j <= (cx + x); j++) {
                imagem[cy + y][j] = parametro[3];
                imagem[cy - y][j] = parametro[3];
            }
            for (int i = (cy - y); i <= (cy + y); i++){
                imagem[i][cx + x] = parametro[3];
                imagem[i][cx - x] = parametro[3];
            }
            for (int j = (cx - y); j <= (cx + y); j++) {
                imagem[cy + x][j] = parametro[3];
                imagem[cy - x][j] = parametro[3];
            }
            for (int i = (cy - x); i <= (cy + x); i++){
                imagem[i][cx + y] = parametro[3];
                imagem[i][cx - y] = parametro[3];
            }
        }
    }
}

// RECT <x> <y> <width> <heigth> <color>
void rect (int** imagem, int* dimensoes){
    int parametro[5];

    // X = parametro[0]
    // Y = parametro[1]
    // Comprimento = parametro[2]
    // Altura = parametro[3]
    // Cor = parametro[4]

    for (int i = 0; i < NUM_P_5; i++) scanf("%d", &parametro[i]);
    // Verifica se algum dos parêmetros inseridos pelo usuário 
    if (parametro[0] < 0 || parametro[1] < 0 || parametro[2] < 0 || parametro[3] < 0 || parametro[4] < 0) printf ("ERRO! Parametros invalidos.\n");

    // Nesse caso, são criados laços de condição para verificar a paridade da altura e do comprimento.
    // metade_alt é uma variável int utilizada para saber "o quanto deve-se acrescentar" acima e abaixo do bloco principal (x, y)
    // metade_comp é uma variável int utilizada para saber "o quanto deve-se acrescentar" a direita e a esquerda do bloco principal (x, y)
    else{
        if ((parametro[3] % 2) != 0){                                                                  //Altura impar 
            int metade_alt;
            if (parametro[3] == 1) metade_alt = 0;
            else metade_alt = (parametro[3] - 1)/2;

            if ((parametro[1] - metade_alt) < 0 || (parametro[1] + metade_alt) > dimensoes[1]) {
                printf("ERRO! Impossivel imprimir essa imagem!\n");
            }
            else{
                for (int i = (parametro[1] - metade_alt); i <= (parametro[1] + metade_alt); i++){
                    if ((parametro[2] % 2) != 0) {                                                     //Comprimento impar
                        int metade_comp;
                        if (parametro[2] == 1) metade_comp = 0;
                        else metade_comp = (parametro[2] - 1)/2;
                        if ((parametro[0] - metade_comp) < 0 || (parametro[0] + metade_comp) > dimensoes[0]){
                            printf("ERRO! Impossivel imprimir essa imagem!\n");
                        }
                        else {
                            for (int j = (parametro[0] - metade_comp); j <= (parametro[0] + metade_comp); j++) imagem[i][j] = parametro[4];
                        }
                    }
                    else {                                                                             //Comprimento par
                        int metade_comp = (parametro[2] - 2)/2;
                        if ((parametro[0] - metade_comp) < 0 || (parametro[0] + metade_comp + 1) > dimensoes[0]){
                            printf("ERRO! Impossivel imprimir essa imagem!\n");
                        }
                        else {
                            for (int j = (parametro[0] - metade_comp); j <= (parametro[0] + metade_comp + 1); j++) imagem[i][j] = parametro[4];
                        }
                    }
                } 
            }    
        }

        else {                                                                                     //Altura par
            int metade_alt = (parametro[3] - 2)/2;
            if ((parametro[1] - metade_alt) < 0 || (parametro[1] + metade_alt + 1) > dimensoes[1]) printf("ERRO! Impossivel imprimir essa imagem!\n");
            else{
                for (int i = (parametro[1] - metade_alt); i <= (parametro[1] + metade_alt + 1); i++){
                    if ((parametro[2] % 2) != 0) {                                                     //Comprimento impar
                        int metade_comp;
                        if (parametro[2] == 1) metade_comp = 0;
                        else metade_comp = (parametro[2] - 1)/2;
                        if ((parametro[0] - metade_comp) < 0 || (parametro[0] + metade_comp) > dimensoes[0]){
                            printf("ERRO! Impossivel imprimir essa imagem!\n");
                        }
                        else {
                            for (int j = (parametro[0] - metade_comp); j <= (parametro[0] + metade_comp); j++) imagem[i][j] = parametro[4];
                        }
                    }
                    else {                                                                             //Comprimento par
                        int metade_comp = (parametro[2] - 2)/2;
                        if ((parametro[0] - metade_comp) < 0 || (parametro[0] + metade_comp + 1) > dimensoes[0]) {
                            printf("ERRO! Impossivel imprimir essa imagem!\n");
                        }
                        else {
                            for (int j = (parametro[0] - metade_comp); j <= (parametro[0] + metade_comp + 1); j++) imagem[i][j] = parametro[4];
                        }
                    }
                }  
            }
        }
    }
}

// END AUX
