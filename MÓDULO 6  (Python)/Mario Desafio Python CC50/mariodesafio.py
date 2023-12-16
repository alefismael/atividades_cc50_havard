#Projeto de duas escadas de Mario feita a pedido do usuário de 1 até 8 de largura

#Pedindo o usuário para informar o número de 1 até 8 da largura 

print("Bem vindo ao criador de escadas baseado em Mário.")
print("Por favor, informe o número da largura da escada que você quer criar.Pode ser de 1 até 8.")
larg = int(input())

#While utilizado para garantir que foi digitado um número de 1 à 8, se não foi, ele pede de novo ao usuário.

while((larg>8)or(larg<1)):
  print("Você me informou um número fora do que foi pedido.Por favor, informe o número da largura da escada que você quer criar de 1 até 8.")
  larg = int(input())
    
print("A largura é %d",larg);
print("Agora, vou mostrar essa escada para você:\n\n");

#Criando as duas escadas (Muito Fácil, só modifiquei no crtl c crtl v aqui a maioria das coisa.

hashtag = 1
espaco = larg-1

for lar in range(larg,0,-1):
  for esp in range(espaco,0 ,-1):
    print(" ",end="")
  for hash in range(hashtag,0,-1):
    print("#",end="")
  print("  ",end="")
  for hash in range(hashtag,0,-1):
    print("#",end="")
  hashtag= hashtag+1
  espaco= espaco-1
  print("")
  
print("\n")