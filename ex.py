nomes = []
notas = []
qtde = 0

while(qtde < 3):
    qtde = int(input("digite quantos alunos deseja add:"))
   
        

for _ in range(qtde):
    nomes.append(input("Nome:"))
    notas.append(float(input("Nota:")))

aprovacao = []

for nota in notas:
    if nota >= 7:
        aprovacao.append("aprovado")
    elif notas >= 3:
        aprovacao.append("recuperacao")
    else:
        aprovacao.append("reprovado")

for nome,situacao in zip(nomes,aprovacao):
    print(f"Nome:{nome}, Situacao:{situacao}")
    
todos_aprovados = all(aluno == 'aprovado' for aluno in aprovacao)
algum_recuperacao = any(aluno == 'recuperacao' for aluno in aprovacao)
print(f"resumo da turma")
print(f"Todos estao aprovados? {'sim' if todos_aprovados else 'nao'}")
print(f"Ha pelo menos um em recuperacao? {'sim' if algum_recuperacao else 'nao'}")
