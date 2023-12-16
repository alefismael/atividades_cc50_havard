#Projeto de uma escada de Mario feita a pedido do usuário de 1 até 8 de largura

#Pedindo o usuário para informar o número de 1 até 8 da largura

print("Bem vindo ao criador de escadas baseado em Mário.")
print(
    "Por favor, informe o número da largura da escada que você quer criar.Pode ser de 1 até 8."
)
while True:
  larg = int(input("Largura(1 até 8):"))
  if larg > 0 and larg < 9:
    break

print(f"\nA largura é {larg}")
print("Agora, vou mostrar essa escada para você:\n\n")

#Criando a escada

hashtag = 1
espaco = larg - 1

for i in range(larg, 0, -1):
  for j in range(espaco, 0, -1):
    print(" ", end="")
  for k in range(hashtag, 0, -1):
    print("#", end="")

  hashtag += 1
  espaco -= 1
  print()

print("")