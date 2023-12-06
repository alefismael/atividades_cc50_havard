/* PROGRAMA FEITO PARA FAZER UMA ELEIÇÃO COM NO MÍNIMO 2 E NO MÁXIMO 9 CANDIDOS, E NO MINIMO 1 ELEITOR O NO MÍNIMO 100 ELEITORES*/
      /* ESSAS ELEIÇÃO USA O MÉTODO DE TIDEMAN PARA DECLARAR O VENCEDOR, NESSE CASO NÃO PERMITIREI VOTAREM EM NULO */
             /*A INFORMAÇÃO DA QUANTIDADE DE CANDIDATOS E ELEITORES DEVE SER PASSADO NO INÍCIO ANTES DA VOTAÇÃO*/

             #include <stdio.h>
             #include <math.h>
             #include <ctype.h>
             #include <locale.h>
             #include <string.h>

struct candidato_eleicao
{
    char nome[20];
    int vitorias;
    int derrotas;
};

struct eleitor_eleicao
{
    char voto[9][20];
};

struct confronto_eleicao
{
    char vencedor[20];
    char perdedor[20];
    int diferenca;
    int clean;
};
            

int main(void)
{
    setlocale(LC_ALL,"Portuguese_Brazil");
    
    printf("PROGRAMA FEITO PARA FAZER UMA ELEIÇÃO COM O MÉTODO TIDEMAN COM NO MÍNIMO 2 E NO MÁXIMO 9 CANDIDOS, E NO MÍNIMO 1 ELEITOR O NO MÁXIMO 100 ELEITORES.\n\n");
    int filtro;
    
    /*AQUI EU PEGO A QUANTIDADE DE CANDIDATOS NAS ELETORES*/

    char ncandidatosletra[100]; /*USEI UMA ARRAY DE 100 PARA EVITAR BUGS POR PARTE DO USUï¿½RIO AO INFORMAR O NÚMERO, COMO POR EXEMPLO DIGITAR LETRAS. */
    int ncandidatos;

    do
    {
    printf("\nINFORME A QUANTIDADE DE CANDIDATOS QUE IRÃO PARTICIPAR DO VOTAÇÃO.(MïÍNIMO 2 E NO MÁXIMO 9 CANDIDOS): ");
    fgets(ncandidatosletra,100,stdin);
    filtro = 0;
    ncandidatos = atoi(ncandidatosletra);
    if (isdigit(ncandidatosletra[0])&&(isspace(ncandidatosletra[1]))&&((1<ncandidatos)&&(ncandidatos<10))) /*FILTRO EXCELENTE PARA EVITAR BUGS, COMO UM CARACTERE ACABAR SE PASSANDO POR INT*/
    filtro=1;       

    } while (filtro==0);


    /*AGORA É A ETAPA DE PEGAR O NOME DE TODOS OS CANDITADOS, E DEIXAR TODOS COM 0 VOTOS INICIALMENTE*/

    struct candidato_eleicao candidato[ncandidatos];

    printf("\nAGORA INFORME O NOME DOS %d CANDITADOS.(Só pode usar letras sem acento, não pode usar outro tipo de caractere.",ncandidatos);
    for (int i = 0; i < ncandidatos; i++)
    {
        do
        {
        printf("\nQUAL É O NOME DO %d CANDIDATO?\n",i+1);
        fgets(candidato[i].nome,20,stdin);      /*AQUI O USUÁRIO INFORMA O NOME DO CANDIDATO*/
        int tam = strlen(candidato[i].nome);
        filtro = 1;
        
        if (i>0)          /*ESSE IF É PARA GARANTIR QUE O SEGUNDO CANDIDATO NÃO TENHA O MESMO NOME DO PRIMEIRO CANDIDATO*/
        {
            for (int s = 0; s < i; s++)
            {
            if (!(strcmp(candidato[i].nome,candidato[s].nome)))
            {
            filtro = 0;
            break;
            }
            }         
            }         

        for (int n = 0; n < tam; n++)
        {
        if(!(isalpha(candidato[i].nome[n])))   /*FILTRO PARA SÓ PERMITIR A PASSAGEM DE LETRAS*/
        filtro = 0;
        break;
        }
        } while (filtro==0);
        
    }

        for (int i = 0; i < ncandidatos; i++)
    {
    candidato[i].derrotas=0;  /*AQUI EU GARANTO QUE TODOS CANDIDATOS VÃO COMEÇAR COM 0 DERROTAS*/
    candidato[i].vitorias=0;   /*AQUI EU GARANTO QUE TODOS CANDIDATOS VÃO COMEÇAR COM 0 VITÓRIAS*/
    }
       
    /*AQUI EU PEGO A QUANTIDADE DE ELEITORES NAS ELEITORES*/

    char neleitoresletra[100]; /*USEI UMA ARRAY DE 100 PARA EVITAR BUGS POR PARTE DO USUÁRIO AO INFORMAR O NÚMERO, COMO POR EXEMPLO DIGITAR LETRAS. */
    int neleitores;

    do
    {

          /*AQUI DENTRO USEI UM FILTRO PARA GARANTIR QUE SEJA INFORMADO UM NÚMERO DE 1 ATÉ 100, NÃO USEI || EM VEZ DE OUTROS IFS PORQUE IA FICAR MUITO LARGO O IF*/

    printf("\nAGORA INFORME O NÚMERO DE ELEITORES QUE IRÃO PARTICIPAR DO VOTAÇÃO.(MÍNIMO 1 E NO MÁXIMO 100 ELEITORES): ");
    fgets(neleitoresletra,100,stdin);
    filtro = 0;
    neleitores = atoi(neleitoresletra);
    if ((isdigit(neleitoresletra[0]))&&(isspace(neleitoresletra[1]))&&((0<neleitores)&&(neleitores<10)))
    filtro = 1;
    else if ((isdigit(neleitoresletra[0]))&&(isdigit(neleitoresletra[1]))&&(isspace(neleitoresletra[2]))&&((0<neleitores)&&(neleitores<100)))
    filtro = 1;
    else if (isdigit(neleitoresletra[0])&&isdigit(neleitoresletra[1])&&isdigit(neleitoresletra[2])&&(isspace(neleitoresletra[3]))&&(neleitores==100))
    filtro = 1;
    } while (filtro==0);

    struct eleitor_eleicao eleitor[neleitores];

    /*AQUI EU INFORMO SOBRE AS ELEITORES QUE IRÃO COMEÇAR, E EU DOU AS INSTRUÇÕES*/

    printf("\nAS ELEIÇÕES COM %d CANDIDATOS E %d ELEITORES VAI COMEÇAR.\n",ncandidatos,neleitores);
    printf("\nOS NOMES DOS CANDIDATOS Sï¿½O: \n");
    for (int i = 0; i < ncandidatos; i++)
    {
        int tam = strlen(candidato[i].nome);
        for (int n = 0; n < tam-1; n++)
        {
        printf("%c",candidato[i].nome[n]);
        }
        if (i==ncandidatos-1)   /*SE FOR O ÚLTIMO CANDIDATO, PRINT '.' SENÃO PRINT ',' */
        printf(".");
        else
        printf(", ");
    }
    
    printf("\nAGORA, PODEM VOTAR EM ORDEM ELEITORES, ESCREVA O NOME CORRETO DO CANDIDATO.RESPEITANDO LETRA MAIUSCULO A MINÚSCULA.\nVOCÊ NÃO PODE VOTAR NULO,É PRECISO VOTAR NAS SUAS PREFERÊNCIAS EM ORDEM, SEM REPETIR O CANDIDATO.\n\n");
    char voto[20];
    char posicao[9][20] = {"PRIMEIRO","SEGUNDO","TERCEIRO","QUARTO","QUINTO","SEXTO","SÉTIMO","OITAVO","NONO"};
    int diferente;

    /*AQUI A ESTRUTURA QUE PEGA OS NOMES DOS VOTOS DOS ELEITORES E ARMAZENAM CADA UM DENTRO DA STRUCT ELEITORES*/
    
    for (int i = 0; i < neleitores; i++)
    {
      for (int c = 0; c < ncandidatos; c++)
      {
      do
      {
        printf("POR FAVOR, ELEITOR NÚMERO %d DE O SEU VOTO PARA SEU %s CANDIDATO DIGITANDO O NOME DELE: ",i+1,posicao[c]);
        fgets(voto,20,stdin);
        filtro = 0;
        diferente = 1;

        if (c>0)
        {
        for (int d = 0; d < c; d++)
        {
         if (!(strcmp(voto,eleitor[i].voto[d])))
         {
         diferente = 0;
         break;
         }
        }
        }
        
        if (diferente == 1)
        {
        for (int v = 0; v < ncandidatos; v++)
        {
        if (!(strcmp(voto,candidato[v].nome)))
        {
        filtro = 1;
        strcpy(eleitor[i].voto[c],voto);
        break;
        }
        }  
        }
        

      } while (filtro == 0);
      }    
    }

    /*AQUI IDENTIFICO O VENCEDOR DA VOTAÇÃO UTILIZANDO O MÉTODO TIDEMAN*/

    int nconfrontos;  /*VOU CALCULAR O NÚMERO DE CONFRONTOS QUE SERÃO NECESSÁRIO*/

    nconfrontos = ((ncandidatos*(ncandidatos-1))/2);

    struct confronto_eleicao confronto[nconfrontos];
    int cand1,cand2;
    int aux = 0;
    
    /*VOU VERIFICAR QUEM GANHOU CADA CONFRONTO OU EMPATE SE TIVER*/

    for (int t = 0; t < ncandidatos-1; t++)
    {
        for (int c = t+1; c < ncandidatos; c++)
        {
        cand1=0;
        cand2=0;
        for (int v = 0; v < neleitores; v++)
        {
        for (int z = 0; z < ncandidatos; z++)
        {
        if (!(strcmp(eleitor[v].voto[z],candidato[t].nome)))
        {
        cand1++;
        break;
        }
        else if (!(strcmp(eleitor[v].voto[z],candidato[c].nome)))
        {
        cand2++;
        break;
        }      
        }    
        }
        if (cand1>cand2)
        {
        strcpy(confronto[aux].vencedor,candidato[t].nome);
        strcpy(confronto[aux].perdedor,candidato[c].nome);
        confronto[aux].diferenca=cand1-cand2;
        candidato[t].vitorias++;
        candidato[c].derrotas++;
        }
        else if (cand2>cand1)
        {
        strcpy(confronto[aux].vencedor,candidato[c].nome);
        strcpy(confronto[aux].perdedor,candidato[t].nome);
        confronto[aux].diferenca=cand2-cand1;
        candidato[c].vitorias++;
        candidato[t].derrotas++;
        }
        aux++;
        }
        
    }
    
/*AGORA VERIFICO SE ALGUEM GANHOU*/
char vencedor[20];
int end = 0;

for (int i = 0; i < nconfrontos; i++)
{
confronto[i].clean = 0;
}



for (int i = 0; i < ncandidatos; i++)
{
if ((candidato[i].derrotas==0)&&(candidato[i].vitorias>0))
{
strcpy(vencedor,candidato[i].nome);
end = 1;
break;
}
}

int menordif;

while (end==0)
{
end=0;
menordif = 999;

for (int i = 0; i < nconfrontos; i++)
{
if ((menordif > confronto[i].diferenca)&&(confronto[i].clean==0))
{
menordif = confronto[i].diferenca;
}
}

if (menordif==999)
{
end=9;
}
else
{
for (int i = 0; i < nconfrontos; i++)
{
if ((confronto[i].diferenca==menordif)&&(confronto[i].clean==0))
{
for (int v = 0; v < ncandidatos; v++)
{
if (!(strcmp(confronto[i].vencedor,candidato[v].nome)))
{
candidato[v].vitorias--;
break;
}
}

for (int v = 0; v < ncandidatos; v++)
{
if (!(strcmp(confronto[i].perdedor,candidato[v].nome)))
{
candidato[v].derrotas--;
break;
}
}
confronto[i].clean=1;
}
}

for (int i = 0; i < ncandidatos; i++)
{
if ((candidato[i].derrotas==0)&&(candidato[i].vitorias>0))
{
strcpy(vencedor,candidato[i].nome);
end = 1;
break;
}
}
}
}

if (end==1)
{
printf("O VENDEDOR DA ELEIÇÃO FOI %s.",vencedor);
}
else
{
    printf("NÃO HOUVE VENCEDORES.");
}


system("pause");
return(0);
}