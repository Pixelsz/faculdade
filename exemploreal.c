#include <stdio.h>

int main()
{
    int qtd = 25;
    int preco_unidade = 10;
    int preco_total = qtd * preco_unidade;
    char moeda[] = "R$";

    printf("Número de itens: %d\n", qtd);
    printf("Preço de cada unidade: %d\n", preco_unidade);
    printf("Valor total:  %d %s\n", preco_total, moeda);
}