#ifndef SISTEMA_H
#define SISTEMA_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

#define TITULO_OPCAO1 "Adicionar cliente"
#define TITULO_OPCAO2 "Excluir cliente"
#define TITULO_OPCAO3 "Listar veiculos atendidos"
#define TITULO_OPCAO4 "Buscar cliente"
#define TITULO_OPCAO5 "Editar informações de cliente"
#define TITULO_OPCAO6 "Consultar veiculos em serviço"
#define TITULO_OPCAO7 "Finalizar atendimento"
#define TITULO_OPCAO8 "Sair"

#define TITULO_SERVICO_OPCAO1 "Lavagem simples"
#define TITULO_SERVICO_OPCAO2 "Lavagem com enceramento"
#define TITULO_SERVICO_OPCAO3 "Polimento"
#define TITULO_SERVICO_OPCAO4 "Higienizacao de ar-condicionado"
#define TITULO_SERVICO_OPCAO5 "Higienizacao interna"
#define TITULO_SERVICO_OPCAO6 "Limpeza e hidratacao de couro"

#define N_OPCOES 8
#define OPCAO1 '1'
#define OPCAO2 '2'
#define OPCAO3 '3'
#define OPCAO4 '4'
#define OPCAO5 '5'
#define OPCAO6 '6'
#define OPCAO7 '7'
#define OPCAO8 '8'

void limpar_buffer(void);

int le_opcao(int menor_valor, int maior_valor);

void le_nome(char *nome, int tamanho_max);

void apresenta_menu(int n_itens, int menor_opcao, ...);

void corrige_nome(char *nome);

int gerar_id();

void le_telefone(char *telefone, int tamanho_max);

void formatar_telefone(const char *telefone);

#endif // SISTEMA_H