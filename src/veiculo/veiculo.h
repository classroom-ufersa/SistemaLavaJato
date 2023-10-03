#ifndef VEICULO_H
#define VEICULO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cliente; // Declaração avançada da estrutura Cliente
typedef struct cliente Cliente;
typedef struct veiculo Veiculo;

//função que cria um veiculo fornecido pelo o usuario e cadastra
Veiculo* criarVeiculo(int id, char* modelo, char* tipo_servico, char* placa, char* marca, char* cor, Cliente* cliente);
//função usada pra adicionar o veiculo
Veiculo* adicionarVeiculo(Veiculo *lista, Veiculo *veiculo);
//exibe os veiculos que ainda não foram atendidos 
void listarVeiculosNaoAtendidos(Veiculo *lista);
//busca o veiculo pela a placa
Veiculo *buscarVeiculoPorPlaca(Veiculo *lista, char placa);
//libera a lista de veiculos
void liberarListaVeiculos(Veiculo* lista);

int vci_is_empty(Veiculo *v);

Veiculo *vci_retira(Veiculo *v, char *placa);
//exclui o veiculo do cliente
Veiculo *excluir_vci_cliente(Veiculo *v, int id, Cliente* cliente);
//finaliza o atendimento do cliente
Veiculo *AtenderVeiculo(Veiculo *v);


#endif // VEICULO_H