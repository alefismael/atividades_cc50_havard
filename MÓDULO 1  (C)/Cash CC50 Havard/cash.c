//*Calculadora feita com o objetivo de facilitar a vida do caixa ao dar o troco*//

//Incluindo as bibliotecas necessárias para o programa//

#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <conio.h>
#include <ctype.h>

//Agora, inciando o programa chamando a função main//

int main(void)

{
//Compatibilidade de linguagem//

setlocale(LC_ALL,"Portuguese_Brazil");

//Aqui dentro dos {} está o código principal do projeto//

//De início vou mostrar ao usuário o que o programa faz, e depois solicitar a ele alguns dados, caso ele informe errado, vou solicitar novamente ou dar a ele a opção sair do programa, adicionei um filtro //
//Talvez mas para frente eu consiga melhorar esse filtro, mas ainda sou iniciante, e a atividade nem pedia um filtro, mas eu preferi fazer um sozinho, valeu a experiência.//

printf("SEJA VEM VINDO AO TROCO FÁCIL!!\n");

printf("\nEsse programa foi criado para facilitar o troco, informando quantas notas e moedas você precisa dar de troco especificamente.\n\n");

printf("Informe o valor total da compra do cliente:\n");
printf("(exemplo - R$23,42)\nR$");

float compra,letracompra;
letracompra = scanf("%f",&compra);
while (getchar() != '\n');

while (((compra <= 0) || (letracompra==0)))
{
    printf("Valor informado inválido, por favor informe um número como valor positivo ou digite 0 para fechar o programa.\nR$");
    letracompra = scanf("%f",&compra);
    while (getchar() != '\n');
    if ((compra == 0) &&( letracompra==1))
    return(0);
}

printf("\nAgora informe o valor recebido para pagar a compra.\n");
printf("(exemplo - R$23,42)\nR$");

float saldo,letrasaldo;
letrasaldo = scanf("%f",&saldo);
while (getchar() != '\n');

while ((saldo <= 0) || (saldo - compra <0) || (letrasaldo==0) )
{
    printf("O valor recebido não é suficiente para pagar a conta, digite 0 para fechar o programa ou então informe outro valor.\nR$");
    scanf("%f",&saldo);
    while (getchar() != '\n');
    if ((saldo == 0) && (letrasaldo==1))
    return(0);
}

//Feito a conversão, agora a parte final, descobrir o troco que precisa ser dado, e então informar ao usuário as informações.//

float troco = (saldo-compra);
float troc=troco;
int n100=0,n50=0,n20=0,n10=0,n5=0,n2=0,n1=0,m20=0,m10=0,m5=0,m1=0;

while ((troc-100)>=0)
{
    n100++;
    troc=troc-100;
}

while ((troc-50)>=0)
{
    n50++;
    troc=troc-50;
}

while ((troc-20)>=0)
{
    n20++;
    troc=troc-20;
}

while ((troc-10)>=0)
{
    n10++;
    troc=troc-10;
}

while ((troc-5)>=0)
{
    n5++;
    troc=troc-5;
}

while ((troc-2)>=0)
{
    n2++;
    troc=troc-2;
}

while ((troc-1)>=0)
{
    n1++;
    troc=troc-1;
}

while ((troc-0.2)>=0)
{
    m20++;
    troc=troc-0.2;
}

while ((troc-0.1)>=0)
{
    m10++;
    troc=troc-0.1;
}

while ((troc-0.05)>=0)
{
    m5++;
    troc=troc-0.05;
}

while ((troc-0.01)>=0)
{
    m1++;
    troc=troc-0.01;
}

printf("\nO troco é R$%.2f",troco);
printf("\nSerá necessário para dar esse troco:\n");
if (n100>0)
printf("\nNotas de R$100 - %d",n100);

if (n50>0)
printf("\nNotas de R$50 - %d",n50);

if (n20>0)
printf("\nNotas de R$20 - %d",n20);

if (n10>0)
printf("\nNotas de R$10 - %d",n10);

if (n5>0)
printf("\nNotas de R$5 - %d",n5);

if (n2>0)
printf("\nNotas de R$2 - %d",n2);

if (n1>0)
printf("\nNotas de R$1 - %d",n1);

if (m20>0)
printf("\nMoedas de R$0,20 - %d",m20);

if (m10>0)
printf("\nMoedas de R$0,10 - %d",m10);

if (m5>0)
printf("\nMoedas de R$0,05 - %d",m5);

if (m1>0)
printf("\nMoedas de R$0,01 - %d",m1);

printf("\n\n");
system("PAUSE");

return(0);

}