def contar_palavras(frase: str):
    palavras = frase.lower().split()
    frequencia = {}
    for palavra in palavras:
        frequencia[palavra] = frequencia.get(palavra,0) + 1

    return frequencia

def mostar_frequencia(dici: dict):
    for chave,valor in dici.items():
        print(f"{chave} - {valor}")
    print()

def main():
    frase = input("digite uma frase: ")
    frequencia = contar_palavras(frase)

    frequencia = dict(sorted(frequencia.items(), key=lambda item : item[1], reverse=True))
    mostar_frequencia(frequencia)

main()