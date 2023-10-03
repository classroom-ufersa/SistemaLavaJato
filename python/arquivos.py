import json
from cliente import Cliente
from veiculo import  Veiculo

# Salva os dados do sistema de lavajato em arquivo json
def salvar_dados(sistema_lava_jato, nome_arquivo):
    # dicionario com os atributos do meu sistema de lavajato
    dados={
        "clientes":[cliente.__dict__ for cliente in sistema_lava_jato.clientes],
        "veiculos_fila":[veiculo.__dict__ for veiculo in sistema_lava_jato.veiculos_fila],
        "veiculos_atendido":[veiculo.__dict__ for veiculo in sistema_lava_jato.veiculos_atendido]
    }
    # salvando os dados em um arquivo json
    with open(nome_arquivo, 'w') as arquivo:
        json.dump(dados, arquivo, indent=4)

# Carrega os dados do sistema lavajato empacotados em um arquivo json
def carrega_dados(nome_arquivo):
    try:
        with open(nome_arquivo, 'r') as arquivo:
            dados = json.load(arquivo)
            clientes = [Cliente(**cliente_data) for cliente_data in dados.get("clientes", [])]
            veiculos_fila = [Veiculo(**veiculo_data) for veiculo_data in dados.get("veiculos_fila",[])]
            veiculos_atendido = [Veiculo(**veiculo_data) for veiculo_data in dados.get("veiculos_atendido",[])]
            return clientes, veiculos_fila, veiculos_atendido
    except FileNotFoundError:
        return [], [], []
