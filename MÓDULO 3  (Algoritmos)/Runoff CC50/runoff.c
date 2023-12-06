/* PROGRAMA FEITO PARA FAZER UMA ELEIÇÃO COM NO MÍMINO 2 E NO MÁXIMO 9 CANDIDOS, E NO MINIMO 1 ELEITOR O NO MÍNIMO 100 ELEITORES*/
      /* AS ELEIÇÕES TÊM SEGUNDO TURNO EM CASO DE EMPATE ENTRE OS PRIMEIROS CANDIDATOS OU O CANDIDATO MAIS VOTADO NÃO TER MAIS DA METADE DOS VOTOS*/
          /*O MÉTODO DE RUNOFF FOI USADO PARA QUANTOS SEGUNDOS TURNOS FOREM NECESSÁRIOS, ATÉ ALGUEM VENCER OU TER EMPATE OU NINGUE GANHAR POR TODOS VOTOS SEREM NULO*/
             /*A INFORMAÇÃO DA QUANTIDADE DE CANDIDATOS E ELEITORES DEVE SER PASSADO NO INÍCIO ANTES DA VOTAÇÃO*/

             #include <stdio.h>
             #include <math.h>
             #include <ctype.h>
             #include <locale.h>
             #include <string.h>

struct candidato_eleicao
{
    char nome[20];
    int votos;
    int eliminado;
};

struct eleitor_eleicao
{
    char voto1 [20];
    char voto2 [20];
    char voto3 [20];
};
            

