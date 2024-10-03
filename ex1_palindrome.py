def eh_palindrome(frase):
    return frase == frase[::-1]

frase = input("digite uma frase: ")

if eh_palindrome(frase):
    print("eh palindrome")
else:
    print("nao eh palindrome")