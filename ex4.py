def menu():
    print("1 - cadastra novo aluno")
    print("2 - mostrar alunos")
    print("3 - media da turma")

def cadastra_aluno(nome: str, nota: float, alunos: dict):
    if nome in alunos:
        resp = input("esse alunos ja foi cadastrado, deseja alterar a nota? S/N")
        if resp.upper() == 'S':
            print("nota mudada...")
            alunos[nome] = nota
        else:
            print("saindo")
            return 
    alunos[nome] = nota

def mostrar_alunos(alunos: dict):
    for aluno,nota in alunos.items():
        print(f"aluno {aluno} - nota {nota}")
    print()

def media_turma(alunos: dict):
    notas = [nota for nota in alunos.values()]
    return sum(notas) / len(notas)

def main():
    alunos = {}

    while True:
        menu()
        opcao = int(input("digite a opcao: 4 para sair "))
        try:
            if opcao < 1 or opcao > 3:
                continue
        except:
            print("erro, digite a opcao corretamente")

        if opcao == "1":
            nome = input("digite o nome do aluno: ")
            while True:
                try:
                    nota = float(input("digite a nota do aluno: "))
                    if nota < 0 or nota > 10:
                        print("nota invalida")
                        continue
                    break
                except:
                    print("nota invalida, corrija")
                break
            cadastra_aluno(nome,nota,alunos)
        elif opcao == "2":
            if len(alunos) == 0:
                print("nenhum aluno cadastrado")
                break
            mostrar_alunos(alunos)
        elif opcao == "3":
            if len(alunos) == 0:
                print("nenhum aluno cadastrado")
                break
            print(f"a media da turma eh {media_turma(alunos)}")
        else:
            print("saindo")
            exit()

