senha = input("digite sua senha:")

eValida = False
while(not eValida):
    eValida = True
    if len(senha) < 8:
        eValida = False
    elif not senha.isupper():
        eValida = False
    elif not senha.isdigit():
        eValida = False
    elif not senha.isalnum():
        eValida = False
    else:
        eValida = True
    senha = input("digite sua senha:")