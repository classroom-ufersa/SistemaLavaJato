#include "./src/cliente/cliente.c"
#include "./src/veiculo/veiculo.c"

int gerarId() {
    srand(time(NULL)); // Define uma semente com base no tempo atual

    int numeroAleatorio = rand() % 100000000; // Gera um número aleatório de até 8 dígitos

    while (numeroAleatorio < 10000000) {
        numeroAleatorio *= 10; // Garante que o número tenha exatamente 8 dígitos
    }

    return numeroAleatorio;
}

void limpar_buffer(void)
{
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void maiusculo(char *s1, char *s2)
{
    int i = 0;
    while (s1[i] != '\0')
    {
        s2[i] = toupper(s1[i]);
        i++;
    }
    s2[i] = '\0';
}

int main()
{
    Cliente *cliente_buscado = NULL;
    Cliente *clientes = NULL;
    Veiculo *veiculo = NULL;
    Veiculo *lista_Veiculos = NULL;
    int id;
    char escolha;
    char nome[100];
    char tel[15];
    int id_busca;
    char resposta;
    int id_case4;
    int id_case5;
    char placa_case7[12];
    do
    {
        printf("\n=== Menu Lava-Jato ===\n");
        printf("1. Adicionar Cliente\n");
        printf("2. Excluir Cliente\n");
        printf("3. Listar Clientes\n");
        printf("4. Buscar Cliente\n");
        printf("5. Editar Informacoes do Cliente\n");
        printf("6. Consultar Veiculos em Servico\n");
        printf("7. Finalizar atendimento\n");
        printf("8. Sair\n");
        printf("Escolha uma opcao: \n");
        scanf("%c", &escolha);
        limpar_buffer();
        switch (escolha)
        {
        case '1':
            printf("digite o nome do cliente: \n");
            scanf(" %s", &nome);
            limpar_buffer();
            printf("cadastrando :%s\n", nome);
            maiusculo(nome, nome);
            printf("Digite o numero de telefone: \n");
            scanf(" %s", &tel);
            limpar_buffer();
            id = gerarId();
            clientes = add_cliente(clientes, nome, tel, id, &lista_Veiculos);
            break;
        case '2':
            printf("Insira o id do usuario que deseja excluir: \n");
            scanf("%d", &id_busca);
            limpar_buffer();
            cliente_buscado = busca_cliente(clientes, id_busca);
            printf("Deseja excluir o cliente (s / n) \n");
            imprime_cliente(cliente_buscado);
            scanf("%c", &resposta);
            limpar_buffer();
            if (resposta == "s")
            {
                if (cliente_buscado != NULL)
                {
                    clientes = excluir_cliente(clientes, id_busca);
                    printf("Cliente exluido com sucesso !\n ");
                }
                else
                {
                    printf("Nao foi possivel achar o cliente: \n ");
                }
            }
            free(cliente_buscado);
            break;
        case '3':
            imprime_cliente(clientes);
            break;
        case '4':
            printf("Insira o id do cliente que deseja buscar :\n");
            scanf("%d", &id_case4);
            limpar_buffer();
            cliente_buscado = busca_cliente(clientes, id_case4);
            imprime_cliente(clientes);
            free(cliente_buscado);
            break;
        case '5':
            printf("Insira o id do cliente que deseja buscar: \n");
            scanf("%d", &id_case5);
            limpar_buffer();
            cliente_buscado = busca_cliente(clientes, id_case5);
            clientes = editar_cliente(cliente_buscado, id_case5);
            maiusculo(nome, nome);
            break;
        case '6':
            listarVeiculosNaoAtendidos(lista_Veiculos);
            break;
        case '7':
            veiculo_imprime(veiculo);
            printf("Informe a placa do veiculo: ");
            scanf(" %[^\n]", placa_case7);
            limpar_buffer();
            veiculo = buscarVeiculoPorPlaca(veiculo, placa_case7);
            lista_Veiculos = AtenderVeiculo(veiculo);
            break;
        case '8':
            printf("Saindo do programa. Ate logo!\n");
            break;
        default:
            printf("Opção invalida. Tente novamente.\n");
            break;
        }
    } while (escolha != '8');
    free(clientes);
    return 0;
}