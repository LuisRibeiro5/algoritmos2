def c_to_f(celsius):
    return (celsius * 9/5) + 32

def f_to_c(fahr):
    return round((fahr - 32) * 5/9,1)

def exibe_temps(lista):
    for temp in lista:
        print(temp)

lista = [temp for temp in range(16,33,2)]

qtde = len(lista)

# for i in range(qtde):
#     lista.append(float(input(f"temp {i + 1}")))

for i in range(qtde):
    lista[i] = c_to_f(lista[i])
exibe_temps(lista)
print(end="\n\n\n")
for i in range(qtde):
    lista[i] = f_to_c(lista[i])
exibe_temps(lista)
