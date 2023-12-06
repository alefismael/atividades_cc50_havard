/* PROGRAMA CRIADO PARA DESCOBRIR O N�VEL DE UM ALUNO PELO TEXTO*/

/*Aqui vou incluir as bibliotecas utilizadas no programa*/

#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <locale.h>

/*Chamada da fun��o main*/

int main(void)
{
    
    /*Aqui est� um comando para deixar o programa em padr�o PT-BR*/
    setlocale(LC_ALL,"Portuguese-Brazil");
    
    /*Come�o do c�digo principal*/
    printf("\nESSE PROGRAMA CRIADO PARA DESCOBRIR O N�VEL DE UM ALUNO PELO TEXTO.\n");
    char texto[1000];
    int textnotnumber;

    /*Aqui vou solicitar um texto at� ser informado um que n�o contenha n�meros.*/

   do
   {
    printf("\nINFORME POR FAVOR O TEXTO PARA A VERIFICA��O DO N�VEL DELE SER FEITA.(N�o pode ter n�meros nele).\n");
    fgets(texto,1000,stdin);
    int tam = strlen(texto);
    textnotnumber = 1;
    int i = 0;
    while ((i < tam) && (textnotnumber == 1))
    {
    i++;
    if (isdigit(texto[i]))
    {
       textnotnumber = 0;
    }
    }
   } while (textnotnumber==0);

   printf("\n\nTexto lido:%s.",texto);
   
   /*Agora vou verificar quantas letra tem esse texto*/

   int tam = strlen(texto);
   int letras = 0;

   for (int i = 0; i < tam; i++)
   {
    if (isalpha(texto[i]))
    {
    letras++;
    }
    
   }

   printf("\n\nLetras n: %d.",letras);


     /*Agora vou verificar quantas palavras tem o texto.*/

     int palavras = 1;
     for (int i = 0; i < tam; i++)
   {
    if (isblank(texto[i]))
    {
    palavras++;
    }
    
   }

   printf("\n\nPalavras n: %d.",palavras);


   /*Agora vou verificar quantas frases tem o texto.*/
    int frase = 0;

 for (int i = 0; i < tam; i++)
   {
    if ((texto[i]=='!')||(texto[i]=='?')||(texto[i]=='.'))
    {
    frase++;
    }
    
   }

   printf("\n\nFrase n: %d.",frase);

    /*Agora com todos esses dados � s� calcular a m�dia.*/

    float L; /*v�riavel n�mero m�dio de letras por 100 palavras no texto.*/
    L = (letras*100) / (palavras);

    printf("\n\nL n: %f.",L);
    
    float S; /*v�riavel n�mero m�dio de frases por 100 palavras no texto.*/
    S = (frase*100) / (palavras);
     printf("\n\nS n: %f.",S);

    /*Aqui fica o c�lculo principal*/
    
    float indice;
    indice = (0.0588 * L - 0.296 * S - 15.8);
    printf("\n\nIndice n: %f.",indice);
    int indicearredondado = round(indice);
    

    /*Aqui eu mostro o resultado do n�vel do texto.*/
    if (indicearredondado <= 1)
       printf("/O N�vel do aluno pelo texto �:before grade 1.");
    
    if (indicearredondado >= 16)
       printf("/O N�vel do aluno pelo texto �:grade 16+.");

    if ((1<indicearredondado) && (16>indicearredondado))
    printf("/O N�vel do aluno pelo texto �:%d�.",indicearredondado);

  system("PAUSE");

  return(0);

}