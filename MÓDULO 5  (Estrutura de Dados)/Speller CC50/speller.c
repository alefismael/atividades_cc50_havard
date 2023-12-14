#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

typedef struct dicionario
{
    struct dicionario *prox;
    char palavra[50];
} dicionario;

typedef dicionario *p_dic;

void armazenar(FILE *dicfile, p_dic dic[26]);
int consulta(p_dic dic[26]);

int main()
{
    setlocale(LC_ALL, "Portuguese");

    p_dic dic[26];

    for (int i = 0; i < 26; i++)
    {
        dic[i] = (p_dic)malloc(sizeof(dicionario));
        dic[i]->prox = NULL;
        strcpy(dic[i]->palavra, "NADA");
    }

    FILE *dicfile;

    dicfile = fopen("dicionario.bin", "rb");
    if (dicfile == NULL)
    {
        system("cls");
        printf("ERRO AO ABRIR O ARQUIVO DICIONARIO.");
        system("pause");
    }

    armazenar(dicfile, dic);
    consulta(dic);

    fclose(dicfile);

    p_dic aux;

    for (int i = 0; i < 26; i++)
    {
        while (dic[i]->prox != NULL)
        {
            aux = dic[i];
            dic[i] = dic[i]->prox;
            free(aux);
        }

        free(dic[i]);
    }

    return 0;
}

void armazenar(FILE *dicfile, p_dic dic[26])
{
    char escrever[50];
    int ajuda;
    p_dic temp;

    while (1)
    {
        fgets(escrever, 50, dicfile);
        if (feof(dicfile))
            break;

        escrever[strlen(escrever) - 1] = '\0'; // Remover a quebra de linha

        escrever[0] = tolower(escrever[0]);
        ajuda = (escrever[0] - 'a');
        for (int i = 0; i < 26; i++)
        {
            if (ajuda == i)
            {
                if (dic[i]->prox == NULL)
                {
                    dic[i]->prox = (p_dic)malloc(sizeof(dicionario));
                    temp = dic[i]->prox;
                    strcpy(temp->palavra, escrever);
                    temp->prox = NULL;
                }
                else
                {
                    temp = dic[i]->prox;
                    while (temp->prox != NULL)
                    {
                        temp = temp->prox;
                    }
                    temp->prox = (p_dic)malloc(sizeof(dicionario));
                    temp = temp->prox;
                    strcpy(temp->palavra, escrever);
                    temp->prox = NULL;
                }

                break;
            }
        }
    }
}

int consulta(p_dic dic[26])
{
    char *minhaString = NULL;
    int capacidade = 10; // Capacidade inicial da string
    int tamanhoAtual = 0;
    char caractere;

    minhaString = (char *)malloc(capacidade * sizeof(char));

    if (minhaString == NULL)
    {
        printf("ERRO AO ALOCAR MEMÓRIA PARA STRING.\n");
        return 1;
    }

    printf("DIGITE UM TEXTO PARA CONSULTAR SUAS INFORMAÇÕES DE ACORDO COM O DICIONÁRIO. (USE TEXTOS SEM ACENTOS) (PRESSIONE ENTER PARA ENCERRAR):\n");

    while ((caractere = getchar()) != '\n')
    {
        minhaString[tamanhoAtual++] = caractere;

        // Se a capacidade atual for atingida, realoca a string com o dobro da capacidade
        if (tamanhoAtual == capacidade - 1)
        {
            capacidade *= 2;
            minhaString = (char *)realloc(minhaString, capacidade * sizeof(char));

            if (minhaString == NULL)
            {
                printf("ERRO AO ALOCAR MEMÓRIA NA STRING.\n");
                return 1;
            }
        }
    }

    // Adiciona o caractere de terminação nulo no final da string
    minhaString[tamanhoAtual] = '\0';

    // Verifica as palavras que estão corretas;

    p_dic temp;
    char verifica[50];
    int i = 0, palavraserrada = 0, palavrascertas = 0, inicio = 0, ajuda = 0;
    while (minhaString[i] != '\0')
    {
        while (minhaString[i] != '\0' && !isalpha(minhaString[i]))
        {
            i++;
        }

        inicio = 0;

        while (minhaString[i] != '\0' && isalpha(minhaString[i]))
        {
            verifica[inicio++] = tolower(minhaString[i++]);
        }
        verifica[inicio] = '\0';

        // Pesquisa no dicionário se a palavra existe
        ajuda = (verifica[0] - 'a');
        temp = dic[ajuda]->prox;

        int encontrada = 0;

        while (temp != NULL)
        {
            if (strcmp(temp->palavra, verifica) == 0)
            {
                encontrada = 1;
                palavrascertas++;
                break;
            }
            temp = temp->prox;
        }

        if (!encontrada)
        {
            palavraserrada++;
            if (palavraserrada == 1)
            {
                printf("\nAS PALAVRAS ERRADAS SÃO: [%s] ", verifica);
            }
            else
            {
                printf("[%s] ", verifica);
            }
        }
    }

    printf("\n\nESSE TEXTO TEM %d PALAVRAS ERRADAS E %d PALAVRAS CERTAS.", palavraserrada, palavrascertas);

    // Libera a memória alocada
    free(minhaString);

    system("pause");
    return 0;
}
