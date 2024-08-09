#include <stdio.h>

int main()
{
    int qtd = 25;
    float preco_unidade = 10.99;
    int preco_total = qtd * preco_unidade;
    char moeda[] = "R$";

    printf("Número de itens: %d\n", qtd);
    printf("Preço de cada unidade: %.2f %s\n", preco_unidade, moeda);
    printf("Valor total:  %.2f %s\n", preco_total, moeda);
}