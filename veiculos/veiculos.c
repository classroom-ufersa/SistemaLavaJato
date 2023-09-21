#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../cliente/cliente.h"

typedef struct veiculo
{
    int id;
    char marca[100];
    char modelo[100];
    char placa[12];
    int atendido;
    char cor[12];
    Cliente *cliente;
    char tipo_de_servico[100];
    struct Veiculo *prox;
} Veiculo;

Veiculo *criarVeiculo(int id, char *modelo, char *tipo_servico, char *placa, char *marca, char *cor, Cliente *cliente)
{
    Veiculo *veiculo = (Veiculo *)malloc(sizeof(Veiculo));
    if (veiculo != NULL)
    {
        veiculo->id = id;
        strcpy(veiculo->modelo, modelo);
        strcpy(veiculo->tipo_de_servico, tipo_servico);
        strcpy(veiculo->placa, placa);
        strcpy(veiculo->marca, marca);
        strcpy(veiculo->cor, cor);
        veiculo->cliente = cliente;
        veiculo->atendido = 0;
        veiculo->prox = NULL;
    }
    return veiculo;
}

Veiculo *adicionarVeiculo(Veiculo *lista, Veiculo *veiculo)
{
    veiculo->prox = lista;
    return veiculo;
}

void listarVeiculosNaoAtendidos(Veiculo *lista)
{
    printf("Lista de Veiculos Nao Atendidos:\n");
    while (lista != NULL)
    {
        if (lista->atendido == 0)
        {
            printf("ID: %d, Tipo de servico: %s, Marca: %s, Modelo: %s, Placa: %s\n",
                   lista->id, lista->tipo_de_servico, lista->marca, lista->modelo, lista->placa);
        }
        lista = lista->prox;
    }
}

Veiculo *buscarVeiculoPorID(Veiculo *lista, int id)
{
    while (lista != NULL)
    {
        if (lista->id == id)
        {
            return lista;
        }
        lista = lista->prox;
    }
    return NULL;
}

void liberarListaVeiculos(Veiculo *lista)
{
    while (lista != NULL)
    {
        Veiculo *t = lista;
        lista = lista->prox;
        free(t);
    }
}