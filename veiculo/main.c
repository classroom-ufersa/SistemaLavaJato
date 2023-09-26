#include "../cliente/cliente.c"
#include "./veiculo.c"

int main()
{

    Cliente *clientes = NULL;
    int id = 0;
    printf("Cadastrando Felipe\n");
    clientes = add_cliente(clientes, "Felipe", "84996579714", id);
    printf("Cadastrando Abner\n");
    clientes = add_cliente(clientes, "Abner", "84996579714", ++id);
    printf("Cadastrando Whatsapp\n");
    clientes = add_cliente(clientes, "Whatsapp", "84996579714", ++id);
    printf("imprimindo nomes...\n\n");
    imprime_cliente(clientes);

    Cliente* exclui = excluir_cliente(clientes, 1);
    printf("imprimindo nomes...\n\n");
    imprime_cliente(exclui);
    clientes_libera(clientes);

    return 0;
}