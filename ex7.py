def ocorrencias(lista:list):
    ocorrencia = {}
    for num in lista:
        ocorrencia[num] = ocorrencia.get(num,0) + 1
    return ocorrencia

def main():
    lista = []
    while True:
        try:
            num = input("digite um num para add (digite fim para sair): ")
            if num.lower() == 'fim':
                break
            lista.append(int(num))
        except:
            print("digite num valido")

    print("menor numero da lista - ", min(lista))
    print("maior numero da lista - ", max(lista))
    print("media da lista - ", sum(lista)/len(lista))

    ocorrencia = ocorrencias(lista)
    for chave,valor in ocorrencia.items():
        print(f"{chave} {valor}")
    print()
    
main()