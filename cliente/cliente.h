#ifndef CLIENTE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cliente Cliente;
/* Insere novo cliente em uma lista de clientes de ordenada por nome */
Cliente *add_cliente(Cliente *c, char *nome, char *telefone, int id);
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

#define CLIENTE_H
#endif // CLIENTE_H