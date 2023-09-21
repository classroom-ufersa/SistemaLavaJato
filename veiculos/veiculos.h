#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../cliente/cliente.h"
typedef cliente Cliente;
typedef Veiculo Veiculo;

Veiculo* criarVeiculo(int id, char* modelo, char* tipo_servico, char* placa, char* marca, char* cor, Cliente* cliente);
Veiculo* adicionarVeiculo(Veiculo *lista, Veiculo *veiculo);
void listarVeiculosNaoAtendidos(Veiculo *lista);
Veiculo* buscarVeiculoPorID(Veiculo *lista, int id);
void liberarListaVeiculos(Veiculo* lista);