#include "./src/cliente/cliente.c"
#include "./src/veiculo/veiculo.c"


int main() {
    Cliente *clientes = NULL;
    int id = 0;
    int escolha;
    char nome[100];
    char tel[15];
    do {
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

        switch (escolha) {
            case 1:
                printf ("digite o nome do cliente \n");
                scanf ("%s", &nome);
                printf ("cadastrando %s\n", nome);
                printf ("Digite o numero de telefone\n");
                scanf ("%s", &tel);
                printf ("Digite o id\n");
                scanf ("%d", &id);
                clientes = add_cliente(clientes, nome, &tel, id);
                break;
            case 2:
                 clientes = excluir_cliente(clientes, 1);
                break;
            case 3:
                imprime_cliente(clientes);
                break;
            case 4:
               
                break;
            case 5:
                
                break;
            case 6:
                
                break;
            case 7:
                printf("Saindo do programa. Até logo!\n");
                break;
            default:
                printf("Opção invalida. Tente novamente.\n");
                break;
        }
    } while (escolha != 7);

    return 0;
}