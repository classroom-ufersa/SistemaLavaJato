#ifndef CLIENTE_H
#define CLIENTE_H

#include "../sistema/sistema.h"

struct veiculo; // Declaração avançada da estrutura Veiculo
typedef struct veiculo Veiculo;

typedef struct cliente Cliente;

/* Resto do código de cliente.h */

/* Insere novo cliente em uma lista de clientes de ordenada por nome */
Cliente *add_cliente(Cliente *c, char *nome, char *telefone, int id, Veiculo **todos_veiculo);
/* Exclui cliente de uma lista de clientes */
Cliente *excluir_cliente(Cliente *c, int id);
/* Busca por um cliente em uma lista pelo id */
Cliente *busca_cliente(Cliente *c, int id);
/* Verifica se uma lista de clientes está vazia, retorna 1 se sim */
int lst_cliente_vazia(Cliente *l);
/* Imprime uma lista de clientes */
void imprime_cliente(Cliente *c);
//função que edita as informações do cliente
Cliente *editar_cliente(Cliente *c, int id);
//gera um id aleatorio para cada usuario
int gerarId();
//converte todo nome fornecido pro usuario pra maisculo
void maiusculo(char *s1, char *s2);
//função usada para limpar o buffer caso tenha algum valor lixo
// void limpar_buffer(void);


#endif // CLIENTE_H