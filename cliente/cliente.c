#include "cliente.h"
#include "../veiculos/veiculos.h"

struct cliente
{
    int id;
    char nome[81];
    char telefone[16];
    Veiculo *veiculo;
    struct cliente *prox;
};

Cliente *add_cliente(Cliente *c, char *nome, char *telefone, int id)
{
    Cliente *new_cliente;
    Cliente *ant = NULL;
    Cliente *p = c;

    /*procurando posição de inserção*/
    while (p != NULL && strcmp(p->nome, nome) < 0)
    {
        ant = p;
        p = p->prox;
    }
    /*Cria novo cliente*/
    new_cliente = (Cliente *)malloc(sizeof(Cliente));
    new_cliente->veiculo = vci_cria();

    strcpy(new_cliente->nome, nome);
    strcpy(new_cliente->telefone, telefone);
    new_cliente->id = id;

    int adiciona_mais = 1; // 1 true | 0 false
    char marca[100];
    char modelo[100];
    char placa[12];
    char cor[12];
    char tipo_servico[100];
    int qtd_veiculos = 0;
    printf("Cadastro de veiculo\n");
    while (adiciona_mais == 1)
    {
        printf("Digite a marca:");
        scanf(" %[^\n]", marca);
        printf("Digite o modelo:");
        scanf(" %[^\n]", modelo);
        printf("Digite a placa do veiculo:");
        scanf(" %[^\n]", placa);
        printf("Digite a cor:");
        scanf(" %[^\n]", cor);
        printf("Digite o tipo de serviço:");
        scanf(" %[^\n]", tipo_servico);

        new_cliente->veiculo = vci_add(new_cliente->veiculo, marca, modelo, placa, cor, tipo_servico, new_cliente);
        qtd_veiculos++;
        printf("Deseja cadastrar mais um veiculo?(s/N)\n");
        char resposta;
        scanf(" %c", &resposta);
        if (resposta != 's' || resposta != 'S')
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
    p->veiculo = excluir_vci_cliente(p->veiculo, id);
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
    vci_imprime(c->veiculo);
}

void clientes_libera(Cliente *c)
{
    Cliente *p = c;
    while (p != NULL)
    {
        Cliente *t = p->prox;

        free(p);
        p = t;
    }
}