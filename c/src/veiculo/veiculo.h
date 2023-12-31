#ifndef VEICULO_H
#define VEICULO_H

#include "../sistema/sistema.h"

struct cliente; // Declaração avançada da estrutura Cliente
typedef struct cliente Cliente;
typedef struct veiculo Veiculo;

//função que cria um veiculo fornecido pelo o usuario e cadastra
Veiculo* criarVeiculo(int id, char* modelo, char* tipo_servico, char* placa, char* marca, char* cor, Cliente* cliente, int atendido);
//função usada pra adicionar o veiculo
Veiculo* adicionarVeiculo(Veiculo *lista, Veiculo *veiculo);
//exibe os veiculos que ainda não foram atendidos 
int listarVeiculosNaoAtendidos(Veiculo *lista);
//busca o veiculo pela a placa
Veiculo *buscarVeiculoPorPlaca(Veiculo *lista, char *placa);
//libera a lista de veiculos
void liberarListaVeiculos(Veiculo* lista);
// verifica se uma lista de veiculo está vazia
int vci_is_empty(Veiculo *v);
// retira um veiculo da lista
Veiculo *vci_retira(Veiculo *v, char *placa);
//exclui o veiculo do cliente
Veiculo *excluir_vci_cliente(Veiculo *v, int id, Cliente* cliente);
//finaliza o atendimento do cliente
<<<<<<< HEAD
Veiculo *AtenderVeiculo(Veiculo *lista_veiculos, Veiculo *v);
=======
Veiculo *AtenderVeiculo(Veiculo *v);
>>>>>>> main
// imprime os campos de uma lista de veiculos atendidos
void veiculo_imprime_atendidos(Veiculo *v);



#endif // VEICULO_H