int main(void)
{
    setlocale(LC_ALL,"Portuguese_Brazil");
    
    printf("PROGRAMA FEITO PARA FAZER UMA ELEIÇÃO PODENDO TER SEGUNDO TURNO USANDO O MÉTODO RUNOFF COM NO MÍNIMO 2 E NO MÁXIMO 9 CANDIDOS, E NO MINIMO 1 ELEITOR O NO MÁXIMO 100 ELEITORES.\n\n");
    int filtro;
    
    /*AQUI EU PEGO A QUANTIDADE DE CANDIDATOS NAS ELEIÇÕES*/

    char ncandidatosletra[100]; /*USEI UMA ARRAY DE 100 PARA EVITAR BUGS POR PARTE DO USUÁRIO AO INFORMAR O NÚMERO, COMO POR EXEMPLO DIGITAR LETRAS. */
    int ncandidatos;

    do
    {
    printf("\nINFORME A QUANTIDADE DE CANDIDATOS QUE IRÃO PARTICIPAR DO VOTAÇÃO.(MÍNIMO 2 E NO MÁXIMO 9 CANDIDOS): ");
    fgets(ncandidatosletra,100,stdin);
    filtro = 0;
    ncandidatos = atoi(ncandidatosletra);
    if (isdigit(ncandidatosletra[0])&&(isspace(ncandidatosletra[1]))&&((1<ncandidatos)&&(ncandidatos<10))) /*FILTRO EXCELENTE PARA EVITAR BUGS, COMO UM CARACTERE ACABAR SE PASSANDO POR INT*/
    filtro=1;       

    } while (filtro==0);


    /*AGORA É A ETAPA DE PEGAR O NOME DE TODOS OS CANDITADOS, E DEIXAR TODOS COM 0 VOTOS INICIALMENTE, E DEIXO TODOS COMO CANDIDATOS POSSÍVEIS, DEIXANDO ELIMINADOS COMO 0*/

    struct candidato_eleicao candidato[ncandidatos];

    printf("\nAGORA INFORME O NOME DOS %d CANDITADOS.(Só pode usar letras sem acento, não pode usar outro tipo de caractere.",ncandidatos);
    for (int i = 0; i < ncandidatos; i++)
    {
        do
        {
        printf("\nQUAL É O NOME DO %d CANDIDATO?\n",i+1);
        fgets(candidato[i].nome,20,stdin);
        int tam = strlen(candidato[i].nome);
        filtro = 1;
        
        if (i>0)
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
        if(!(isalpha(candidato[i].nome[n])))
        filtro = 0;
        break;
        }
        } while (filtro==0);
        
    }

        for (int i = 0; i < ncandidatos; i++)
    {
    candidato[i].votos=0;
    candidato[i].eliminado=0;
    }
       
    /*AQUI EU PEGO A QUANTIDADE DE ELEITORES NAS ELEIÇÕES*/

    char neleitoresletra[100]; /*USEI UMA ARRAY DE 100 PARA EVITAR BUGS POR PARTE DO USUÁRIO AO INFORMAR O NÚMERO, COMO POR EXEMPLO DIGITAR LETRAS. */
    int neleitores;

    do
    {
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

    /*AQUI EU INFORMO SOBRE AS ELEI??ES V?O COME?AR, E EU DOU AS INSTRU??ES*/

    printf("\nAS ELEIÇÕES COM %d CANDIDATOS E %d ELEITORES VAI COMEÇAR.\n",ncandidatos,neleitores);
    printf("\nOS NOMES DOS CANDIDATOS SÃO: \n");
    for (int i = 0; i < ncandidatos; i++)
    {
        int tam = strlen(candidato[i].nome);
        for (int n = 0; n < tam-1; n++)
        {
        printf("%c",candidato[i].nome[n]);
        }
        if (i==ncandidatos-1)
        printf(".");
        else
        printf(", ");
    }
    
    printf("\nAGORA, PODEM VOTAR EM ORDEM ELEITORES, ESCREVA O NOME CORRETO DO CANDIDATO.RESPEITANDO LETRA MAIUSCULO A MINÚSCULA.\n\n");
    char nulo[] = "NULO\n";
    char voto[20];

    /*AQUI ? A ESTRUTURA QUE PEGA OS NOMES DOS VOTOS DOS ELEITORES E ARMAZENAM CADA UM DENTRO DA STRUCT ELEITORES*/
    
    for (int i = 0; i < neleitores; i++)
    {
      do
      {
        printf("POR FAVOR, ELEITOR NÚMERO %d DE O SEU VOTO PARA SEU PRIMEIRO CANDIDATO DIGITANDO O NOME DELE OU DIGITE 'NULO' PARA VOTAR NULO(DEPOIS DE NULO NÃO É POSSÍVEL MAIS VOTAR.\nCASO VOCÊ SÓ QUERIA VOTAR EM 1 CANDIDATO VOTE NO PRIMEIRO E DIGITE NULO NO SEGUNDO.): ",i+1);
        fgets(voto,20,stdin);
        filtro = 0;

        for (int v = 0; v < ncandidatos; v++)
        {
        if (!(strcmp(voto,candidato[v].nome)))
        {
        filtro = 1;
        strcpy(eleitor[i].voto1,voto);
        break;
        }
        }
        if (!(strcmp(voto,nulo)))
        filtro = 9;   

        if (filtro==1)
        {
        do
        {
        printf("\n\nPOR FAVOR, ELEITOR NÚMERO %d DE O SEU VOTO PARA SEU SEGUNDO CANDIDATO DIGITANDO O NOME DELE OU DIGITE 'NULO' PARA VOTAR NULO(DEPOIS DE NULO NÃO É POSSÍVEL MAIS VOTAR.\nCASO VOCÊ SÓ QUERIA VOTAR EM 1 CANDIDATO VOTE NO PRIMEIRO E DIGITE NULO NO SEGUNDO.): ",i+1);
        fgets(voto,20,stdin);

        for (int v = 0; v < ncandidatos; v++)
        {
        if (strcmp(voto,eleitor[i].voto1))       
        if (!(strcmp(voto,candidato[v].nome)))
        {
        filtro = 2;
        strcpy(eleitor[i].voto2,voto);
        break;
        }
        }
        if (!(strcmp(voto,nulo)))
        filtro = 9;  
        } while (filtro==1);    
        }

        if ((filtro==2)&&(neleitores>2))
        {
        do
        {
        printf("\n\nPOR FAVOR, ELEITOR NÚMERO %d DE O SEU VOTO PARA SEU TERCEIRO CANDIDATO DIGITANDO O NOME DELE OU DIGITE 'NULO' PARA VOTAR NULO(DEPOIS DE NULO NÃO É POSSÍVEL MAIS VOTAR.\nCASO VOCÊ SÓ QUERIA VOTAR EM 2 CANDIDATOS, VOTE NO PRIMEIRO E SEGUNDO E DIGITE NULO NO TERCEIRO.): ",i+1);
        fgets(voto,20,stdin);

        for (int v = 0; v < ncandidatos; v++)
        {
        if ((strcmp(voto,eleitor[i].voto1))&&(strcmp(voto,eleitor[i].voto2))) 
        if (!(strcmp(voto,candidato[v].nome)))
        {
        filtro = 3;
        strcpy(eleitor[i].voto3,voto);
        break;
        }
        }
        if (!(strcmp(voto,nulo)))
        filtro = 9;  
        } while (filtro==2);    
        }
        
        
        
      } while (filtro == 0);
      
    }
    
    //AGORA VOU FAZER O CALCULO E INFORMAR O VENCEDOR OU EMPATE.*/
    char maior[20];
    int maiorn,nvotos,menorn;
    char vencedor[20];
    int venc = 0;
    int empt = 0;
    filtro = 0;
    int todoseliminados;
    do
    {
       todoseliminados = 0;
       nvotos = 0;
       maiorn = 0;

       for (int i = 0; i < ncandidatos; i++)
       {
       candidato[i].votos = 0;
       }
       

       
       for (int i = 0; i < neleitores; i++)
       {
        for (int n = 0; n < ncandidatos; n++)
        {
         if (!(strcmp(candidato[n].nome,eleitor[i].voto1))&&(candidato[n].eliminado==0))
         candidato[n].votos++;
         else if (!(strcmp(candidato[n].nome,eleitor[i].voto2))&&(candidato[n].eliminado==0))
         candidato[n].votos++;
         else if (!(strcmp(candidato[n].nome,eleitor[i].voto3))&&(candidato[n].eliminado==0))
         candidato[n].votos++;         
        }
       }
    
    for (int i = 0; i < ncandidatos; i++)
    {
    if (candidato[i].votos>maiorn)
    {
    strcpy(maior, candidato[i].nome);
    maiorn = candidato[i].votos;
    }  
    }
    if (((maiorn%2==0)&&(maiorn>(nvotos/2))||((maiorn%2==1)&&(maiorn>=(nvotos/2)))))
    {
    strcpy(vencedor, maior);
    filtro=1;
    venc=1;
    }
    else
    {
    for (int i = 0; i < ncandidatos; i++)
    {
    if ((candidato[i].votos<=menorn)&&(candidato[i].eliminado==0))
    menorn = candidato[i].votos;   
    }
    
    for (int i = 0; i < ncandidatos; i++)
    {
    if ((candidato[i].votos==menorn)&&(candidato[i].eliminado==0))
    {
    candidato[i].eliminado=1;
    }
    }
    }
    

    for (int i = 0; i < ncandidatos; i++)
    {
    if (candidato[i].eliminado==1)
    {
    todoseliminados++;
    } 
    }
    
 if ((maiorn==menorn)&&(todoseliminados==ncandidatos)||(maiorn==0))
    {
    filtro=1;
    empt=1;
    }
    
    

    } while (filtro==0);
    
    if(venc==1)
    printf("\n\n%s GANHOU A ELEIÇÃO!!",maior);
    else if(empt==1)
    printf("\n\nA ELEIÇÃO NÃO TEVE VENCEDORES.");
    
    system("pause");
    return(0);
}

/*QUE BOM QUE FUNCIONOU, PENSEI EM DESISTIR DESSA ATIVIDADE, FIQUEI UNS 4 DIAS PENSANDO EM COMO EU IA FAZER ESSE PROGRAMA, ACABOU QUE DEPOIS QUE EU ENTENDI A LÓGICA QUE EU IA TER QUE FAZER FOI RÁPIDO CODAR*/
/*MINHA DICA É SEMPRE TENTAR FAZER A LÓGICA QUE VOCÊ QUER USAR NO PAPEL PRIMEIRO, PARA DEPOIS CODAR*/