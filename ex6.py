def menu():
    print("1 - add item")
    print("2 - del item")
    print("3 - mostra lista")
    print()

def add(lista: dict, item: str, qtde: int):
    if item in lista:
        resp = input("item ja esta na lista, deseja acrescentar qtde dele: S/N")
        if resp.upper() == "S":
            lista[item] += qtde
        else:
            lista[item] = qtde
    lista[item] = qtde

def delete(lista: dict, item: str):
    if item in lista:
        del lista[item]
    else:
        print("item nao encontrado.")

def mostrar_lista(lista):
    for chave,valor in lista.items():
        print(f"{chave} {valor}")
    print()

def main():
    lista = {}
    while True:
        menu()
        opcao = input("digite a opcao(4 para sair)")
        if opcao < 1 or opcao > 3:
            print("opcao invalida")
            continue

        if opcao == "1":
            item = input("digite o nome do item: ")
            while True:
                try:
                    qtde = int(input("digite a qtde de itens: "))
                    if item > 0:
                        print("item add...")
                        break
                    print("qtde invalida")
                    continue
                except:
                    print("qtde invalida")
                
            add(lista,item,qtde)
        
        elif opcao == "2":
            item = input("digite o item que qeur deletar: ")
            delete(lista,item)
        elif opcao == "3":
            mostrar_lista(lista)
        else:
            exit()