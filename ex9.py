def contar_char(string):
    frequencia = {}
    for char  in string:
        frequencia[char] = frequencia.get(char,0) + 1

def main():
    string = input("digite uma string: ")
    string_nova = " ".join(string).split()
    frequencia = contar_char(string_nova)
main()