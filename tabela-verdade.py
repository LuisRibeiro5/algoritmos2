print("=======================================")
print(f"a\t| b\t| a and b ")
lista = [True,False]
for i in lista:
    for j in lista:
        print(f"{i}\t | {j} \t| {i and j}")

print("=======================================")
print(f"a\t| b\t| a or b ")
lista = [True,False]
for i in lista:
    for j in lista:
        print(f"{i}\t | {j} \t| {i or j}")

print("=======================================")
print(f"a\t| b\t| a XOR b ")
lista = [True,False]
for i in lista:
    for j in lista:
        print(f"{i}\t | {j} \t| {i ^ j}")