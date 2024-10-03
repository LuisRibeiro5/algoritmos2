def calc_media(notas: list,pesos: list) -> float:
    soma_pond = sum(nota * peso for nota,peso in zip(notas,pesos))
    soma_pesos = sum(pesos)

    if soma_pesos == 0:
        raise ValueError("A soma dos pesos nao pode ser 0")

    soma_pond / soma_pesos

def solicitar_dados(lista):
    qtde = int(input("digite quantas notas: "))

    for i in range(qtde):
        peso = float(input("digita o peso: "))
        lista[1].append(peso)

        nota = float(input("digita a nota: "))
        lista[0].append(nota)

        

lista = [[],[]]

solicitar_dados(lista)
calc_media(*lista)
