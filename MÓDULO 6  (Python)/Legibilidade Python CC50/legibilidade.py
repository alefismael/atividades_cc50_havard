import string
import os

def calcular_nivel_aluno(texto):
    # Contagem de letras
    letras = sum(c.isalpha() for c in texto)

    # Contagem de palavras
    palavras = len(texto.split())

    # Contagem de frases
    frases = sum(texto.count(p) for p in ['.', '!', '?'])

    # Cálculo de L e S
    L = (letras * 100) / palavras
    S = (frases * 100) / palavras

    # Cálculo do índice
    indice = 0.0588 * L - 0.296 * S - 15.8
    indice_arredondado = round(indice)

    # Determinar o nível do aluno
    if indice_arredondado <= 1:
        return "O nível do aluno pelo texto é: antes do 1º ano."
    elif indice_arredondado >= 16:
        return "O nível do aluno pelo texto é: 16+ anos."
    else:
        return f"O nível do aluno pelo texto é: {indice_arredondado}º ano."

def main():
    print("ESSE PROGRAMA CRIADO PARA DESCOBRIR O NÍVEL DE UM ALUNO PELO TEXTO.")
    texto = input("Informe o texto para a verificação do nível dele ser feita (não pode ter números nele):\n")

    # Verifica se há números no texto
    while any(c.isdigit() for c in texto):
        texto = input("O texto não pode conter números. Informe novamente:\n")

    print(f"\nTexto lido: {texto}")

    resultado = calcular_nivel_aluno(texto)
    print(resultado)

if __name__ == "__main__":
    main()

os.system("PAUSE")