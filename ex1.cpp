#include <stdio.h>  
#include <stdlib.h> 
#include <string.h> 


typedef struct { //definicao de struct para representar os dados do estudante
    char nomeCompleto[100]; 
    float notaExercicio;    
    float notaProva1;      
    float notaProva2;
} Estudante; //nome da struct 

float calcularMediaFinal(Estudante dadosEstudante) {
    float mediaPonderadaProvas = (dadosEstudante.notaProva1 * 0.4F) + (dadosEstudante.notaProva2 * 0.6F);
    float mediaFinalCalculada = (mediaPonderadaProvas * 0.8F) + (dadosEstudante.notaExercicio * 0.2F);
    return mediaFinalCalculada; //valor da media final 
}

int main() {
    float mediaObtida;

    Estudante estudanteA = {"Alicia Moraes", 10.0F, 4.75F, 6.0F};

    mediaObtida = calcularMediaFinal(estudanteA);

    printf("A media final do estudante %s e: %.2f\n", estudanteA.nomeCompleto, mediaObtida);

    getchar();
    return 0;
}