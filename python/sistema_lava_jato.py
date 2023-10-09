class SistemaLavaJato:
    def __init__(self):
        self.clientes = []
        self.veiculos_fila = []
        self.veiculos_atendido = []

    """
        Adiciona novo cliente a lista de clientes
        E adiciona o novo veiculo a fila de veiculos,
        caso o cliente já exista, só será adicionado o veiculo    
    """

    def adiciona_cliente(self, cliente, veiculo):
        if cliente in self.clientes:
            self.veiculos_fila.append(veiculo)
        else:
            self.clientes.append(cliente)
            self.veiculos_fila.append(veiculo)

    def excluir_cliente(self, cliente):
        if cliente in self.clientes:
            self.clientes.remove(cliente)
            print(f'Cliente {cliente.nome} removido da lista.')
            index = 0
            while index < len(self.veiculos_fila):
                veiculo = self.veiculos_fila[index]
                if cliente.id == veiculo.cliente["id"]:
                    self.veiculos_fila.remove(veiculo)
                else:
                    index += 1
            return 1
        print('Cliente não encontrado na lista')
        return 0

    def buscar_cliente(self, id):
        for cliente in self.clientes:
            if cliente.id == id:
                return cliente

    def buscar_nome(self, nome):
        cont = 0
        for cliente in self.clientes:
            if cliente.nome == nome:
                cliente.imprime()
                cont = cont + 1
        if cont != 0:
            return 1
        return None

    def imprimir_clientes(self):
        for cliente in self.clientes:
            cliente.imprime()

    def editar_informacoes(self, id, escolha):
        cliente = self.buscar_cliente(id)
        if cliente:
            if escolha == '1':
                novo_nome = input('Digite o novo nome:')
                cliente.nome = novo_nome
            elif escolha == '2':
                novo_telefone = input('Digite o novo telefone:')
                cliente.telefone = novo_telefone
            elif escolha == '3':
                novo_nome = input('Digite o novo nome:')
                cliente.nome = novo_nome
                novo_telefone = input('Digite o novo telefone:')
                cliente.telefone = novo_telefone
            elif escolha == '4':
                return
            else:
                print('Entrada invalida!')
        else:
            print('Cliente não encontrado!')

    @staticmethod
    def imprime_veiculo(veiculo):
        print(f'Marca: {veiculo.marca}')
        print(f'Modelo: {veiculo.modelo}')
        print(f'Placa: {veiculo.placa}')
        print(f'Cor: {veiculo.cor}')
        print(f'Tipo de Serviço: {veiculo.tipo_servico}')
        print(f'Status: {"Atendido" if veiculo.status == 1 else "Não Atendido"}')
        print(f'Cliente: {veiculo.cliente["nome"]} - {veiculo.cliente["id"]}')
        print()

    def imprime_veiculos_atendidos(self):
        if len(self.veiculos_atendido) == 0:
            print("Nenhum Veiculo atendido!")
            return
        for veiculo in self.veiculos_atendido:
            self.imprime_veiculo(veiculo)

    def imprime_veiculos_servico(self):
        if len(self.veiculos_fila) == 0:
            print("Nenhum Veiculo na fila de atendimento!")
            return
        for veiculo in self.veiculos_fila:
            self.imprime_veiculo(veiculo)

    def atender_veiculo(self):
        if self.veiculos_fila:
            veiculo = self.veiculos_fila.pop(0)
            veiculo.muda_status()
            self.veiculos_atendido.append(veiculo)
            print(f'{veiculo.marca} {veiculo.modelo} atendido!')
            return veiculo
        else:
            print("Nenhum veiculo para ser atendido")
            return None

    def editar_info_cliente(self, cliente, nome, telefone):
        if cliente in self.clientes:
            cliente.nome = nome
            cliente.telefone = telefone
        for veiculo in self.veiculos_fila:
            if cliente == veiculo.cliente:
                cliente.nome = nome
                cliente.telefone = telefone
        for veiculo in self.veiculos_atendido:
            if cliente == veiculo.cliente:
                cliente.nome = nome
                cliente.telefone = telefone

    def ordernar_clientes_por_nome(self):
        self.clientes = sorted(self.clientes, key=lambda cliente: cliente.nome)
