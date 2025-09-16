#include <stdio.h>
#include <string.h>

typedef struct {
    char estado;      
    char codigo[10];     
    char nome[50];        
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidade;
    float pibPerCapita;
} Carta;

void fillCards(Carta *carta, int numero) {
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

void operation(Carta *carta) {
    carta->densidade = carta->populacao / carta->area;
    carta->pibPerCapita = carta->pib / carta->populacao;
}

void showResults(Carta carta, int numero) {
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
}

int main() {
    Carta carta1, carta2;

    fillCards(&carta1, 1);
    fillCards(&carta2, 2);

    operation(&carta1);
    operation(&carta2);

    showResults(carta1, 1);
    showResults(carta2, 2);

    return 0;
}
