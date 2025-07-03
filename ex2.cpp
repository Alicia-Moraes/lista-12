#include <stdio.h>   
#include <stdlib.h>  
#include <string.h>  

#define CAPACIDADE_MAXIMA_ESTUDANTES 30

typedef struct {
    char nomeCompleto[100];
    float notaExercicios;
    float notaProva1;
    float notaProva2;
} Estudante;


float calcularMediaFinal(Estudante dadosEstudante) {
    float mediaProvasPonderada = (dadosEstudante.notaProva1 * 0.4F) + (dadosEstudante.notaProva2 * 0.6F);
    float mediaFinalCalculada = (mediaProvasPonderada * 0.8F) + (dadosEstudante.notaExercicios * 0.2F);
    return mediaFinalCalculada;
}


typedef struct {
    Estudante listaDeEstudantes[CAPACIDADE_MAXIMA_ESTUDANTES]; 
    int numeroDeEstudantes;                                    
} Turma;


void imprimirMediasDaTurma(Turma turma) {
    printf("Medias da Turma: \n");
    for (int i = 0; i < turma.numeroDeEstudantes; i++) {
        Estudante estudante1 = turma.listaDeEstudantes[i];
        float mediaEstudante = calcularMediaFinal(estudante1);
        printf("Estudante: %s = Media Final: %.2f\n", estudante1.nomeCompleto, mediaEstudante);
    }
    printf("\n");
}


int main() {
    Turma turmaDeProgramacao;
    turmaDeProgramacao.numeroDeEstudantes = 0;

    strcpy(turmaDeProgramacao.listaDeEstudantes[0].nomeCompleto, "Alicia");
    turmaDeProgramacao.listaDeEstudantes[0].notaExercicios = 10.0F;
    turmaDeProgramacao.listaDeEstudantes[0].notaProva2 = 4.75F;
    turmaDeProgramacao.listaDeEstudantes[0].notaProva1= 6.0F;
    turmaDeProgramacao.numeroDeEstudantes++;

    strcpy(turmaDeProgramacao.listaDeEstudantes[1].nomeCompleto, "Maria");
    turmaDeProgramacao.listaDeEstudantes[1].notaExercicios = 5.7F;
    turmaDeProgramacao.listaDeEstudantes[1].notaProva1 = 9.0F;
    turmaDeProgramacao.listaDeEstudantes[1].notaProva1 = 2.0F;
    turmaDeProgramacao.numeroDeEstudantes++;

    strcpy(turmaDeProgramacao.listaDeEstudantes[2].nomeCompleto, "Vinicius");
    turmaDeProgramacao.listaDeEstudantes[2].notaExercicios = 4.0F;
    turmaDeProgramacao.listaDeEstudantes[2].notaProva1 = 6.0F;
    turmaDeProgramacao.listaDeEstudantes[2].notaProva2 = 6.0F;
    turmaDeProgramacao.numeroDeEstudantes++;

    imprimirMediasDaTurma(turmaDeProgramacao);

    getchar();
    return 0;
}
