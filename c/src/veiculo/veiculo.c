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

Veiculo *criarVeiculo(int id, char *modelo, char *tipo_servico, char *placa, char *marca, char *cor, Cliente *cliente)
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

Veiculo *AtenderVeiculo(Veiculo *v)
{

    Veiculo *p;
    for (p = v; p != NULL; p = p->prox)
    {
        if (p->placa == v->placa)
            p->atendido = 1;
    }

    return (v);
}

void listarVeiculosNaoAtendidos(Veiculo *lista)
{
    int veiculoNaoAtendidoEncontrado = 0; // Variável de controle

    printf("Lista de Veiculos Nao Atendidos:\n");
    while (lista != NULL)
    {
        if (lista->atendido == 0)
        {
            printf("ID: %d, Tipo de servico: %s, Marca: %s, Modelo: %s, Placa: %s\n",
                   lista->id, lista->tipo_servico, lista->marca, lista->modelo, lista->placa);
            veiculoNaoAtendidoEncontrado = 1; // Um veículo não atendido foi encontrado
        }
        lista = lista->prox;
    }

    if (!veiculoNaoAtendidoEncontrado)
    {
        printf("Nenhum veiculo nao esta em servico.\n");
    }
}
void veiculo_imprime(Veiculo *v)
{
    Veiculo *p; // pecorrer a lista
    printf("MARCA\tMODELO\tPLACA\tCOR\tSERVICO\n");
    for (p = v; p != NULL; p = p->prox)
    {
        printf("%s\t%s\t%s\t%s\t%s - CLIENTE %s\n", p->marca, p->modelo, p->placa, p->cor, p->tipo_servico, p->cliente->nome);
    }
}

Veiculo *buscarVeiculoPorPlaca(Veiculo *lista, char *placa)
{
    while (lista != NULL)
    {
        char *placa_veiculo = lista->placa; 
        if (strcmp(placa_veiculo, placa) == 0)
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
