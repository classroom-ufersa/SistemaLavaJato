#include "cliente.h"
#include "../veiculo/veiculo.h"

// void limpar_buffer(void)
// {
//     int c;
//     while ((c = getchar()) != '\n' && c != EOF)
//         ;
// }

struct cliente
{
    int id;
    char nome[81];
    char telefone[16];
    Veiculo *veiculo;
    struct cliente *prox;
};

Cliente *add_cliente(Cliente *c, char *nome, char *telefone, int id, Veiculo **todos_veiculo)
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

    new_cliente->veiculo = NULL;

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
    char escolha;
    printf("Cadastro de veiculo\n");
while (adiciona_mais == 1)
    {
        printf("Digite a marca:");
        scanf(" %[^\n]", marca);
        limpar_buffer();
        printf("Digite o modelo:");
        scanf(" %[^\n]", modelo);
        limpar_buffer();
        printf("Digite a placa do veiculo:");
        scanf(" %[^\n]", placa);
        limpar_buffer();
        printf("Digite a cor:");
        scanf(" %[^\n]", cor);
        limpar_buffer();
        while (1)
        {
            apresenta_menu(6, OPCAO1, TITULO_SERVICO_OPCAO1, TITULO_SERVICO_OPCAO2, TITULO_SERVICO_OPCAO3, TITULO_SERVICO_OPCAO4, TITULO_SERVICO_OPCAO4, TITULO_SERVICO_OPCAO5, TITULO_SERVICO_OPCAO6);
            escolha = le_opcao(OPCAO1, OPCAO6);
            switch (escolha)
            {
            case OPCAO1:
                strcpy(tipo_servico, "Lavagem simples");
                break;
            case OPCAO2:
                strcpy(tipo_servico, "Lavagem com enceramento");
                break;
            case OPCAO3:
                strcpy(tipo_servico, "Polimento");
                break;
            case OPCAO4:
                strcpy(tipo_servico, "Higienizacao de ar-condicionado");
                break;
            case OPCAO5:
                strcpy(tipo_servico, "Higienizacao interna");
                break;
            case OPCAO6:
                strcpy(tipo_servico, "Limpeza e hidratacao de couro");
                break;
            default:
                printf("Digite um numero de 1 a 6\n");
            }
            break;
        }
        Veiculo *aux = criarVeiculo(id, modelo, tipo_servico, placa, marca, cor, new_cliente, 0);
        new_cliente->veiculo = adicionarVeiculo(new_cliente->veiculo, aux);
        *todos_veiculo = adicionarVeiculo(*todos_veiculo, aux);
        qtd_veiculos++;
        printf("Digite 'S' para cadastrar mais um veiculo, ou digite qualquer tecla para retornar ao menu principal.\n");
        char resposta;
        scanf(" %c", &resposta);
        limpar_buffer();
        resposta = toupper(resposta);
        if (resposta != 'S')
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

    p->veiculo = excluir_vci_cliente(p->veiculo, id, p);

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
    {
        printf("ID: %d\tNome: %s\tTelefone: %s\n", p->id, p->nome, p->telefone);
        veiculo_imprime(p->veiculo);
    }
}


Cliente *editar_cliente(Cliente *c, int id)
{
    Cliente *atual = c;

    // Percorrer a lista de clientes
    while (atual != NULL)
    {
        if (atual->id == id)
        {
            // Se encontrarmos o cliente com o ID desejado, permitimos a edição das informações
            printf("Digite o novo nome para o cliente: \n");
            scanf("%s", atual->nome);
            printf("Digite o novo telefone : \n");
            scanf("%s", atual->telefone);
            // Outras operações de edição de informações do cliente podem ser adicionadas aqui

            return c; // Retorna o ponteiro original para a lista de clientes com as edições feitas
        }
        atual = atual->prox;
    }

    // Se o cliente com o ID desejado não for encontrado, retornamos a lista original
    return c;
}
