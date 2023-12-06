//*Projeto de uma escada de Mario feita a pedido do usuário de 1 até 8 de largura*//

#include <stdio.h>
#include <math.h>

int main(void)

{

 // Pedindo o usuário para informar o número de 1 até 8 da largura //

    printf("Bem vindo ao criador de escadas baseado em Mário.\n");
    printf("Por favor, informe o número da largura da escada que você quer criar.Pode ser de 1 até 8.\n");
    int larg;
    scanf("%d",&larg);

    //While utilizado para garantir que foi digitado um número de 1 à 8, se não foi, ele pede de novo ao usuário.//

    while((larg>8)||(larg<1))
    {
     printf("Você me informou um número fora do que foi pedido.Por favor, informe o número da largura da escada que você quer criar de 1 até 8.\n");
     scanf("%d",&larg);
    }
    printf("A largura é %d",larg);
    printf("Agora, vou mostrar essa escada para você:\n\n");

    //Criando a escada//

    int hashtag = 1;
    int espaco = larg-1;

    for (int lar=larg; lar > 0;lar--)
    {
       for (int esp = espaco; esp > 0 ; esp--)
       {
        printf(" ");
       }
       
       for (int hash=hashtag;hash > 0; hash--)
       {
        printf("#");
       }
       hashtag++;
       espaco--;
       printf("\n");
    }
    
    printf("\n");

    //Aqui é só um comando para finalizar o programa quando eu digitar enter.//

    system("pause");

    return 0;

}