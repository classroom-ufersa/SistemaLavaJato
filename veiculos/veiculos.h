#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct veiculos Veiculos;

Veiculo* adicionarVeiculo(char *modelo, char *tipo_servico, char *placa, char *marca, char *cor, Cliente *cliente);
void listarVeiculosAtendidos();
void consultarVeiculosAtendidos(Veiculos* veiculos, int n);