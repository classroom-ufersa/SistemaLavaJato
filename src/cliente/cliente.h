#ifndef CLIENTE_H
#define CLIENTE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
/* Libera uma lista de cliente da memoria */
void clientes_libera(Cliente *c);
//função que edita as informações do cliente
Cliente *editar_cliente(Cliente *c, int id);

#endif // CLIENTE_H