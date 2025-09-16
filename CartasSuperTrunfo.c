#include <stdio.h>
#include <string.h>

typedef struct
{
    char estado;
    char codigo[10];
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidade;
    float pibPerCapita;
    float superPoder;
} Carta;

void fillCards(Carta *carta, int numero)
{
    printf("\n--- Carta %d ---\n", numero);

    printf("Digite o estado (1 letra): ");
    scanf(" %c", &carta->estado);
    getchar();

    printf("Digite o codigo: ");
    fgets(carta->codigo, sizeof(carta->codigo), stdin);
    carta->codigo[strcspn(carta->codigo, "\n")] = '\0';

    printf("Digite o nome da cidade: ");
    fgets(carta->nome, sizeof(carta->nome), stdin);
    carta->nome[strcspn(carta->nome, "\n")] = '\0';

    printf("Digite a populacao: ");
    scanf("%d", &carta->populacao);

    printf("Digite a area em km²: ");
    scanf("%f", &carta->area);

    printf("Digite o PIB: ");
    scanf("%f", &carta->pib);

    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &carta->pontosTuristicos);

    getchar();
}

void operation(Carta *carta)
{
    carta->densidade = carta->populacao / carta->area;
    carta->pibPerCapita = carta->pib / carta->populacao;
    carta->superPoder = (float)carta->populacao + carta->area + carta->pib + (float)carta->pontosTuristicos + carta->pibPerCapita + (1.0f / carta->densidade);
}

void showResults(Carta carta, int numero)
{
    printf("\n--- Resultados da Carta %d ---\n", numero);
    printf("Estado: %c\n", carta.estado);
    printf("Codigo: %s\n", carta.codigo);
    printf("Cidade: %s\n", carta.nome);
    printf("Populacao: %d\n", carta.populacao);
    printf("Area: %.2f km²\n", carta.area);
    printf("PIB: %.2f\n", carta.pib);
    printf("Pontos Turisticos: %d\n", carta.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidade);
    printf("PIB per Capita: %.2f\n", carta.pibPerCapita);
    printf("Super Poder: %.2f\n", carta.superPoder);
}

void compareCards(Carta carta1, Carta carta2)
{
    printf("\n--- Comparacao entre as Cartas ---\n");

    if (carta1.populacao > carta2.populacao)
        printf("Populacao: Carta 1 vence\n");
    else if (carta1.populacao < carta2.populacao)
        printf("Populacao: Carta 2 vence\n");
    else
        printf("Populacao: Empate\n");

    if (carta1.area > carta2.area)
        printf("Area: Carta 1 vence\n");
    else if (carta1.area < carta2.area)
        printf("Area: Carta 2 vence\n");
    else
        printf("Area: Empate\n");

    if (carta1.pib > carta2.pib)
        printf("PIB: Carta 1 vence\n");
    else if (carta1.pib < carta2.pib)
        printf("PIB: Carta 2 vence\n");
    else
        printf("PIB: Empate\n");

    if (carta1.pontosTuristicos > carta2.pontosTuristicos)
        printf("Pontos Turisticos: Carta 1 vence\n");
    else if (carta1.pontosTuristicos < carta2.pontosTuristicos)
        printf("Pontos Turisticos: Carta 2 vence\n");
    else
        printf("Pontos Turisticos: Empate\n");

    if (carta1.densidade < carta2.densidade)
        printf("Densidade Populacional: Carta 1 vence\n");
    else if (carta1.densidade > carta2.densidade)
        printf("Densidade Populacional: Carta 2 vence\n");
    else
        printf("Densidade Populacional: Empate\n");

    if (carta1.pibPerCapita > carta2.pibPerCapita)
        printf("PIB per Capita: Carta 1 vence\n");
    else if (carta1.pibPerCapita < carta2.pibPerCapita)
        printf("PIB per Capita: Carta 2 vence\n");
    else
        printf("PIB per Capita: Empate\n");

    if (carta1.superPoder > carta2.superPoder)
        printf("Super Poder: Carta 1 vence\n");
    else if (carta1.superPoder < carta2.superPoder)
        printf("Super Poder: Carta 2 vence\n");
    else
        printf("Super Poder: Empate\n");
}

int main()
{
    Carta carta1, carta2;

    fillCards(&carta1, 1);
    fillCards(&carta2, 2);

    operation(&carta1);
    operation(&carta2);

    showResults(carta1, 1);
    showResults(carta2, 2);

    compareCards(carta1, carta2);

    return 0;
}
