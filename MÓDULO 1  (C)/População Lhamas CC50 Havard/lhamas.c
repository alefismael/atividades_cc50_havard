/*PROGRAMA PARA CALCULAR QUANTIDADE DE ANOS NECESSÁRIOS PARA A POPULAÇÃO DE LHAMAS ADQUIRIREM UMA NOVA QUANTIDADE DA POPULAÇÃO EM RELEÇÃO A UMA ANTIGA INFORMADA.*/

#include <stdio.h>
#include <math.h>
#include <locale.h>

int main(void)

{
 setlocale(LC_ALL,"portuguese_brazil");

 int populacaoinicial,populacaofinal,populacao,anos=0,vida=0,morte=0;

 printf("\nESSE PROGRAMA FOI CRIADO PARA CALCULAR QUANTIDADE DE ANOS NECESSÁRIOS PARA A POPULAÇÃO DE LHAMAS ADQUIRIREM UMA NOVA QUANTIDADE DA POPULAÇÃO EM RELEÇÃO A UMA ANTIGA INFORMADA.\n");

 // Solicite o valor inicial ao usuário

 printf("Informe o número inicial da população de lhamas:\n");
 scanf("%d",&populacaoinicial);
 while (getchar() != '\n');

 while (populacaoinicial<9)
 {
    printf("\nA população de lhamas precisa ser de pelo menos 9,informe o número inicial da população de lhamas:\n");
    scanf("%d",&populacaoinicial);
    while (getchar() != '\n');
 }
 
 // Solicite o valor final ao usuário

 printf("\nInforme o número final da população de lhamas:\n");
 scanf("%d",&populacaofinal);
 while (getchar() != '\n');

 while (populacaofinal<populacaoinicial)
 {
    printf("\nA população final de lhamas precisa ser igual ou maior a população inicial,informe o número final da população de lhamas:\n");
    scanf("%d",&populacaofinal);
    while (getchar() != '\n');
 }

// Calcule o número de anos até o limite

populacao = populacaoinicial;

while (populacao<populacaofinal)
{
   vida=populacao/3;
   morte=populacao/4;
   populacao = (populacao + (vida - morte));
   anos++;
}

// Imprima o número de anos

if (anos==1)
   printf("Será necessário 1 ano para a população inicial de %d atingir %d lhamas.",populacaoinicial,populacaofinal);
else
   printf("Será necessário %d anos para a população inicial de %d atingir %d lhamas.",anos,populacaoinicial,populacaofinal);

system("PAUSE");

return(0);

}