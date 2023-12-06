/*PROGRAMA CRIADO PARA 2 JOGADORES JOGAR SCRABBLE*/

/*AQUI EU VOU INFORMAR AS BIBLIOTECAS QUE VOU PRECISAR*/

#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <ctype.h>

/*AQUI INCIA O C�DIGO INCIAL*/

int main(void)

{

setlocale(LC_ALL,"Portuguese_Brazil");

/*AQUI INFORMO VARI�VEIS*/

int scrabble[26] = {1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10};
char player1[30],player2[30];
int tam;
int soletras;
printf("\nJOGO SCRABBLE, CRIADO PARA JOGAR DE 2 PESSOAS.");

/*AQUI EU PEGO A PALAVRA DO PLAYER 1 E 2, FILTRANDO PARA N�O PERMITIR PALAVRA COM ESPA��O, TRA�O E N�MEROS, APENAS LETRAS.*/

do
{
    printf("\n\nINFORME A SUA PALAVRA PLAYER 1: ");
    fgets(player1,30,stdin);
    tam = strlen(player1);
    soletras = 0;

    for (int i = 0; i < tam-1; i++)
    {
        if (!(isalpha(player1[i])))
        {
            soletras = 1;
        }
        
    }

} while (soletras==1);


do
{
    printf("\n\nAGORA INFORME A SUA PALAVRA PLAYER 2: ");
    fgets(player2,30,stdin);
    tam = strlen(player2);
    soletras = 0;

    for (int i = 0; i < tam-1; i++)
    {
        if (!(isalpha(player2[i])))
        {
            soletras = 1;
        }
        
    }

} while (soletras==1);

/*AGORA VOU CALCULAR A PONTUA��O DOS 2 PLAYERS*/

/*PLAYER 1*/

tam = strlen(player1);

int pontplay1 = 0;
int calculo1 = 0;
int test1;

for (int i = 0; i < tam-1; i++)
{
    
    if (islower(player1[i]))
    {
       calculo1= (player1[i]-97);
       pontplay1= (pontplay1+scrabble[calculo1]);
    }
    if (isupper(player1[i]))
    {
    calculo1 = (player1[i]-65);
    pontplay1= (pontplay1+scrabble[calculo1]);}
    
}

/*PLAYER 2*/

tam = strlen(player2);

int pontplay2 =0;
int calculo2 = 0;
int test2;

for (int i = 0; i < tam-1; i++)
{
    if (islower(player2[i]))
    {  
       calculo2= (player2[i]-97);
       pontplay2= (pontplay2+scrabble[calculo2]);
    }
    if(isupper(player2[i]))
    {
    calculo2= (player2[i]-65);
    pontplay2= (pontplay2+scrabble[calculo2]);}
    
}

/*AGORA VOU IMPRIMIR QUEM VENCEU OU SE DEU EMPATE*/
printf("\n\nO RESULTADO FINAL �:");
if (pontplay1>pontplay2)
    printf(" PLAYER 1 GANHOU!!");
else if (pontplay1<pontplay2)
    printf(" PLAYER 2 GANHOU!!");
else
printf(" DEU EMPATE.");




system("pause");

return(0);
}

