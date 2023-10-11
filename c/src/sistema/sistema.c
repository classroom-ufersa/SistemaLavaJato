#include "sistema.h"

void limpar_buffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

int le_opcao(int menor_valor, int maior_valor)
{
    char op[100];
    int aux = 0;
    while (1)
    {
        printf("\nDigite sua opcão: ");
        scanf(" %[^\n]s", op);
        aux = op[0];
        if (aux >= menor_valor && aux <= maior_valor && strlen(op) == 1)
        {
            limpar_buffer();
            break;
        }
        else
        {
            printf("\nOpção invalida. Tente novamente.");
            printf("\nA opção deve estar entre %c e %c. \n", menor_valor, maior_valor);
            limpar_buffer();
        }
    }
    return aux;
}

/* Lê um nome
**
*/
void le_nome(char *nome, int tamanho_max)
{
    printf("Digite um nome: ");
    if (fgets(nome, tamanho_max, stdin) != NULL)
    {
        // Remove a quebra de linha do final da string (se existir)
        int length = strlen(nome);
        if (length > 0 && nome[length - 1] == '\n')
        {
            nome[length - 1] = '\0';
        }
    }
    else
    {
        printf("Erro na leitura do nome.\n");
    }
    // limpar_buffer();
}

/* Apresenta menu com número indeterminado de opções
** @param n_itens: número de itens no menu
** @param menor_opcao: caractere associado ao item I
*/
void apresenta_menu(int n_itens, int menor_opcao, ...)
{
    int i;
    va_list argumentos;
    /* Inicia lista de argumentos variáveis */
    va_start(argumentos, menor_opcao);
    /* Lê cada argumento e imprime na tela. Note que o
       tipo de cada argumento é char *, que é o tipo que
       representa strings em C
    */
    for (i = 0; i < n_itens; i++)
    {
        printf("%c-%s\n", menor_opcao++, va_arg(argumentos, char *));
    }
    va_end(argumentos); /* Encerra processamento de argumentos */
}

void corrige_nome(char *nome)
{
    int tamanho_do_nome = strlen(nome);
    int i, j;
    char ultimo_caractere = ' ';

    for (i = 0, j = 0; i < tamanho_do_nome; i++)
    {
        if (isalpha(nome[i]) || nome[i] == ' ')
        {
            if (nome[i] == ' ' && ultimo_caractere == ' ')
            {
                continue;
            }
            nome[j] = nome[i];
            j++;
            ultimo_caractere = nome[i];
        }
    }
    nome[j] = '\0';
    nome[0] = toupper(nome[0]);
    for (i = 1; i < j; i++)
    {
        nome[i] = tolower(nome[i]);
        if (nome[i - 1] == ' ')
        {
            nome[i] = toupper(nome[i]);
        }
    }
    tamanho_do_nome = strlen(nome);
    if (j == 1 && nome[tamanho_do_nome] == ' ')
    {
        nome[tamanho_do_nome] = '\0';
    }
}

int gerar_id()
{
    srand(time(NULL)); // Define uma semente com base no tempo atual

    int numeroAleatorio = rand() % 100000000; // Gera um número aleatório de até 8 dígitos

    while (numeroAleatorio < 10000000)
    {
        numeroAleatorio *= 10; // Garante que o número tenha exatamente 8 dígitos
    }

    return numeroAleatorio;
}

void le_telefone(char *telefone, int tamanho_max)
{
    int i;
    printf("\nDigite um número de telefone: ");
    if (fgets(telefone, tamanho_max, stdin) != NULL)
    {
        // Remova espaços, traços e parênteses do número de telefone
        int length = strlen(telefone);
        for (i = 0; i < length; i++)
        {
            if (isdigit(telefone[i]))
            {
                // Mantenha apenas dígitos
                telefone[length++] = telefone[i];
            }
        }
        telefone[length] = '\0';
    }
    else
    {
        printf("Erro na leitura do número de telefone.\n");
    }
    limpar_buffer();
}

void formatar_telefone(const char *telefone)
{
    if (strlen(telefone) == 11)
    {
        char ddd[3], numero[6], parte_final[5];
        sscanf(telefone, "%2s%5s%4s", ddd, numero, parte_final);
        printf("+55 (%s) %s-%s\n", ddd, numero, parte_final);
    }
    else
    {
        printf("Número de telefone inválido.\n");
    }
}

