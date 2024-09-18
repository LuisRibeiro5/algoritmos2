notas = [5.5, 8.0, 6.5, 9.0, 4.0]
status = ["Aprovado" if nota >= 7 else "Reprovado" for nota in notas]
print(status)
