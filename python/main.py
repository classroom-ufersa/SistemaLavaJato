from cliente import Cliente
from veiculo import Veiculo
from sistema_lava_jato import SistemaLavaJato
from telefone import Telefone
from arquivos import *
import random
import re


def menu():
    print("\nMenu:")
    print("1. Adicionar cliente")
    print("2. Excluir cliente")
    print("3. Listar veículos atendidos")
    print("4. Buscar cliente")
    print("5. Editar informações de cliente")
    print("6. Consultar veículos")
    print("7. Sair")

    return input('Digite uma ação: ')


def menu_services():
    while True:
        print('Escolha uma opção:')
        print('1 - Lavagem simples')
        print('2 - Lavagem com enceramento')
        print('3 - Polimento')
        print('4 - Higienização de ar-condicionado')
        print('5 - Higienização interna')
        print('6 - Limpeza e hidratação de couro')

        escolha = input()
        tipo_servico = '0'
        if escolha == '1':
            tipo_servico = 'Lavagem simples'
            return tipo_servico
        elif escolha == '2':
            tipo_servico = 'Lavagem com enceramento'
            return tipo_servico
        elif escolha == '3':
            tipo_servico = 'Polimento'
            return tipo_servico
        elif escolha == '4':
            tipo_servico = 'Higienizacao de ar-condicionado'
            return tipo_servico
        elif escolha == '5':
            tipo_servico = 'Higienizacao interna'
            return tipo_servico
        elif escolha == '6':
            tipo_servico = 'Limpeza e hidratacao de couro'
            return tipo_servico
        else:
            print('Entrada Invalida')


def gerar_id():
    id_aleatorio = ''.join([str(random.randint(0, 9)) for _ in range(8)])
    return id_aleatorio

def menu_editar_info():
    print('Qual informação será editada:')
    print('1 - Nome')
    print('2 - Telefone')
    print('3 - Ambos')
    print('4 - Cancelar acão')
    return input()

def menu_veiculos_atendimento():
    print('Gerenciamento de veiculos')
    print('1 - Serviço do veiculo no começo da fila concluido')
    print('2 - Retornar ao  menu principal')
    return input()

# teste
if __name__ == '__main__':
    # carrega os dados empacotados em um arquivo json
    clientes, veiculos_fila, veiculos_atendido = carrega_dados('data.json')
    # Cria instancia do sistema
    sistema = SistemaLavaJato()
    # inicializa os campos do sistema com os dados extraidos do dataset
    sistema.clientes = clientes
    sistema.veiculos_fila = veiculos_fila
    sistema.veiculos_atendido = veiculos_atendido
    new_cliente = None
    new_veiculo = None

    nome = '0'
    telefone = 'A'
    marca = '0'
    modelo = '0'
    placa = '0'
    cor = '0'
    tipo_servico = '0'
    telefone_formatado = None
    while True:
        escolha = menu()

        if escolha == '1':  # Adicionar cliente
            while True:
                try:
                    nome = input('Digite o nome do cliente: ')
                    if re.search(r'[0-9!@#$%^&*(),.?":{}|<>]', nome):
                        raise ValueError('Nome não deve conter números ou caracteres especiais. Entrada invalida.')
                    break
                except ValueError as error:
                    print(error)
            while True:
                try:
                    telefone = input('Digite o telefone do cliente (xx) 9xxxx-xxxx: ')
                    telefone_formatado = Telefone(telefone)
                    break
                except ValueError as error:
                    print(error)
            print('Cadastrando cliente...')
            new_cliente = Cliente(gerar_id(), nome, telefone_formatado.telefone_formatado())
            while True:
                print('Adicionando veiculo...')
                marca = input('Digite a marca: ')
                modelo = input('Digite o modeelo: ')
                placa = input('Digite a placa: ')
                cor = input('Digite a cor: ')
                tipo_servico = menu_services()
                new_veiculo = Veiculo(marca, modelo, placa, cor, tipo_servico, vars(new_cliente))
                mais_um_veiculo = input("Digite 'S' adicionar mais um veiculo, ou digite qualquer"
                                        " outra tecla para voltar ao menu principal:")
                sistema.adiciona_cliente(new_cliente, new_veiculo)
                if mais_um_veiculo.upper() != 'S':
                    print('Retornando ao menu principal...', '\n')
                    break
        elif escolha == '2':  # Excluir cliente
            if len(sistema.clientes) > 0:
                sistema.imprimir_clientes()
                id = input("Informe o ID do cliente a ser excluido ou digite 'q' para retornar ao menu principal:")
                if id.upper() != 'Q':
                    cliente_excluir = sistema.buscar_cliente(id)
                    if cliente_excluir:
                        while True:
                            confirme = input(f'Deseja mesmo excluir o cliente {nome.upper()}?(S/N) ')
                            if confirme.upper() == 'S':
                                sistema.excluir_cliente(cliente_excluir)
                                break
                            elif confirme.upper() == 'N':
                                print('Retornando ao menu principal...')
                                break
                    else:
                        print('Cliente não encontrado!')
                else:
                    print('Retornando ao menu principal...')
            else:
                print('Lista de clientes vazia!')
        elif escolha == '3':  # Listar veículos atendidos
            sistema.imprime_veiculos_atendidos()
        elif escolha == '4': # Buscar cliente
            nome = input('Infome o nome do cliente a ser buscado: ')
            cliente_buscar = sistema.buscar_nome(nome.upper())
            if cliente_buscar:
                print('Cliente encontrado!', 'Dados:', sep='\n')
                cliente_buscar.imprime()
            else:
                print('Cliente não encontrado no bando de dados!')
        elif escolha == '5':  # Editar informações de cliente
            sistema.imprimir_clientes()
            id = input('Informe o id do cliente que terá suas informações editadas:')
            cliente_buscar = sistema.buscar_cliente(id)
            if cliente_buscar:
                print('Cliente encontrado!', 'Dados:', sep='\n')
                cliente_buscar.imprime()
                while True:
                    qual_informacao = menu_editar_info()
                    if qual_informacao == '1':
                        nome_editar = input('Informe o novo nome:')
                        sistema.editar_info_cliente(cliente_buscar, nome_editar.upper(), cliente_buscar.telefone)
                        print('Nome alterado com sucesso!')
                    elif qual_informacao == '2':
                        telefone_editar = input('Informe o novo número de telefone:')
                        sistema.editar_info_cliente(cliente_buscar, cliente_buscar.nome, telefone_editar)
                        print('Número alterado com sucesso!')
                    elif qual_informacao == '3':
                        nome_editar = input('Informe o novo nome:')
                        telefone_editar = input('Informe o novo número de telefone:')
                        sistema.editar_info_cliente(cliente_buscar, nome_editar.upper(), telefone_editar)
                        print('Dados alterados com sucesso!')
                    elif qual_informacao == '4':
                        print('Voltando...')
                        break
                    else:
                        raise ValueError('Opção escolhida é inválida!!')
            else:
                print('Cliente não encontrado no bando de dados!')
        elif escolha == '6': # Consultar veículos
            while True:
                print("Veiculos em serviço:")
                sistema.imprime_veiculos_servico()
                consulta = menu_veiculos_atendimento()
                if consulta == '1':
                    veiculo_atendido = sistema.atender_veiculo()
                    break
                elif consulta == '2':
                    print('retornando ao menu principal...')
                    break
                else:
                    raise ValueError('Opção escolhida é inválida!!')
        elif escolha == '7': # Sair
            print('saindo...')
            break
        else:
            raise ValueError('Opção escolhida é inválida!!')

    salvar_dados(sistema, 'data.json')

