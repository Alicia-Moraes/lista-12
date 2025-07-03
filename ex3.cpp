#include <stdio.h>  
#include <stdlib.h>


typedef struct NoMatriz {
    int valorElemento;
    int indiceLinha;
    int indiceColuna;
    struct NoMatriz* proximoNo; 
} NoMatriz;

typedef struct { //estrutura principal da matriz
    NoMatriz* inicioListaElementos;
    int numeroTotalLinhas;
    int numeroTotalColunas;
} Matriz;


void inicializarMatriz(Matriz* matriz, int linhas, int colunas) {
    matriz->inicioListaElementos = NULL; 
    matriz->numeroTotalLinhas = linhas;
    matriz->numeroTotalColunas = colunas;
}

void inserirValor(Matriz* matriz, int linha, int coluna, int valor) {
    if (valor == 0) {
        return; 
    }

    NoMatriz* novoNo = (NoMatriz*) malloc(sizeof(NoMatriz));
    if (novoNo == NULL) {
        printf("Erro de alocacao.\n");
        return;
    }
    novoNo->indiceLinha = linha;
    novoNo->indiceColuna = coluna;
    novoNo->valorElemento = valor;


    novoNo->proximoNo = matriz->inicioListaElementos;
    matriz->inicioListaElementos = novoNo;
}

void imprimirMatriz(Matriz matriz) {
    printf("Matriz %dx%d:\n", matriz.numeroTotalLinhas, matriz.numeroTotalColunas);
    for (int i = 0; i < matriz.numeroTotalLinhas; i++) {
        for (int j = 0; j < matriz.numeroTotalColunas; j++) {
            NoMatriz* noAtual = matriz.inicioListaElementos;
            int valorEncontrado = 0;

           
            while (noAtual != NULL) {
                if (noAtual->indiceLinha == i && noAtual->indiceColuna == j) {
                    printf("%d ", noAtual->valorElemento);
                    valorEncontrado = 1;
                    break; 
                }
                noAtual = noAtual->proximoNo;
            }
         
            if (!valorEncontrado) {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

void liberarMatriz(Matriz* matriz) {
    NoMatriz* noAtual = matriz->inicioListaElementos;
    NoMatriz* noTemporario;

    while (noAtual != NULL) {
        noTemporario = noAtual;
        noAtual = noAtual->proximoNo;
        free(noTemporario);       
    }
    matriz->inicioListaElementos = NULL;
}


int main() {
    Matriz minhaMatriz;

    inicializarMatriz(&minhaMatriz, 3, 3); 

    inserirValor(&minhaMatriz, 1, 2, 3);
    inserirValor(&minhaMatriz, 4, 5, 6);
    inserirValor(&minhaMatriz, 7, 8, 9);
    inserirValor(&minhaMatriz, 10, 11, 12);

    imprimirMatriz(minhaMatriz);

    liberarMatriz(&minhaMatriz);

    getchar();
    return 0;
}
