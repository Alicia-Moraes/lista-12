#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int valorInteiro;
} Decimal;

Decimal criarDecimal(double valorReal) {
    Decimal decimal;
    decimal.valorInteiro = (int)(valorReal * 10000);
    return decimal;
}

void imprimirDecimal(Decimal decimal) { // imprime o decimal com 4 casas decimais
    printf("%d.%04d\n", 
           decimal.valorInteiro / 10000, decimal.valorInteiro % 10000);     
}

Decimal somarDecimais(Decimal a, Decimal b) {
    Decimal resultado;
    resultado.valorInteiro = a.valorInteiro + b.valorInteiro;
    return resultado;
}

Decimal subtrairDecimais(Decimal a, Decimal b) {
    Decimal resultado;
    resultado.valorInteiro = a.valorInteiro - b.valorInteiro;
    return resultado;
}

int main() {

    Decimal precoProduto = criarDecimal(20.50); 
    Decimal desconto = criarDecimal(4.9999);       

    printf("Preco do Produto: ");
    imprimirDecimal(precoProduto);

    printf("Desconto: ");
    imprimirDecimal(desconto);

    Decimal totalComDesconto = somarDecimais(precoProduto, desconto);
    printf("Total soma: ");
    imprimirDecimal(totalComDesconto);

    Decimal totalFinal = subtrairDecimais(precoProduto, desconto);
    printf("Total com desconto: ");
    imprimirDecimal(totalFinal);

    getchar();
    return 0;
}
