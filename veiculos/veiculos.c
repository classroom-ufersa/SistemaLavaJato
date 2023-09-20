#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"veiculos.h"

typedef struct veiculos
{
    char marca[100];
    char modelo[100];
    char placa[12];
    int servico;
    
}Veiculos;

void consultarVeiculosAtendidos(Veiculos* veiculos, int n) {
    printf("Lista de Veículos Atendidos:\n");
    int contador = 0;
    for (int i = 0; i < n; i++) {
        if (veiculos[i].servico == 1) {
            printf("ID: %d, Marca: %s, Modelo: %s, Placa: %s\n", i, veiculos[i].marca, veiculos[i].modelo, veiculos[i].placa);
            contador++;
        }
    }
    if (contador == 0) {
        printf("Nenhum veiculo em servico encontrado.\n");
    }
}