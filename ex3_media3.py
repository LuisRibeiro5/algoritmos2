def calc_media(notas,pesos):
    soma_pond = sum(nota * peso for nota,peso in zip(notas,pesos))
    soma_peso = sum(pesos)

    if soma_peso == 0:
        raise ValueError("soma peso nao pode ser 0")
    
def solicita_dados():
    notas = []
    pesos = []

    while True:
        try:
            nota = input("digite a nota: (para parar -1)")
            if nota == -1:
                break
            peso = input("digite o peso: ")
            pesos.append(float(peso))
            notas.append(float(nota))

        except ValueError:
            print("valor invalido. tente novamente.")

    return notas, pesos

def main():
    notas, pesos = solicita_dados()
    
    try:
        media = calc_media(notas, pesos)
        print(f"a media ponderada eh: {media}")

    except ValueError as e:
        print(e)

if __name__ == "__main__":
    main()