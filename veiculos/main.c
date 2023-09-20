#include"veiculos.c"
#include"cliente.c"

int main()
{
    int escolha;

    do
    {
        printf("\n=== Menu Lava-Jato ===\n");
        printf("1. Adicionar Cliente\n");
        printf("2. Excluir Cliente\n");
        printf("3. Listar Clientes\n");
        printf("4. Buscar Cliente\n");
        printf("5. Editar Informacoes do Cliente\n");
        printf("6. Consultar Veículos em Servico\n");
        printf("7. Sair\n");
        printf("Escolha uma opçao: ");
        scanf("%d", &escolha);

        switch (escolha)
        {
        case 1:
            adicionarCliente();
            break;
        case 2:
            excluirCliente();
            break;
        case 3:
            listarClientes();
            break;
        case 4:
            buscarCliente();
            break;
        case 5:
            editarCliente();
            break;
        case 6:
            listarVeiculosAtendidos();
            break;
        case 7:
            printf("Saindo do programa.\n");
            break;
        default:
            printf("Opcao invalida. Tente novamente.\n");
        }

    } while (escolha != 7);

    return 0;
}