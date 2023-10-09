#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include "./cliente/cliente.c"
#include "./veiculo/veiculo.c"

#define TITULO_OPCAO1 "Adicionar cliente"
#define TITULO_OPCAO2 "Excluir cliente"
#define TITULO_OPCAO3 "Listar veiculos atendidos"
#define TITULO_OPCAO4 "Buscar cliente"
#define TITULO_OPCAO5 "Editar informações de cliente"
#define TITULO_OPCAO6 "Consultar veiculos em serviço"
#define TITULO_OPCAO7 "Finalizar atendimento"
#define TITULO_OPCAO8 "Sair"

#define N_OPCOES 8
#define OPCAO1 '1'
#define OPCAO2 '2'
#define OPCAO3 '3'
#define OPCAO4 '4'
#define OPCAO5 '5'
#define OPCAO6 '6'
#define OPCAO7 '7'
#define OPCAO8 '8'

/****
 * Função: limpar_buffer()
 * Descrição: Lê e descarta caracteres encontrados na entrada
 * Parâmetros: Nenhum
 * Retorno: Nada
 ****/
// void limpar_buffer(void)
// {
//     int c;
//     while ((c = getchar()) != '\n' && c != EOF)
//         ;
// }

/* Lê e valida a opção digitada pelo usuário
** @param menor_valor: o menor valor válido
** @param maior_valor: o maior valor válido
*/
int le_opcao(int menor_valor, int maior_valor)
{
    int op;
    while (1)
    {
        printf("\nDigite sua opcão: ");
        op = getchar();
        if (op >= menor_valor && op <= maior_valor)
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
    return op;
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
    printf("\nDigite um número de telefone: ");
    if (fgets(telefone, tamanho_max, stdin) != NULL)
    {
        // Remova espaços, traços e parênteses do número de telefone
        int length = strlen(telefone);
        for (int i = 0; i < length; i++)
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

int main(void)
{
    unsigned char op;
    unsigned int saida = 0;
    char nome[100];
    int id;
    char telefone[20];
    Cliente *cliente_buscado = NULL;
    Cliente *clientes = NULL;
    Veiculo *veiculo = NULL;
    Veiculo *lista_Veiculos = NULL;
    int id_busca;
    char resposta;
    int id_case4;
    int id_case5;
    char placa_case7[12];

    do
    {
        apresenta_menu(N_OPCOES, OPCAO1, TITULO_OPCAO1, TITULO_OPCAO2, TITULO_OPCAO3, TITULO_OPCAO4, TITULO_OPCAO5, TITULO_OPCAO6, TITULO_OPCAO7, TITULO_OPCAO8);
        op = le_opcao(OPCAO1, OPCAO1 + N_OPCOES - 1);
        switch (op)
        {
        case OPCAO1:
            le_nome(nome, sizeof(nome));
            corrige_nome(nome);
            // printf("%s", nome);
            // le_telefone(telefone, sizeof(telefone));
            printf("Digite o numero de telefone: ");
            scanf(" %s", telefone);
            limpar_buffer();
            id = gerar_id();
            clientes = add_cliente(clientes, nome, telefone, id, &lista_Veiculos);
            break;
        case OPCAO2:
            if (clientes != NULL)
            {
                imprime_cliente(clientes);
                printf("Insira o id do usuario que deseja excluir: \n");
                scanf("%d", &id_busca);
                limpar_buffer();
                cliente_buscado = busca_cliente(clientes, id_busca);
                printf("Deseja excluir o cliente (s / n)\n");
                imprime_cliente(cliente_buscado);
                scanf(" %c", &resposta);
                limpar_buffer();
                if (resposta == 's')
                {
                    if (cliente_buscado != NULL)
                    {
                        clientes = excluir_cliente(clientes, id_busca);
                        printf("Cliente excluido com sucesso!\n");
                    }
                    else
                    {
                        printf("Nao foi possivel achar o cliente.\n");
                    }
                }
            }
            else
            {
                printf("Lista de clientes vazia!\n");
            }

            break;
        case OPCAO3:
            imprime_cliente(clientes);
            break;
        case OPCAO4:
            printf("Insira o id do cliente que deseja buscar:\n");
            scanf("%d", &id_case4);
            limpar_buffer();
            cliente_buscado = busca_cliente(clientes, id_case4);
            imprime_cliente(cliente_buscado);
            free(cliente_buscado);
            break;
        case OPCAO5:
            printf("Insira o id do cliente que deseja buscar:\n");
            scanf("%d", &id_case5);
            limpar_buffer();
            cliente_buscado = busca_cliente(clientes, id_case5);
            clientes = editar_cliente(cliente_buscado, id_case5);
            break;
            break;
        case OPCAO6:
            listarVeiculosNaoAtendidos(lista_Veiculos);
            break;
        case OPCAO7:
            printf("Informe a placa do veiculo: ");
            scanf(" %[^\n]", placa_case7);
            limpar_buffer();
            veiculo = buscarVeiculoPorPlaca(veiculo, placa_case7);
            lista_Veiculos = AtenderVeiculo(veiculo);
            break;
        case OPCAO8:
            printf("Saindo do programa. Ate logo!\n");
            saida = 1;
            break;
        default:
            printf("Opcao invalida. Tente novamente.\n");
            break;
        }
    } while (!saida);

    free(clientes);
    free(veiculo);
    free(lista_Veiculos);

    return 0;
}