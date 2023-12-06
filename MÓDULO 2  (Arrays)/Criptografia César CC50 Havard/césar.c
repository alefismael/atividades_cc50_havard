 /*PROGRAMA FEITO PARA USAR A CRIPTOGRAFIA DE CÉSAR EM UM TEXTO*/

#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>

int main (void)

{
  setlocale(LC_ALL,"bortuguese_brazil");
  printf("\nPROGRAMA CRIADO PARA USAR A CRIPTOGRAFIA DE CÉSAR EM UM TEXTO.\n");
  char key2[10000];
  int filtro = 1;

  /*AQUI VOU PEDIR UMA KEY QUE PRECISA SER UM NÚMERO POSITIVO, VOU PEDIR EM STRING PARA FAZER UM FILTRO ÓTIMO, COMO - POR EXEMPLO NÃO É NÚMERO, NEGATIVOS NÃO PASSAM. ASSIM COMO FLOATS*/

  do
  {
    printf("\nPOR FAVOR, INFORME A KEY QUE VOCÊ QUER USAR NESSA CRIPTOGRAFIA(NÚMERO INTEIRO POSITIVO):\n");
    fgets(key2,10000,stdin);
    int tam = strlen(key2);

    /*AQUI EU TIRO O \n PARA NÃO RESULTAR EM KEY COMO CONTENDO CARACTERE.*/
    if (tam > 0 && key2[tam - 1] == '\n') {
            key2[tam - 1] = '\0';}

    filtro = 1;
    tam = strlen(key2);

    for (int i = 0; i < tam; i++)
    {
        if (!(isdigit(key2[i])))
        {
           filtro = 0;
           break;
        }
        
    }
    
  } while (filtro==0);
  
  int key = atoi(key2); /*CONVERSÃO DA KEY EM CHAR PARA DIGITO.*/

  /*AGORA VOU SOLICITAR AO USUÁRIO O TEXTO QUE ELE QUER CRIPTOGRAFAR.USEI UM FILTRO PARA NÃO PERMITIR QUE O USUÁRIO INFORME UM TEXTO SEM NADA.*/

  char texto[10000];
  int tam;

  do
  {
    printf("\nINFORME O TEXTO QUE VOCÊ DESEJA CRIPTOGRAFAR:\n");
    fgets(texto,10000,stdin);
    tam = strlen(texto);
    
  } while (tam==1);
  
  /*AGORA COM A KEY E O TEXTO, AQUI É A PARTE DE CRIPTOGRAFAR O TEXTO.*/

  tam = strlen(texto);

  for (int i = 0; i < tam; i++)
  {
    if (isalpha(texto[i]))
    {
      if (isupper(texto[i]))
      {
        int ma = (texto[i]);
        ma = (ma-65);
        int ci = (ma + key)% 26;
        ma = ci+65;
        texto[i] = ma;
      }
    if (islower(texto[i])) 
    {
       int mi = (texto[i]);
        mi = (mi-97);
        int ci = (mi + key)% 26;
        mi = ci+97;
        texto[i] = mi;
    }
    }
    
  }
  
  /*AQUI VOU ENVIAR O RESULTADO DO TEXTO CRIPTOGRAFADO.*/

  printf("\nO TEXTO CRIPTOGRAFADO COM A KEY %d é:\n %s.",key,texto);

  system("pause");

return(0);
}