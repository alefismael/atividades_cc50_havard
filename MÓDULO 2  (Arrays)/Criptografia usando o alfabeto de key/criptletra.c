/*ESSE CÓDIGO É O CLÁSSICO QUE SE FUNCIONAR TÁ BOM, USEI MUITO IF, MAS ELE ENTREGA O QUE PROMETE*/

/*AQUI ESTÃO AS BLIBIOTECAS UTILIZADAS*/

#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

/*AQUI EU CHAMO A FUNÇÃO MAIN E COMEÇO O CÓDIGO*/

int main (void)
{

setlocale(LC_ALL,"Portuguese_Brazil"); /*DEIXA A LINGUAGEM DO PROGRAMA COM OS ACENTOS */

printf("ESSE PROGRAMA FOI CRIADO PARA CRIPTOGRAFAR ULTIZIZANDO O ALFABETO EM ORDEM DIFERENTE.EX:SE OB,AB=OB.\n\n");


char key[1000];
int filtro;


do
{
    
    printf("DIGITE O ALFABETO NA ORDEM QUE VOC? DESEJAR PARA CRIPTOGRAFAR(PRECISA TER 26 LETRAS, OU SEJA, TODAS AS LETRAS DO ALFABETO.).\n\n");

    fgets(key,1000,stdin);
    int tam = strlen(key);
    filtro=0;
    if (tam == 27)
    if (strchr(key, 'A') || strchr(key, 'a'))
    if (strchr(key, 'B') || strchr(key, 'b'))
    if (strchr(key, 'C') || strchr(key, 'c'))
    if (strchr(key, 'D') || strchr(key, 'd'))
    if (strchr(key, 'E') || strchr(key, 'e'))
    if (strchr(key, 'F') || strchr(key, 'f'))
    if (strchr(key, 'G') || strchr(key, 'g'))
    if (strchr(key, 'H') || strchr(key, 'h'))
    if (strchr(key, 'I') || strchr(key, 'i'))
    if (strchr(key, 'J') || strchr(key, 'j'))
    if (strchr(key, 'K') || strchr(key, 'k'))
    if (strchr(key, 'L') || strchr(key, 'l'))
    if (strchr(key, 'M') || strchr(key, 'm'))
    if (strchr(key, 'N') || strchr(key, 'n'))
    if (strchr(key, 'O') || strchr(key, 'o'))
    if (strchr(key, 'P') || strchr(key, 'p'))
    if (strchr(key, 'Q') || strchr(key, 'q'))
    if (strchr(key, 'R') || strchr(key, 'r'))
    if (strchr(key, 'S') || strchr(key, 's'))
    if (strchr(key, 'T') || strchr(key, 't'))
    if (strchr(key, 'U') || strchr(key, 'u'))
    if (strchr(key, 'V') || strchr(key, 'v'))
    if (strchr(key, 'W') || strchr(key, 'w'))
    if (strchr(key, 'X') || strchr(key, 'x'))
    if (strchr(key, 'Y') || strchr(key, 'y'))
    if (strchr(key, 'Z') || strchr(key, 'x'))
    filtro=1;
    
}while (filtro==0);

  /*PEDINDO PARA O USUÁRIO DIGITAR O TEXTO QUE ELE QUER CRIPTOGRAFAR, PRECISO CONTER PELO MENOS 1 CARACTERE.*/

  char texto[10000];
  int tam;

  do
  {
    printf("\nINFORME O TEXTO QUE VOCÊ DESEJA CRIPTOGRAFAR:\n");
    fgets(texto,10000,stdin);
    tam = strlen(texto);
    
  } while (tam==1);

  //*AQUI EM INFORMO O TEXTO CRIPTOGRAFATO*//

  printf("\n\nO TEXTO CRIPTOGRAFADO É:");

  tam = strlen(texto);

  for (int i = 0; i < tam; i++)
  {
    char letra;
         if ((texto[i] == 'A') || (texto[i] == 'a'))
         {
            if (texto[i] == 'A')
            {
            letra = toupper(key[0]);
            printf("%c",letra);
            }
            else
           { letra = tolower(key[0]);
            printf("%c",letra);}
         }
    else if ((texto[i] == 'B') || (texto[i] == 'b'))
    {
            if ((texto[i] == 'B'))
            {
            letra = toupper(key[1]);
            printf("%c",letra);
            }
            else
            {letra = tolower(key[1]);
            printf("%c",letra);}
         }
    else if ((texto[i] == 'C') || (texto[i] == 'c'))
    {
            if ((texto[i] == 'C'))
            {
            letra = toupper(key[2]);
            printf("%c",letra);
            }
            else
            {letra = tolower(key[2]);
            printf("%c",letra);}
         }
    else if ((texto[i] == 'D') || (texto[i] == 'd'))
    {
            if ((texto[i] == 'D'))
            {
            letra = toupper(key[3]);
            printf("%c",letra);
            }
            else
            {letra = tolower(key[3]);
            printf("%c",letra);}
         }
    else if ((texto[i] == 'E') || (texto[i] == 'e'))
    {
            if ((texto[i] == 'E'))
            {
            letra = toupper(key[4]);
            printf("%c",letra);
            }
            else
            {letra = tolower(key[4]);
            printf("%c",letra);}
         }
    else if ((texto[i] == 'F') || (texto[i] == 'f'))
    {
            if ((texto[i] == 'F'))
            {
            letra = toupper(key[5]);
            printf("%c",letra);
            }
            else
            {letra = tolower(key[5]);
            printf("%c",letra);}
         }
    else if ((texto[i] == 'G') || (texto[i] == 'g'))
    {
            if ((texto[i] == 'G'))
            {
            letra = toupper(key[6]);
            printf("%c",letra);
            }
            else
            {letra = tolower(key[6]);
            printf("%c",letra);}
         }
    else if ((texto[i] == 'H') || (texto[i] == 'h'))
    {
            if ((texto[i] == 'H'))
            {
            letra = toupper(key[7]);
            printf("%c",letra);
            }
            else
            {letra = tolower(key[7]);
            printf("%c",letra);}
         }
    else if ((texto[i] == 'I') || (texto[i] == 'i'))
    {
            if ((texto[i] == 'I'))
            {
            letra = toupper(key[8]);
            printf("%c",letra);
            }
            else
            {letra = tolower(key[8]);
            printf("%c",letra);}
         }
    else if ((texto[i] == 'J') || (texto[i] == 'j'))
    {
            if ((texto[i] == 'J'))
            {
            letra = toupper(key[9]);
            printf("%c",letra);
            }
            else
            {letra = tolower(key[9]);
            printf("%c",letra);}
         }
    else if ((texto[i] == 'K') || (texto[i] == 'k'))
    {
            if ((texto[i] == 'K'))
            {
            letra = toupper(key[10]);
            printf("%c",letra);
            }
            else
            {letra = tolower(key[10]);
            printf("%c",letra);}
         }
    else if ((texto[i] == 'L') || (texto[i] == 'l'))
    {
            if ((texto[i] == 'L'))
            {
            letra = toupper(key[11]);
            printf("%c",letra);
            }
            else
            {letra = tolower(key[11]);
            printf("%c",letra);}
         }
    else if ((texto[i] == 'M') || (texto[i] == 'm'))
    {
            if ((texto[i] == 'M'))
            {
            letra = toupper(key[12]);
            printf("%c",letra);
            }
            else
            {letra = tolower(key[12]);
            printf("%c",letra);}
         }
    else if ((texto[i] == 'N') || (texto[i] == 'n'))
    {
            if ((texto[i] == 'N'))
            {
            letra = toupper(key[13]);
            printf("%c",letra);
            }
            else
            {letra = tolower(key[13]);
            printf("%c",letra);}
         }
    else if ((texto[i] == 'O') || (texto[i] == 'o'))
    {
            if ((texto[i] == 'O'))
            {
            letra = toupper(key[14]);
            printf("%c",letra);
            }
            else
            {letra = tolower(key[14]);
            printf("%c",letra);}
         }
     else if ((texto[i] == 'P') || (texto[i] == 'p'))
    {
            if ((texto[i] == 'P'))
            {
            letra = toupper(key[15]);
            printf("%c",letra);
            }
            else
            {letra = tolower(key[15]);
            printf("%c",letra);}
         }
    else if ((texto[i] == 'Q') || (texto[i] == 'q'))
    {
            if ((texto[i] == 'Q'))
            {
            letra = toupper(key[16]);
            printf("%c",letra);
            }
            else
            {letra = tolower(key[16]);
            printf("%c",letra);}
         }
    else if ((texto[i] == 'R') || (texto[i] == 'r'))
    {
            if ((texto[i] == 'R'))
            {
            letra = toupper(key[17]);
            printf("%c",letra);
            }
            else
            {letra = tolower(key[17]);
            printf("%c",letra);}
         }
    else if ((texto[i] == 'S') || (texto[i] == 's'))
    {
            if ((texto[i] == 'S'))
            {
            letra = toupper(key[18]);
            printf("%c",letra);
            }
            else
            {letra = tolower(key[18]);
            printf("%c",letra);}
         }
    else if ((texto[i] == 'T') || (texto[i] == 't'))
    {
            if ((texto[i] == 'T'))
            {
            letra = toupper(key[19]);
            printf("%c",letra);
            }
            else
            {letra = tolower(key[19]);
            printf("%c",letra);}
         }
    else if ((texto[i] == 'U') || (texto[i] == 'u'))
    {
            if ((texto[i] == 'U'))
            {
            letra = toupper(key[20]);
            printf("%c",letra);
            }
            else
            {letra = tolower(key[20]);
            printf("%c",letra);}
         }
    else if ((texto[i] == 'V') || (texto[i] == 'v'))
    {
            if ((texto[i] == 'V'))
            {
            letra = toupper(key[21]);
            printf("%c",letra);
            }
            else
            {letra = tolower(key[21]);
            printf("%c",letra);
         }}
    else if ((texto[i] == 'W') || (texto[i] == 'w'))
    {
            if ((texto[i] == 'W'))
            {
            letra = toupper(key[22]);
            printf("%c",letra);
            }
            else
            {
                letra = tolower(key[22]);
            printf("%c",letra);
            }
         }
    else if ((texto[i] == 'X') || (texto[i] == 'x'))
    {
            if ((texto[i] == 'X'))
            {
            letra = toupper(key[23]);
            printf("%c",letra);
            }
            else
            {letra = tolower(key[23]);
            printf("%c",letra);}
         }     
    else if ((texto[i] == 'Y') || (texto[i] == 'y'))
    {
            if ((texto[i] == 'Y'))
            {
            letra = toupper(key[24]);
            printf("%c",letra);
            }
            else
            {letra = tolower(key[24]);
            printf("%c",letra);}
         }
    else if ((texto[i] == 'Z') || (texto[i] == 'z'))
    {
            if ((texto[i] == 'Z'))
            {
            letra = toupper(key[25]);
            printf("%c",letra);
            }
            else
            {letra = tolower(key[25]);
            printf("%c",letra);}
         }
    else
    printf("%c",texto[i]);
    

  }
  

printf("\n\n");
system("pause");
return(0);

}