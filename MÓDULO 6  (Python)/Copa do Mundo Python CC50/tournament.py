import csv
import random

# Número de simulações a serem executadas
N = 1000

def main():
    try:
        nome_arquivo = input("Digite o nome do arquivo CSV (por exemplo, 2018m.csv): ")
        print("Lendo times...")
        times = ler_times_do_arquivo(nome_arquivo)
        print("Times lidos com sucesso.")
    except Exception as e:
        print(f"Erro ao ler o arquivo CSV: {e}")
        return

    contagens = simular_n_torneios(times, N)

    # Ordena as equipes de acordo com a probabilidade de vitória
    equipes_ordenadas = sorted(contagens.items(), key=lambda x: x[1], reverse=True)

    # Imprime as chances de cada time ganhar, de acordo com a simulação
    total_simulacoes = sum(contagens.values())

    for time, contagem in equipes_ordenadas:
        chance_vitoria = contagem * 100 / total_simulacoes
        print(f"{time}: {chance_vitoria:.1f}% chance de vitória")

    print("Programa concluído")

def ler_times_do_arquivo(nome_arquivo):
    """Lê os times do arquivo CSV e retorna uma lista de dicionários."""
    times = []
    try:
        with open(nome_arquivo, newline='') as csvfile:
            print(f"Abrindo arquivo CSV '{nome_arquivo}'...")
            reader = csv.DictReader(csvfile)
            for row in reader:
                times.append({"nome": row["team"], "rating": int(row["rating"])})
            print("Arquivo CSV lido com sucesso.")
    except Exception as e:
        print(f"Erro ao ler o arquivo CSV: {e}")
        raise  # Propaga o erro para interromper a execução

    return times

def simular_n_torneios(times, n):
    """Simula N torneios e retorna as contagens de vitórias para cada time."""
    contagens = {time["nome"]: 0 for time in times}
    for _ in range(n):
        vencedor = simular_torneio(times)
        contagens[vencedor["nome"]] += 1
    return contagens

def simular_torneio(times):
    """Simula um torneio eliminatório e retorna o time vencedor."""
    while len(times) > 1:
        times = simular_rodada(times)
    return times[0]

def simular_rodada(times):
    """Simula uma rodada. Retorna uma lista de times vencedores."""
    vencedores = []

    # Simula os jogos para todos os pares de times
    for i in range(0, len(times), 2):
        if simular_jogo(times[i], times[i + 1]):
            vencedores.append(times[i])
        else:
            vencedores.append(times[i + 1])

    return vencedores

def simular_jogo(time1, time2):
    """Simula um jogo. Retorna True se o time1 vencer, False caso contrário."""
    rating1 = time1["rating"]
    rating2 = time2["rating"]
    probabilidade = 1 / (1 + 10 ** ((rating2 - rating1) / 600))
    return random.random() < probabilidade

if __name__ == "__main__":
    main()

print("Pressione Enter para continuar...")
input()  # Aguarda a entrada do usuário