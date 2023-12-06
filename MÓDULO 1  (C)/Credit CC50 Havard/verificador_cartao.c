/*PROGRAMA CRIADO PARA VERIFICAR SE UM NÚMERO DE CARTÃO É VÁLIDO.(mais informações no bloco de notas da pasta do programa)*/

/*INCLUINDO BIBLIOTECAS*/

#include <stdio.h>
#include <math.h>
#include <locale.h>

/*CHAMANDO FUNÇÃO MAIN PARA INICIAR O PROGRAMA*/

int main(void)

{
/*ESSE SET LOCALE É PARA DEIXAR CORRETO A CONVERSÃO DO PROGRAMA PARA PORTUGUÊS COM SEUS RESPECTIVOS SIMBOLOS*/

setlocale(LC_ALL, "Portuguese_Brazil");

/*AQUI COMEÇA O CÓDIGO PRINCIPAL, FIZ ELE COM O PRÓPOSITO PRINCIPAL DE FUNCIONAR, SEI QUE OUTRO MÉTODOS TALVEZ SERIAM MAIS SIMPLES, MAS COMO SOU NOVO NA ÁREA, FUNCINANDO CONSIDERO BOM*/

/*PRIMEIRO VOU INFORMAR O USUÁRIO SOBRE A FUNCÃO DO PROGRAMA, E DEPOIS PEDIR ELE PARA INFORMAR O NÚMERO DO CARTÃO, E FAZER UM FILTRO ANTI CARACTERE*/

printf("\n  SEJA BEM VINDO AO VERIFICADOR DE CARTÃO.\n");

printf("\n  VOCÊ DESCOBRIRÁ EM BREVE INFORMAÇÕES DO SE CARTÃO.\n");

printf("\nPOR FAVOR, INFORME O NÚMERO DO SEU CARTÃO DE CRÉDITO:\n");

long long cartao;  //AQUI ESTÁ A VARÍAVEL QUE GUARDARÁ O NÚMERO DO CARTÃO//
long long copiacartao;  //VARÍAVEL CÓPIA DO NÚMERO DO CARTÃO//
int digitoinicial;    //ESTÁ É A VARÍAVEL QUE GUARDA OS 2 PRIMEIROS NÚMEROS DO CARTÃO//
int validadordigito=2;  //ESSA É A VARIÁVEL DE VALIDAÇÃO, O NÚMERO SÓ SERÁ VÁLIDO SE ELA VALER 1//
int n1,n2,n3,n4,n5,n6,n7,n8,n9,n10,n11,n12,n13,n14,n15,n16;    //VARIÁVEIS PARA AMAZENAR OS NÚMEROS DO CARTÃO SEPARADAMENTE//
int cartaovisa=0,cartaoamerican=0,cartaomastercard=0;
int filtro = scanf("%lld",&cartao);  //AQUI ESTÁ A VARÍAVEL QUE FILTRA SE NÃO FOI DIGITADO UM CARACTERE//
while (getchar() != '\n');
copiacartao = cartao;

do
{
    if (validadordigito == 0)
    {
      printf("\nNúmero do cartão inválido, informe outro número para consulta ou digite 0 para fechar o programa:\n");
      filtro = scanf("%lld",&cartao);
      while (getchar() != '\n');
      copiacartao = cartao;

      if ((filtro==1)&&(cartao==0))
        return(0);
 
    }
    
       //SE CARTÃO TEM 13 DIGÍTOS//

    if ((10000000000000>cartao)&&(cartao>999999999999)&&(filtro=1))  
    {
        //AQUI VOU PEGAR A INFORMAÇÃO DO PRIMEIRO DÍGITO DO NÚMERO SE ELE FOR VÁLIDO.//

        digitoinicial = cartao / 1000000000000;
        
        //SE DIGITO INICIAL IGUAL A 4//

        if (digitoinicial==4)
        {

           n1 = copiacartao%10;
           copiacartao = copiacartao/10;
           n2 = copiacartao%10;
           copiacartao = copiacartao/10;
           n3 = copiacartao%10;
           copiacartao = copiacartao/10;
           n4 = copiacartao%10;
           copiacartao = copiacartao/10;
           n5 = copiacartao%10;
           copiacartao = copiacartao/10;
           n6 = copiacartao%10;
           copiacartao = copiacartao/10;
           n7 = copiacartao%10;
           copiacartao = copiacartao/10;
           n8 = copiacartao%10;
           copiacartao = copiacartao/10;
           n9 = copiacartao%10;
           copiacartao = copiacartao/10;
           n10 = copiacartao%10;
           copiacartao = copiacartao/10;
           n11 = copiacartao%10;
           copiacartao = copiacartao/10;
           n12 = copiacartao%10;
           copiacartao = copiacartao/10;
           n13 = copiacartao%10;

          n2 = n2*2;
          n4 = n4*2;
          n6 = n6*2;
          n8 = n8*2;
          n10 = n10*2;
          n12 = n12*2;

          if (n2>9)
          {
            int n21 = n2%10;
            n2 = n2 / 10;
            int n22 = n2%10;
            n2 = n21 + n22;
          }

          if (n4>9)
          {
            int n41 = n4%10;
            n4 = n4 / 10;
            int n42 = n4%100;
            n4 = n41 + n42;
          }

          if (n6>9)
          {
            int n61 = n6%10;
            n6 = n6 / 10;
            int n62 = n6%100;
            n6 = n61 + n62;
          }

          if (n8>9)
          {
            int n81 = n8%10;
            n8 = n8 / 10;
            int n82 = n8%100;
            n8 = n81 + n82;
          }

          if (n10>9)
          {
            int n101 = n10%10;
            n10 = n10 / 10;
            int n102 = n10%100;
            n10 = n101 + n102;
          }

          if (n12>9)
          {
            int n121 = n12%10;
            n12 = n12 / 10;
            int n122 = n12%100;
            n12 = n121 + n122;
          }
          
          int resultado = n1+n2+n3+n4+n5+n6+n7+n8+n9+n10+n11+n12+n13;

          resultado = resultado%10;

          if (resultado == 0)
          {
            cartaovisa = 1;
            validadordigito = 1;
          }
          

        }
        

    }


    //SE CARTÃO TEM 15 DIGÍTOS//

    if ((1000000000000000>cartao)&&(cartao>99999999999999)&&(filtro=1))  
    {
        //AQUI VOU PEGAR A INFORMAÇÃO DOS DOIS PRIMEIROS DÍGITOS DO NÚMERO SE ELE FOR VÁLIDO.//

        digitoinicial = cartao / 10000000000000;
        
        //SE DIGITO INICIAL IGUAL A 34 OU 37//

        if ((digitoinicial==34) || (digitoinicial==37))
        {

           n1 = copiacartao%10;
           copiacartao = copiacartao/10;
           n2 = copiacartao%10;
           copiacartao = copiacartao/10;
           n3 = copiacartao%10;
           copiacartao = copiacartao/10;
           n4 = copiacartao%10;
           copiacartao = copiacartao/10;
           n5 = copiacartao%10;
           copiacartao = copiacartao/10;
           n6 = copiacartao%10;
           copiacartao = copiacartao/10;
           n7 = copiacartao%10;
           copiacartao = copiacartao/10;
           n8 = copiacartao%10;
           copiacartao = copiacartao/10;
           n9 = copiacartao%10;
           copiacartao = copiacartao/10;
           n10 = copiacartao%10;
           copiacartao = copiacartao/10;
           n11 = copiacartao%10;
           copiacartao = copiacartao/10;
           n12 = copiacartao%10;
           copiacartao = copiacartao/10;
           n13 = copiacartao%10;
           copiacartao = copiacartao/10;
           n14 = copiacartao%10;
           copiacartao = copiacartao/10;
           n15 = copiacartao%10;

          n2 = n2*2;
          n4 = n4*2;
          n6 = n6*2;
          n8 = n8*2;
          n10 = n10*2;
          n12 = n12*2;
          n14 = n14*2;

          if (n2>9)
          {
            int n21 = n2%10;
            n2 = n2 / 10;
            int n22 = n2%10;
            n2 = n21 + n22;
          }

          if (n4>9)
          {
            int n41 = n4%10;
            n4 = n4 / 10;
            int n42 = n4%100;
            n4 = n41 + n42;
          }

          if (n6>9)
          {
            int n61 = n6%10;
            n6 = n6 / 10;
            int n62 = n6%100;
            n6 = n61 + n62;
          }

          if (n8>9)
          {
            int n81 = n8%10;
            n8 = n8 / 10;
            int n82 = n8%100;
            n8 = n81 + n82;
          }

          if (n10>9)
          {
            int n101 = n10%10;
            n10 = n10 / 10;
            int n102 = n10%100;
            n10 = n101 + n102;
          }

          if (n12>9)
          {
            int n121 = n12%10;
            n12 = n12 / 10;
            int n122 = n12%100;
            n12 = n121 + n122;
          }

          if (n14>9)
          {
            int n141 = n14%10;
            n14 = n14 / 10;
            int n142 = n14%100;
            n14 = n141 + n142;
          }
          
          int resultado = n1+n2+n3+n4+n5+n6+n7+n8+n9+n10+n11+n12+n13+n14+n15;

          resultado = resultado%10;

          if (resultado == 0)
          {
            cartaoamerican = 1;
            validadordigito = 1;
          }
          

        }
        

    }

     //SE CARTÃO TEM 16 DIGÍTOS//

    if ((10000000000000000>cartao)&&(cartao>999999999999999)&&(filtro=1))  
    {
        //AQUI VOU PEGAR A INFORMAÇÃO DOS DOIS PRIMEIROS DÍGITOS DO NÚMERO SE ELE FOR VÁLIDO.//

        digitoinicial = cartao / 100000000000000;
        
        //SE DIGITO INICIAL IGUAL A 51,52,53,54 OU 55//

        if ((digitoinicial==51) || (digitoinicial==52) || (digitoinicial==53) || (digitoinicial==54) || (digitoinicial==55))
        {

           n1 = copiacartao%10;
           copiacartao = copiacartao/10;
           n2 = copiacartao%10;
           copiacartao = copiacartao/10;
           n3 = copiacartao%10;
           copiacartao = copiacartao/10;
           n4 = copiacartao%10;
           copiacartao = copiacartao/10;
           n5 = copiacartao%10;
           copiacartao = copiacartao/10;
           n6 = copiacartao%10;
           copiacartao = copiacartao/10;
           n7 = copiacartao%10;
           copiacartao = copiacartao/10;
           n8 = copiacartao%10;
           copiacartao = copiacartao/10;
           n9 = copiacartao%10;
           copiacartao = copiacartao/10;
           n10 = copiacartao%10;
           copiacartao = copiacartao/10;
           n11 = copiacartao%10;
           copiacartao = copiacartao/10;
           n12 = copiacartao%10;
           copiacartao = copiacartao/10;
           n13 = copiacartao%10;
           copiacartao = copiacartao/10;
           n14 = copiacartao%10;
           copiacartao = copiacartao/10;
           n15 = copiacartao%10;
           copiacartao = copiacartao/10;
           n16 = copiacartao%10;

          n2 = n2*2;
          n4 = n4*2;
          n6 = n6*2;
          n8 = n8*2;
          n10 = n10*2;
          n12 = n12*2;
          n14 = n14*2;
          n16 = n16*2;

          if (n2>9)
          {
            int n21 = n2%10;
            n2 = n2 / 10;
            int n22 = n2%10;
            n2 = n21 + n22;
          }

          if (n4>9)
          {
            int n41 = n4%10;
            n4 = n4 / 10;
            int n42 = n4%100;
            n4 = n41 + n42;
          }

          if (n6>9)
          {
            int n61 = n6%10;
            n6 = n6 / 10;
            int n62 = n6%100;
            n6 = n61 + n62;
          }

          if (n8>9)
          {
            int n81 = n8%10;
            n8 = n8 / 10;
            int n82 = n8%100;
            n8 = n81 + n82;
          }

          if (n10>9)
          {
            int n101 = n10%10;
            n10 = n10 / 10;
            int n102 = n10%100;
            n10 = n101 + n102;
          }

          if (n12>9)
          {
            int n121 = n12%10;
            n12 = n12 / 10;
            int n122 = n12%100;
            n12 = n121 + n122;
          }

          if (n14>9)
          {
            int n141 = n14%10;
            n14 = n14 / 10;
            int n142 = n14%100;
            n14 = n141 + n142;
          }

          if (n16>9)
          {
            int n161 = n16%10;
            n16 = n16 / 10;
            int n162 = n16%100;
            n16 = n161 + n162;
          }
          
          int resultado = n1+n2+n3+n4+n5+n6+n7+n8+n9+n10+n11+n12+n13+n14+n15+n16;

          resultado = resultado%10;

          if (resultado == 0)
          {
            cartaomastercard = 1;
            validadordigito = 1;
          }
          

        }
        
        else
        {
          //AQUI VOU PEGAR A INFORMAÇÃO DO PRIMEIRO DÍGITO DO NÚMERO SE ELE FOR VÁLIDO.//

        digitoinicial = cartao / 1000000000000000;
        
        //SE DIGITO INICIAL IGUAL A 4/

        if (digitoinicial==4)
        {

           n1 = copiacartao%10;
           copiacartao = copiacartao/10;
           n2 = copiacartao%10;
           copiacartao = copiacartao/10;
           n3 = copiacartao%10;
           copiacartao = copiacartao/10;
           n4 = copiacartao%10;
           copiacartao = copiacartao/10;
           n5 = copiacartao%10;
           copiacartao = copiacartao/10;
           n6 = copiacartao%10;
           copiacartao = copiacartao/10;
           n7 = copiacartao%10;
           copiacartao = copiacartao/10;
           n8 = copiacartao%10;
           copiacartao = copiacartao/10;
           n9 = copiacartao%10;
           copiacartao = copiacartao/10;
           n10 = copiacartao%10;
           copiacartao = copiacartao/10;
           n11 = copiacartao%10;
           copiacartao = copiacartao/10;
           n12 = copiacartao%10;
           copiacartao = copiacartao/10;
           n13 = copiacartao%10;
           copiacartao = copiacartao/10;
           n14 = copiacartao%10;
           copiacartao = copiacartao/10;
           n15 = copiacartao%10;
           copiacartao = copiacartao/10;
           n16 = copiacartao%10;

          n2 = n2*2;
          n4 = n4*2;
          n6 = n6*2;
          n8 = n8*2;
          n10 = n10*2;
          n12 = n12*2;
          n14 = n14*2;
          n16 = n16*2;

          if (n2>9)
          {
            int n21 = n2%10;
            n2 = n2 / 10;
            int n22 = n2%10;
            n2 = n21 + n22;
          }

          if (n4>9)
          {
            int n41 = n4%10;
            n4 = n4 / 10;
            int n42 = n4%100;
            n4 = n41 + n42;
          }

          if (n6>9)
          {
            int n61 = n6%10;
            n6 = n6 / 10;
            int n62 = n6%100;
            n6 = n61 + n62;
          }

          if (n8>9)
          {
            int n81 = n8%10;
            n8 = n8 / 10;
            int n82 = n8%100;
            n8 = n81 + n82;
          }

          if (n10>9)
          {
            int n101 = n10%10;
            n10 = n10 / 10;
            int n102 = n10%100;
            n10 = n101 + n102;
          }

          if (n12>9)
          {
            int n121 = n12%10;
            n12 = n12 / 10;
            int n122 = n12%100;
            n12 = n121 + n122;
          }

          if (n14>9)
          {
            int n141 = n14%10;
            n14 = n14 / 10;
            int n142 = n14%100;
            n14 = n141 + n142;
          }

          if (n16>9)
          {
            int n161 = n16%10;
            n16 = n16 / 10;
            int n162 = n16%100;
            n16 = n161 + n162;
          }
          
          int resultado = n1+n2+n3+n4+n5+n6+n7+n8+n9+n10+n11+n12+n13+n14+n15+n16;

          resultado = resultado%10;

          if (resultado == 0)
          {
            cartaovisa = 1;
            validadordigito = 1;
          }
          

        }
        }
        

    }

    if (validadordigito==2)
    validadordigito=0;

} while (validadordigito == 0);

if (cartaovisa==1)
printf("\nSEU CARTÃO VISA NÚMERO %lld É VÁLIDO.\n",cartao);

if (cartaomastercard==1)
printf("\nSEU CARTÃO MASTER CARD NÚMERO %lld É VÁLIDO.\n",cartao);

if (cartaoamerican==1)
printf("\nSEU CARTÃO AMERICAN EXPRESS NÚMERO %lld É VÁLIDO.\n",cartao);

system("PAUSE");

return(0);
}