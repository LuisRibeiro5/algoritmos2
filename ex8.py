def media_turma(dici:dict):
    notas = [nota for nota in dici.values()]
    return sum(notas)/len(notas)

def mostar_aprovados(dici:dict):
    for aluno,nota in dici.items():
        if nota >= 7:
            print(f"{aluno} - {nota}")

def adicionar_nota(dici:dict, aluno:str, nota:float):
    if aluno in dici:
        resp = input("aluno ja esta registrado deseja alterar a nota: S/N")
        if resp.upper() == "N":
            return
    dici[aluno] = nota

def main():
    alunos = {}
    while True:
        resp = input("deseja add mais um aluno: S/N")    
        if resp.upper() == "N":
            break

        nome = input("nome: ")
        while True:
            try:
                nota = float(input("nota: "))
                if nota < 0 or nota > 10:
                    print("nota invalida")
                    continue
                break
            except:
                print("nota invalida")

        adicionar_nota(alunos,nome,nota)
    
    mostar_aprovados(alunos)
    print(media_turma(alunos))