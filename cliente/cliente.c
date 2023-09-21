#include "cliente.h"
#include "veiculo.c"

struct cliente
{
    char nome[81];
    char telefone[16];
    Veiculo **veiculo;
    struct cliente *prox;
};

Cliente *add_cliente(Cliente *c, char *nome, char *telefone)
{
    Cliente *new_cliente = c;

    new_cliente->veiculo = (Veiculo**) malloc(sizeof(Veiculo*));

    strcpy(new_cliente->nome, nome);
    strcpy(new_cliente->telefone, telefone);

    int adiciona_mais = 1; // 1 true | 0 false
    char num_placa[7];
    char marca[21];
    char cor[10];
    int qtd_veiculos = 0;
    printf("Cadastro de veiculo\n");
    while (adiciona_mais == 1)
    {
        scanf(" 7%[^\n]", num_placa);
        scanf(" 21%[^\n]", marca);
        scanf(" 10%[^\n]", cor);
        new_cliente->veiculo[qtd_veiculos] = cria_veiculo(num_placa, marca, cor, c);
        qtd_veiculos++;
        printf("Deseja cadastrar mais um veiculo?\n");
        char escolha;
        if (getc(escolha) == 's' || getc(escolha) == 'S')
        {
            new_cliente->veiculo = (Veiculo **)realloc(new_cliente->veiculo, ++qtd_veiculos * (sizeof(Veiculo*)));
            scanf(" 7%[^\n]", num_placa);
            scanf(" 21%[^\n]", marca);
            scanf(" 10%[^\n]", cor); 
            new_cliente->veiculo[qtd_veiculos] = cria_veiculo(num_placa, marca, cor, c);
        }
        else
            adiciona_mais = 0;
    }

    return new_cliente;
}

void excluir_cliente(Cliente *c){
    
}