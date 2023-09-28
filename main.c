#include "./src/cliente/cliente.c"
#include "./src/veiculo/veiculo.c"

int main()
{
    Cliente *cliente_buscado = NULL;
    Cliente *clientes = NULL;
    int id;
    int escolha;
    char nome[100];
    char tel[15];
    int id_busca;
    char resposta;
    int id_case4;
    int id_case5;
    do
    {
        printf("\n=== Menu Lava-Jato ===\n");
        printf("1. Adicionar Cliente\n");
        printf("2. Excluir Cliente\n");
        printf("3. Listar Clientes\n");
        printf("4. Buscar Cliente\n");
        printf("5. Editar Informacoes do Cliente\n");
        printf("6. Consultar Veiculos em Servico\n");
        printf("7. Sair\n");
        printf("Escolha uma opcao: \n");
        scanf("%d", &escolha);

        switch (escolha)
        {
        case 1:
            printf("digite o nome do cliente: \n");
            scanf(" %s", &nome);
            printf("cadastrando %s\n", nome);
            printf("Digite o numero de telefone: \n");
            scanf(" %s", &tel);
            printf("Digite o id: \n");
            scanf("%d", &id);
            clientes = add_cliente(clientes, nome, tel, id);
            break;
        case 2:
            printf("Insira o id do usuario que deseja excluir: \n");
            scanf("%d", &id_busca);
            cliente_buscado = busca_cliente(clientes, id_busca);
            printf("Deseja excluir o cliente (s / n) \n");
            imprime_cliente(cliente_buscado);
            scanf("%c", &resposta);
            if (resposta == "s")
            {
                if (cliente_buscado != NULL)
                {
                    clientes = excluir_cliente(clientes, id_busca);
                    printf ("Cliente exluido com sucesso !\n ");
                }
                else
                {
                    printf("Nao foi possivel achar o cliente:\n ");
                }
            }
            free (cliente_buscado);
            break;
        case 3:
            imprime_cliente(clientes);
            break;
        case 4:
            printf ("Insira o id do cliente que deseja buscar \n");
            scanf("%d", &id_case4);
            cliente_buscado = busca_cliente(clientes, id_case4);
            imprime_cliente(clientes);
            free (cliente_buscado);
            break;
        case 5:
            printf ("Insira o id do cliente que deseja buscar \n");
            scanf("%d", &id_case5);
            cliente_buscado = busca_cliente(clientes, id_case5);
            clientes = editar_cliente(cliente_buscado, id_case5);
            break;
        case 6:

            break;
        case 7:
            printf("Saindo do programa. Ate logo!\n");
            break;
        default:
            printf("Opção invalida. Tente novamente.\n");
            break;
        }
    } while (escolha != 7);
    free(clientes);
    return 0;
}