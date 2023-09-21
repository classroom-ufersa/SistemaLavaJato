#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"veiculos.h"
#include "../cliente/cliente.h"

typedef struct veiculos
{
    int id;
    char marca[100];
    char modelo[100];
    char placa[12];
    int atendido;
    char cor[12];
    Cliente *cliente;
    char tipo_de_servico[100];
}Veiculo;

 Veiculo* adicionarVeiculo(int *id, char *modelo, char *tipo_servico, char *placa, char *marca, char *cor, Cliente *cliente){
    Veiculo *v = (Veiculo*) malloc (sizeof(Veiculo));
    strcpy(v->placa, placa);
    strcpy(v->marca, marca);
    strcpy(v->cor, cor);
    strcpy(v->modelo, modelo);
    strcpy(v->tipo_de_servico, tipo_servico);
    v->id=id;
    v->cliente= cliente;
    return (v);
}
void gerenciamento_de_veiculos(Veiculo* veiculos, int n){
    printf ("Registrar veiculos atendidos");
    int gerenciador;
    int i;
    for (i = 0; i < n; i++){
        if(veiculos[i].atendido==0){
            printf("ID: %d, Tipo de serviço: %s, Marca: %s, Modelo: %s, Placa: %s\n", veiculos[i].tipo_de_servico, veiculos[i].marca, veiculos[i].modelo, veiculos[i].placa);
        }
        

        
    }
}
Veiculo* buscar_veiculo(Veiculo **veiculos, int n, int *id){
    int i;
    for(i=0; i < n; i++){
        if(veiculos[i]->id==id){
            return veiculos[i];
        }
    }
    return NULL;
}

void consultarVeiculosAtendidos(Veiculo* veiculos, int n) {
    printf("Lista de Veículos Atendidos:\n");
    int contador = 0;
    int i;
    for ( i = 0; i < n; i++) {
        if (veiculos[i].atendido == 1) {
            printf("ID: %d,Tipo de serviço: %s, Marca: %s, Modelo: %s, Placa: %s\n", veiculos[i].tipo_de_servico, veiculos[i].marca, veiculos[i].modelo, veiculos[i].placa);
            contador++;
        }
    }
    if (contador == 0) {
        printf("Nenhum veiculo em servico encontrado.\n");
    }
}