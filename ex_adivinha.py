from random import randint
secreto = randint(1,20)
num_usu = int(input("digite um numero entre 1 e 20 para adivinhar"))

while(secreto != num_usu):
    if secreto > num_usu:
        print(f"O numero que voce escolheu é menor")
    else:
        print(f"O numero que voce escolheu é maior")
    num_usu = int(input("digite um numero entre 1 e 20 para adivinhar"))
print(f"acertou!")