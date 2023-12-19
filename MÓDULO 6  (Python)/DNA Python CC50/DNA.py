import csv

# Abre o arquivo CSV para leitura
dados = open("DADOS_DNA_CLIENTES.csv", "r")

# Cria um objeto leitor CSV
tabela = csv.reader(dados,delimiter=",")

# Itera sobre as linhas do arquivo e imprime cada linha

txt = open("AMOSTRA_DNA.txt","r")

amostra = txt.read()

aux1 = 0
tatc = 0

n = int(len(amostra))
i = 0

while i < n:
  if amostra [i:i+4]!= "TATC":
    i += 1
  else:
    while amostra[i:i+4]=="TATC":
      aux1 = aux1+1
      i = i+4
    if tatc < aux1:
      tatc = aux1
  aux1 = 0

aux1 = 0
agatc = 0
i = 0

while i < n:
  if amostra [i:i+5]!= "AGATC":
    i += 1
  else:
    while amostra[i:i+5]=="AGATC":
      aux1 = aux1+1
      i = i+5
    if agatc < aux1:
      agatc = aux1
  aux1 = 0

aux1 = 0
aatg = 0
i = 0

while i < n:
  if amostra [i:i+4]!= "AATG":
    i += 1
  else:
    while amostra[i:i+4]=="AATG":
      aux1 = aux1+1
      i = i+4
    if aatg < aux1:
      aatg = aux1
  aux1 = 0

aux2=0

for linha in tabela:
  if aux2>0:
    if agatc == int(linha[1]) and aatg == int(linha[2]) and tatc == int(linha[3]):
      print("\nEssa amostra de dna é de:" +linha[0])
      break
  aux2 += 1
  


# Aguarda a entrada do usuário antes de fechar a janela do console
input("Pressione Enter para continuar...")

dados.close()
txt.close()

