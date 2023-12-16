#PROGRAMA CRIADO PARA VERIFICAR SE UM NÚMERO DE CARTÃO É VÁLIDO.(mais informações no bloco de notas da pasta do programa)

#INCLUINDO BIBLIOTECAS*

import sys
import os

# sys.exit()


#CHAMANDO FUNÇÕES

def luhn_algorithm(card_number):
    card_digits = [int(digit) for digit in card_number[::-1]]
    
    for i in range(1, len(card_digits), 2):
        card_digits[i] *= 2
        if card_digits[i] > 9:
            card_digits[i] -= 9
    
    total = sum(card_digits)
    return total % 10 == 0


def validar_cartao():
  global cartao
  
  cartao= cartao.replace(" ","").replace("-","")
  if not cartao.isdigit():
    return False

  if not (13 <= len(cartao)<=16):
    return False
  
  return luhn_algorithm(cartao)

def banco_cartao(cartao):
  
  if (cartao.startswith("4") and (len(cartao)==13 or len(cartao)==16)):
    return "VISA"
  
  elif ((cartao.startswith("34") or cartao.startswith("37")) and len(cartao)==15):
    return "AMERICAN EXPRESS"
  
  elif ((cartao.startswith("51") or cartao.startswith("52") or cartao.startswith("53") or cartao.startswith("54") or cartao.startswith("55")) and len(cartao)==16):
    return "MASTERCARD"
  
  return "DE UM BANCO DESCONHECIDO"


#AQUI COMEÇA O CÓDIGO PRINCIPAL, FIZ ELE COM O PRÓPOSITO PRINCIPAL DE FUNCIONAR, SEI QUE OUTRO MÉTODOS TALVEZ SERIAM MAIS SIMPLES, MAS COMO SOU NOVO NA ÁREA, FUNCINANDO CONSIDERO BOM

#PRIMEIRO VOU INFORMAR O USUÁRIO SOBRE A FUNCÃO DO PROGRAMA, E DEPOIS PEDIR ELE PARA INFORMAR O NÚMERO DO CARTÃO, E FAZER UM FILTRO ANTI CARACTERE

print("\n  SEJA BEM VINDO AO VERIFICADOR DE CARTÃO.")

print("\n  VOCÊ DESCOBRIRÁ EM BREVE INFORMAÇÕES DO SE CARTÃO.")

cartao = input("\nPOR FAVOR, INFORME O NÚMERO DO SEU CARTÃO DE CRÉDITO: ")  #AQUI ESTÁ A VARÍAVEL QUE FILTRA SE NÃO FOI DIGITADO UM CARACTERE//

if validar_cartao():
    banco = banco_cartao(cartao)
    print(f"O CARTAO {banco} É VÁLIDO")
else:
   print("CARTÃO INVÁLIDO")

os.system("PAUSE")