#include <stdio.h>

typedef struct {
    char estado[50];
    char codigo[20];
    char nome[50];
    unsigned long int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float pib_per_capita;
    float densidade_populacional;
    float super_poder;
} Carta;

// Funções para cálculo dos atributos
void calcular_densidade(Carta *carta) {
    carta->densidade_populacional = carta->populacao / carta->area;
}

void calcular_pib_per_capita(Carta *carta) {
    carta->pib_per_capita = carta->pib / carta->populacao;
}

void calcular_super_poder(Carta *carta) {
    carta->super_poder = carta->populacao + carta->area + carta->pib + carta->pontos_turisticos +
                         carta->pib_per_capita + (1 / carta->densidade_populacional);
}

// Função para comparar as cartas
void comparar_cartas(Carta c1, Carta c2) {
    printf("\nComparação de Cartas:\n");

    printf("População: Carta %d venceu (%d)\n", c1.populacao > c2.populacao ? 1 : 2, c1.populacao > c2.populacao);
    printf("Área: Carta %d venceu (%d)\n", c1.area > c2.area ? 1 : 2, c1.area > c2.area);
    printf("PIB: Carta %d venceu (%d)\n", c1.pib > c2.pib ? 1 : 2, c1.pib > c2.pib);
    printf("Pontos Turísticos: Carta %d venceu (%d)\n", c1.pontos_turisticos > c2.pontos_turisticos ? 1 : 2, c1.pontos_turisticos > c2.pontos_turisticos);
    printf("Densidade Populacional: Carta %d venceu (%d)\n", c1.densidade_populacional < c2.densidade_populacional ? 1 : 2, c1.densidade_populacional < c2.densidade_populacional);
    printf("PIB per Capita: Carta %d venceu (%d)\n", c1.pib_per_capita > c2.pib_per_capita ? 1 : 2, c1.pib_per_capita > c2.pib_per_capita);
    printf("Super Poder: Carta %d venceu (%d)\n", c1.super_poder > c2.super_poder ? 1 : 2, c1.super_poder > c2.super_poder);
}

int main() {
    Carta carta1, carta2;

    
    printf("Digite os dados da Carta 1 (estado, código, nome, população, área, PIB, pontos turísticos):\n");
    scanf("%s %s %s %lu %f %f %d", carta1.estado, carta1.codigo, carta1.nome, &carta1.populacao, &carta1.area, &carta1.pib, &carta1.pontos_turisticos);

    printf("Digite os dados da Carta 2 (estado, código, nome, população, área, PIB, pontos turísticos):\n");
    scanf("%s %s %s %lu %f %f %d", carta2.estado, carta2.codigo, carta2.nome, &carta2.populacao, &carta2.area, &carta2.pib, &carta2.pontos_turisticos);

    
    calcular_densidade(&carta1);
    calcular_densidade(&carta2);
    
    calcular_pib_per_capita(&carta1);
    calcular_pib_per_capita(&carta2);
    
    calcular_super_poder(&carta1);
    calcular_super_poder(&carta2);

   
    comparar_cartas(carta1, carta2);

    return 0;
}