void salvar_clientes(const char *nome_arquivo_clientes, const char *nome_arquivo_veiculos, Cliente *lista_clientes, Veiculo *lista_veiculos)
{
    FILE *arquivo_clientes;
    arquivo_clientes = fopen(nome_arquivo_clientes, "w");
    if (arquivo_clientes == NULL)
    {
        perror("Erro ao abrir arquivo de clientes!\n");
        exit(1);
    }

    FILE *arquivo_veiculos;
    arquivo_veiculos = fopen(nome_arquivo_veiculos, "w");
    if (arquivo_veiculos == NULL)
    {
        perror("Erro ao abrir arquivo de veiculos!\n");
        exit(1);
    }

    Cliente *p = lista_clientes; // variavel auxiliar para pecorrer lista
    while (p != NULL)
    {
        fprintf(arquivo_clientes, "%d,%s,%s\n", p->id, p->nome, p->telefone);
        p = p->prox;
    }

    Veiculo *v = lista_veiculos; // varaivel auxiliar para pecorrer a lista de veiculos de cada cliente
    while (v != NULL)
    {
        fprintf(arquivo_veiculos, "%d,%s,%s,%s,%d,%s,%s\n", v->id, v->marca, v->modelo, v->placa, v->atendido, v->cor, v->tipo_servico);
        v = v->prox;
    }

    fclose(arquivo_clientes);
    fclose(arquivo_veiculos);
}

Cliente *carregar_clientes(const char *nome_arquivo_clientes, const char *nome_arquivo_veiculos, Veiculo **lista_veiculos)
{
    FILE *arquivo_clientes;
    arquivo_clientes = fopen(nome_arquivo_clientes, "r");
    if (arquivo_clientes == NULL)
    {
        perror("Erro ao abrir arquivo de clientes!\n");
        exit(1);
    }

    FILE *arquivo_veiculos;
    arquivo_veiculos = fopen(nome_arquivo_veiculos, "r");
    if (arquivo_veiculos == NULL)
    {
        perror("Erro ao abrir arquivo de veiculos!\n");
        exit(1);
    }

    Cliente *lista_clientes = NULL;
    Cliente *cliente_atual = NULL;

    char linha[500];
    while (fgets(linha, sizeof(linha), arquivo_clientes))
    {
        int id;
        char nome[81];
        char telefone[16];
        if (sscanf(linha, "%d,%80[^,],%15[^,]", &id, nome, telefone) == 3)
        {
            if (lista_clientes == NULL)
            {
                lista_clientes = malloc(sizeof(Cliente));
                cliente_atual = lista_clientes;
            }
            else
            {
                cliente_atual->prox = malloc(sizeof(Cliente));
                cliente_atual = cliente_atual->prox;
            }

            cliente_atual->id = id;
            strcpy(cliente_atual->nome, nome);
            strcpy(cliente_atual->telefone, telefone);
            cliente_atual->veiculo = NULL;
            cliente_atual->prox = NULL;
        }

        while (fgets(linha, sizeof(linha), arquivo_veiculos))
        {
            int veiculo_id, atendido;
            char marca[100], modelo[100], placa[12], cor[12], tipo_servico[100];
            if (sscanf(linha, "%d,%99[^,],%99[^,],%11[^,],%d,%11[^,],%99[^,]", &veiculo_id, marca, modelo, placa, &atendido, cor, tipo_servico) == 7)
            {

                // Encontre o cliente correspondente
                Cliente *cliente = lista_clientes;
                while (cliente != NULL && cliente->id != veiculo_id)
                {
                    cliente = cliente->prox;
                }

                if (cliente_atual != NULL)
                {
                    Veiculo *veiculo = criarVeiculo(veiculo_id, modelo, tipo_servico, placa, marca, cor, cliente_atual, atendido);
                    *lista_veiculos = adicionarVeiculo(*lista_veiculos, veiculo);
                }
            }
        }
    }

    fclose(arquivo_clientes);
    fclose(arquivo_veiculos);
    return lista_clientes;
}
