#ifndef VEICULO_H
#define VEICULO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cliente; // Declaração avançada da estrutura Cliente
typedef struct cliente Cliente;
typedef struct veiculo Veiculo;

Veiculo* criarVeiculo(int id, char* modelo, char* tipo_servico, char* placa, char* marca, char* cor, Cliente* cliente);
Veiculo* adicionarVeiculo(Veiculo *lista, Veiculo *veiculo);
void listarVeiculosNaoAtendidos(Veiculo *lista);
Veiculo* buscarVeiculoPorID(Veiculo *lista, int id);
void liberarListaVeiculos(Veiculo* lista);
int vci_is_empty(Veiculo *v);
Veiculo *vci_retira(Veiculo *v, char *placa);
Veiculo *excluir_vci_cliente(Veiculo *v, int id, Cliente* cliente);

#endif // VEICULO_H