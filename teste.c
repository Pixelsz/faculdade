#include <stdio.h>
#include <math.h>

#define MAX 99
#define MAX_PONTOS 100
#define MAX_NOME 99

float d(float x_a, float x_b, float y_a, float y_b)
{
    float pow_1 = pow(x_a - x_b, 2);
    float pow_2 = pow(y_a - y_b, 2);
    return sqrt(pow_1 + pow_2);
}

int main()
{
    int n_pontos_lidos = 0;
    float distancia = 5.0f;
    char nome_pontos[MAX][MAX];
    float pontos_X[MAX];
    float pontos_Y[MAX];
    while (distancia >= 5.0f)
    {
        printf("\nColoque o nome do ponto: ");
        scanf("%98s", nome_pontos[n_pontos_lidos]);
        printf("\nQual a coordenada X do ponto '%s'? ", nome_pontos[n_pontos_lidos]);
        scanf("%f", &pontos_X[n_pontos_lidos]);
        printf("\nQual a coordenada Y do ponto '%s'? ", nome_pontos[n_pontos_lidos]);
        scanf("%f", &pontos_Y[n_pontos_lidos]);
        printf("\nNome do ponto: %s\nX: %f\nY: %f\n", nome_pontos[n_pontos_lidos],
               pontos_X[n_pontos_lidos],
               pontos_Y[n_pontos_lidos]);
        if (n_pontos_lidos > 0)
        {
            distancia = d(pontos_X[n_pontos_lidos], pontos_X[n_pontos_lidos - 1],
                          pontos_Y[n_pontos_lidos], pontos_Y[n_pontos_lidos - 1]);
        }
        n_pontos_lidos++;
    }
    // Quantos pontos estão em cada quadrante?
    int Q1 = 0;
    int Q2 = 0;
    int Q3 = 0;
    int Q4 = 0;
    for (int i = 0; i < n_pontos_lidos; i++)
    {
        if ((pontos_X[i] > 0) && (pontos_Y[i] > 0))
        {
            Q1++;
        }
        if ((pontos_X[i] < 0) && (pontos_Y[i] > 0))
        {
            Q2++;
        }
        if ((pontos_X[i] < 0) && (pontos_Y[i] < 0))
        {
            Q3++;
        }
        if ((pontos_X[i] > 0) && (pontos_Y[i] < 0))
        {
            Q4++;
        }
    }
    printf("\nQ1: %d\nQ2: %d\nQ3: %d\nQ4: %d\n", Q1, Q2, Q3, Q4);

    float ponto_mais_alto = 0;
    int indice_ponto_mais_alto = 0;
    for (int i = 0; i < n_pontos_lidos; i++)
    {
        if (pontos_Y[i] > ponto_mais_alto)
        {
            ponto_mais_alto = pontos_Y[i];
            indice_ponto_mais_alto = i;
        }
    }
    printf("O ponto mais alto é o ponto: '%s'.\n",
           nome_pontos[indice_ponto_mais_alto]);

    float ponto_mais_a_esquerda = 0;
    int indice_ponto_mais_a_esquerda = 0;
    for (int i = 0; i < n_pontos_lidos; i++)
    {
        if (pontos_X[i] < ponto_mais_a_esquerda)
        {
            ponto_mais_a_esquerda = pontos_X[i];
            indice_ponto_mais_a_esquerda = i;
        }
    }
    printf("O ponto mais a esquerdaa é o ponto: '%s'.\n",
           nome_pontos[indice_ponto_mais_a_esquerda]);
}