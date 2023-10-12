class Veiculo:
    def __init__(self, marca, modelo, placa, cor, tipo_servico, cliente, status=None):
        self.marca = marca.upper()
        self.modelo = modelo.upper()
        self.placa = placa.upper()
        self.cor = cor.upper()
        self.tipo_servico = tipo_servico.upper()
        self.status = 0  # Inicialmente não atendido
        self.cliente = cliente
        self.status = status
        # print(self.marca, self.modelo, 'adicionado a fila com sucesso!', sep=' ')

    # Atende o veiculo
    def muda_status(self):
        self.status = 1
