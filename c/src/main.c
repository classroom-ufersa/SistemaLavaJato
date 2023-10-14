#include "./cliente/cliente.c"
#include "./veiculo/veiculo.c"
#include "./sistema/sistema.c"

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
    char *telefone_formatado;

    printf("Carregando lista de clientes...\n");
    clientes = carregar_clientes("../data/clientes.txt", "../data/veiculos.txt", &lista_Veiculos);
    do
    {
        apresenta_menu(N_OPCOES, OPCAO1, TITULO_OPCAO1, TITULO_OPCAO2, TITULO_OPCAO3, TITULO_OPCAO4, TITULO_OPCAO5, TITULO_OPCAO6, TITULO_OPCAO7, TITULO_OPCAO8);
        op = le_opcao(OPCAO1, OPCAO1 + N_OPCOES - 1);
        switch (op)
        {
        case OPCAO1: // ADICIONAR CLIENTE
            printf("Digite um nome: ");
            le_nome(nome, sizeof(nome));
            corrige_nome(nome);
            while (formatar_telefone(telefone) == NULL)
            {
                printf("Digite o numero de telefone(somente numeros) (DDD)XXXXX-XXXX: ");
                scanf(" %s", telefone);
                limpar_buffer();
                telefone_formatado = formatar_telefone(telefone);
                if (telefone_formatado == NULL)
                    printf("entrada invalida!\n");
            }
            id = gerar_id();
            clientes = add_cliente(clientes, nome, telefone_formatado, id, &lista_Veiculos);
            break;
        case OPCAO2: // EXLUIR CLIENTE
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
        case OPCAO3: // LISTAR VEICULOS ATENDIDOS
            veiculo_imprime_atendidos(lista_Veiculos);
            break;
        case OPCAO4: // BUSCAR CLIENTE
            if (!lst_cliente_vazia(clientes))
            {
                printf("Insira o id do cliente que deseja buscar:\n");
                while (scanf("%d", &id_case4) != 1)
                {
                    printf("Entrada inválida. O ID deve ser um número: \n");
                    limpar_buffer();
                }
                cliente_buscado = busca_cliente(clientes, id_case4);
                if (cliente_buscado)
                    imprime_cliente(cliente_buscado);
                else
                    printf("Cliente não encontrando.\n");
                free(cliente_buscado);
            }
            else
            {
                printf("Lista de clientes vazia!\n");
            }
            break;
        case OPCAO5: // EDITAR INFORMAÇÕES DE CLIENTE
            if (clientes != NULL)
            {

                imprime_cliente(clientes);
                printf("Insira o id do cliente que deseja editar:\n");
                scanf("%d", &id_case5);
                limpar_buffer();
                cliente_buscado = busca_cliente(clientes, id_case5);
                if (cliente_buscado)
                {
                    editar_cliente(&clientes, id_case5);
                    free(cliente_buscado);
                }
                else
                    printf("Usuario não encontrado!\n");
            }
            else
                printf("Lista de clientes vazia!");
            break;
<<<<<<< HEAD
        case OPCAO6: // LISTA VEICULOS NÃO ATENDIDOS
            listarVeiculosNaoAtendidos(lista_Veiculos);
            break;
        case OPCAO7: // REGISTRAR ATENDIMENTO DE VEICULO
            if (listarVeiculosNaoAtendidos(lista_Veiculos))
            {
                printf("Informe a placa do veiculo: ");
                scanf(" %[^\n]", placa_case7);
                limpar_buffer();
                veiculo = buscarVeiculoPorPlaca(lista_Veiculos, placa_case7);
                if (veiculo)
                    lista_Veiculos = AtenderVeiculo(lista_Veiculos, veiculo);
                else
                    printf("Veiculo não encontrado!");
            }
=======
        case OPCAO3:
            veiculo_imprime_atendidos(lista_Veiculos);
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
            imprime_cliente(clientes);
            printf("Insira o id do cliente que deseja editar:\n");
            scanf("%d", &id_case5);
            limpar_buffer();
            cliente_buscado = busca_cliente(clientes, id_case5);
            clientes = editar_cliente(cliente_buscado, id_case5);
            break;
        case OPCAO6:
            listarVeiculosNaoAtendidos(lista_Veiculos);
            break;
        case OPCAO7:
            listarVeiculosNaoAtendidos(lista_Veiculos);
            printf("Informe a placa do veiculo: ");
            scanf(" %[^\n]", placa_case7);
            limpar_buffer();
            veiculo = buscarVeiculoPorPlaca(veiculo, placa_case7);
            lista_Veiculos = AtenderVeiculo(veiculo);
>>>>>>> main
            break;
        case OPCAO8: // SAIR
            printf("Saindo do programa. Ate logo!\n");
            saida = 1;
            break;
        default:
            printf("Opcao invalida. Tente novamente.\n");
            break;
        }
    } while (!saida);

    salvar_clientes("../data/clientes.txt", "../data/veiculos.txt", clientes, lista_Veiculos);

    free(clientes);
    free(veiculo);
    free(lista_Veiculos);

    return 0;
}