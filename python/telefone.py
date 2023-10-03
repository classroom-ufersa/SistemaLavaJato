import re


class Telefone:
    def __init__(self, telefone):
        # Remova quaisquer caracteres não numéricos da entrada
        telefone = re.sub(r'\D', '', telefone)

        if self.validacao_telefone(telefone):
            self.telefone = telefone
        else:
            raise ValueError('Telefone INVÁLIDO!')

    def __str__(self):
        return self.telefone_formatado()

    # def to_json(self):
    #     return {"telefone": self.telefone}


    @staticmethod
    def validacao_telefone(telefone):
        # Verifica se o número de telefone tem pelo menos 10 dígitos (incluindo o DDD)
        return len(telefone) >= 10

    def telefone_formatado(self):
        # Formata o número de telefone com código de área (DDD)
        ddd = self.telefone[0:2]
        numero = self.telefone[2:8]
        parte_final = self.telefone[7:12]
        return f"+55 ({ddd}) {numero}-{parte_final}"


if __name__ == "__main__":
    while True:
        try:
            telefone1 = Telefone(input('Informe o numero: '))
            print(telefone1)  # Saída: +55 (11) 23456-789

        except ValueError as e:
            print(e)
