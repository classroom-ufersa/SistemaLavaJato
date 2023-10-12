class Cliente:
    def __init__(self, id, nome, telefone):
        self.id = id
        self.nome = nome.upper()
        self.telefone = telefone

    def imprime(self):
        print('ID:', self.id, 'NOME:', self.nome, 'TELEFONE:', self.telefone, sep='\t')
