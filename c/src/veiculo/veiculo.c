#include "veiculo.h"
#include "../cliente/cliente.h"

struct veiculo
{
    int id;
    char marca[100];
    char modelo[100];
    char placa[12];
    int atendido;
    char cor[12];
    Cliente *cliente;
    char tipo_servico[100];
    Veiculo *prox;
};

Veiculo *criarVeiculo(int id, char *modelo, char *tipo_servico, char *placa, char *marca, char *cor, Cliente *cliente, int atendido)
{
    Veiculo *veiculo = (Veiculo *)malloc(sizeof(Veiculo));
    if (veiculo != NULL)
    {
        veiculo->id = id;
        strcpy(veiculo->modelo, modelo);
        strcpy(veiculo->tipo_servico, tipo_servico);
        strcpy(veiculo->placa, placa);
        strcpy(veiculo->marca, marca);
        strcpy(veiculo->cor, cor);
        veiculo->cliente = cliente;
        veiculo->atendido = atendido;
        veiculo->prox = NULL;
    }
    return veiculo;
}

Veiculo *adicionarVeiculo(Veiculo *lista, Veiculo *veiculo)
{
    veiculo->prox = lista;
    return veiculo;
}

Veiculo *AtenderVeiculo(Veiculo *lista_veiculos, Veiculo *v)
{

    Veiculo *p;
    for (p = lista_veiculos; p != NULL; p = p->prox)
    {
        if (strcmp(p->placa, v->placa) == 0)
        {
            p->atendido = 1;
            printf("Veiculo atendido!\n");
            return lista_veiculos;
        }
    }
    return lista_veiculos;
}

int listarVeiculosNaoAtendidos(Veiculo *lista)
{
    int veiculoNaoAtendidoEncontrado = 0; // Variável de controle

    printf("Lista de Veiculos Nao Atendidos:\n");
    while (lista != NULL)
    {
        if (lista->atendido == 0)
        {
            printf("_______________________________________________________________________\n");
            printf("ID: %d\nTipo de servico: %s\nMarca: %s\nModelo: %s\nPlaca: %s\n",
                   lista->id, lista->tipo_servico, lista->marca, lista->modelo, lista->placa);
            veiculoNaoAtendidoEncontrado = 1; // Um veículo não atendido foi encontrado
            printf("_______________________________________________________________________\n");
        }
        lista = lista->prox;
    }

    if (!veiculoNaoAtendidoEncontrado)
    {
        printf("Nenhum veiculo está em servico.\n\n");
        return 0;
    }
    return 1;
}
void veiculo_imprime_atendidos(Veiculo *v)
{
    int algum_veiculo_foi_atendido = 0;
    Veiculo *p; // pecorrer a lista
    for (p = v; p != NULL; p = p->prox)
    {
        if (p->atendido == 1)
        {
            printf("MARCA: %s\tMODELO: %s\tPLACA: %s\tCOR: %s\tSERVIÇO %s - CLIENTE %s\n", p->marca, p->modelo, p->placa, p->cor, p->tipo_servico, p->cliente->nome);
            algum_veiculo_foi_atendido = 1;
        }
    }
    if (!algum_veiculo_foi_atendido)
        printf("Nenhum Veiculo foi atendido!\n");
}

Veiculo *buscarVeiculoPorPlaca(Veiculo *lista, char *placa)
{
    Veiculo *veiculo_buscado = (Veiculo *)malloc(sizeof(Veiculo));
    while (lista != NULL)
    {
        char *placa_veiculo = lista->placa;
        if (strcmp(placa_veiculo, placa) == 0)
        {
            veiculo_buscado->id = lista->id;
            strcpy(veiculo_buscado->modelo, lista->modelo);
            strcpy(veiculo_buscado->tipo_servico, lista->tipo_servico);
            strcpy(veiculo_buscado->placa, lista->placa);
            strcpy(veiculo_buscado->marca, lista->marca);
            strcpy(veiculo_buscado->cor, lista->cor);
            veiculo_buscado->cliente = lista->cliente;
            veiculo_buscado->atendido = lista->atendido;
            veiculo_buscado->prox = NULL;
            return veiculo_buscado;
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

int vci_is_empty(Veiculo *v)
{
    if (v == NULL)
        return 1;
    return 0;
}

Veiculo *vci_retira(Veiculo *v, char *placa)
{
    Veiculo *ant = NULL;
    Veiculo *p = v;

    /* Procura veiculo na lista,
       guardando anterior */
    while (p != NULL && strcmp(p->placa, placa) < 0)
    {
        ant = p;
        p = p->prox;
    }
    /* Verifica se achou veiculo */
    if (p == NULL)
        return v;
    /* retira veiculo */
    if (ant == NULL)
        v = p->prox; /* retira veiculo do inicio */
    else
        ant->prox = p->prox; /* retira elemento do meio */
    free(p);
    return v;
}

Veiculo *excluir_vci_cliente(Veiculo *v, int id, Cliente *cliente)
{
    Veiculo *ant = NULL;
    Veiculo *p = v;

    /* procura elemento na lista,
        guardando anterior */
    while (p != NULL && p->cliente != cliente)
    {
        ant = p;
        p = p->prox;
    }
    /* verifica se achou o elemento */
    if (p == NULL)
        return v;
    /* retira elemento */
    if (ant == NULL)
        v = p->prox; // retira o elemento do inicio
    else
        ant->prox = p->prox; // retira elemento do meio
    free(p);
    return v;
}
