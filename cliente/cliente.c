#include "cliente.h"
#include "../veiculos/veiculos.c"

struct cliente
{
    int id;
    char nome[81];
    char telefone[16];
    Veiculo **veiculo;
    struct cliente *prox;
};

Cliente *add_cliente(Cliente *c, char *nome, char *telefone, int id)
{
    Cliente *new_cliente;
    Cliente *ant = NULL;
    Cliente *p = c;

    /*procurando posição de inserção*/
    while (p != NULL && p->id < strcmp(p->nome, nome) < 0)
    {
        ant = p;
        p = p->prox;
    }
    /*Cria novo cliente*/
    new_cliente = (Cliente *)malloc(sizeof(Cliente));
    new_cliente->veiculo = (Veiculo **)malloc(sizeof(Veiculo *));

    strcpy(new_cliente->nome, nome);
    strcpy(new_cliente->telefone, telefone);
    new_cliente->id = id;

    int adiciona_mais = 1; // 1 true | 0 false
    char num_placa[7];
    char marca[21];
    char cor[10];
    int qtd_veiculos = 0;
    printf("Cadastro de veiculo\n");
    while (adiciona_mais == 1)
    {
        scanf(" 7%[^\n]", num_placa);
        scanf(" 21%[^\n]", marca);
        scanf(" 10%[^\n]", cor);
        new_cliente->veiculo[qtd_veiculos] = cria_veiculo(num_placa, marca, cor, c);
        qtd_veiculos++;
        printf("Deseja cadastrar mais um veiculo?\n");
        char escolha;
        if (getc(escolha) == 's' || getc(escolha) == 'S')
        {
            new_cliente->veiculo = (Veiculo **)realloc(new_cliente->veiculo, ++qtd_veiculos * (sizeof(Veiculo *)));
            scanf(" 7%[^\n]", num_placa);
            scanf(" 21%[^\n]", marca);
            scanf(" 10%[^\n]", cor);
            new_cliente->veiculo[qtd_veiculos] = cria_veiculo(num_placa, marca, cor, c);
        }
        else
            adiciona_mais = 0;
    }
    /*Encandeia cliente*/
    if (ant == NULL) /* insere no inicio */
    {
        new_cliente->prox = c;
        c = new_cliente;
    }
    else /* insere no meio da lista de cliente */
    {
        new_cliente->prox = ant->prox;
        ant->prox = new_cliente;
    }

    return c;
}

Cliente *excluir_cliente(Cliente *c, int id)
{
    Cliente *ant = NULL;
    Cliente *p = c;

    /* procura elemento na lista,
        guardando anterior */
    while (p != NULL && p->id != id)
    {
        ant = p;
        p = p->prox;
    }
    /* verifica se achou o elemento */
    if (p == NULL)
        return c;
    /* retira elemento */
    if (ant == NULL)
        c = p->prox; // retira o elemento do inicio
    else
        ant->prox = p->prox; // retira elemento do meio
    free(p);
    return c;
}

Cliente *busca_cliente(Cliente *c, int id)
{
    Cliente *p;
    for (p = c; p != NULL; p = p->prox)
    {
        if (p->id == id)
            return p;
    }
    return NULL;
}

int lst_cliente_vazia(Cliente *l)
{
    if (l == NULL)
        return 1;
    return 0;
}

void imprime_cliente(Cliente *c)
{
    Cliente *p;
    for (p = c; p != NULL; p = p->prox)
        printf("ID: %d\tNome: %s\tTelefone: %s\n", p->id, p->nome, p->telefone);
}

void clientes_libera(Cliente *c)
{
    Cliente *p = c;
    while (p != NULL)
    {
        Cliente *t = p->prox;
        free(c);
        p = t;
    }
}