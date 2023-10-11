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

    printf("Carregando lista de clientes...\n");
    clientes = carregar_clientes("../data/clientes.txt","../data/veiculos.txt", &lista_Veiculos);
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

    salvar_clientes("../data/clientes.txt","../data/veiculos.txt" ,clientes, lista_Veiculos);

    free(clientes);
    free(veiculo);
    free(lista_Veiculos);

    return 0;
}