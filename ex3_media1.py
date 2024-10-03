def solicita_dados(lista):
    nota = float(input("dite a nota: "))
    nota = nota if nota >= 0 else 0
    peso = int(input("digite o peso"))
    peso = peso if peso >= 1 else 1

    note = {
        "nota": nota,
        "peso": peso
    }
    lista.append(note)

def calcular_media_pond(lista):
    soma_nota = 0
    soma_peso = 0
    for dici in lista:
        for nota,peso in dici.items():
            soma_nota += nota
            soma_peso += peso

    return soma_nota / soma_peso

lista = []
qtde = int(input("quantas notas serao inseridas: "))
qtde = qtde if qtde > 0 else 1

for i in range(qtde):
    solicita_dados(lista)

media = calcular_media_pond(lista)
