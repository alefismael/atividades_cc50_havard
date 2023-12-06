// Programa criado para ler um arquivo de aï¿½dio .wav e modificar o volume dele//

#include <locale.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef uint8_t BYTE;
typedef int16_t BYTES2;

const int HEADER_SIZE = 44;

int main(void) {

  setlocale(LC_ALL,"Portuguese_Brazil.1252"); //faz o programa usar as normas PT-BR para acentos, etc

  printf("\n\nPROGRAMA CRIADO PARA LER UM Aï¿½DIO .WAV E MODIFICAR O VOLUME "
         "DELE.\n\n");

  char nomearq[50];
  int aberto = 0;
  FILE *audioriginal = NULL;

  while (aberto == 0) {

    printf("\n\nINFORME O NOME DO ARQUIVO DE Aï¿½DIO QUE VOCï¿½ DESEJA LER (precisa ter .wav) OU DIGITE 9 PARA FECHAR O PROGRAMA: ");

    scanf("%s", nomearq);

    if (!strcmp(nomearq, "9")) {
      if (audioriginal != NULL)
        fclose(audioriginal);

      printf("\n\nPROGRAMA FECHADO.\n\n");

      system("pause");

      return(0);
    }

    audioriginal = fopen(nomearq,"rb");

    if (audioriginal == NULL)
      printf("ERRO AO TENTAR LER O ARQUIVO, TENTE NOVAMENTE.");
    else
      aberto = 1;
  }

  BYTE header[HEADER_SIZE];
  int n1 = fread(header, sizeof(BYTE),44, audioriginal);

  if(n1!=HEADER_SIZE)
  { 

  printf("\n\nERRO AO LER O CABEï¿½ALHO DO ARQUIVO.");
  fclose(audioriginal);
  system("pause");
  return(0);

  }

  float n = 0;
  
  FILE *audioalterado = NULL;

  printf("\n\nDIGITE UM Nï¿½MERO PARA A PORCENTAGEM QUE VOCï¿½ DESEJA AUMENTAR OU DIMINUIR NO VOLUME: ");

  scanf("%f",&n);

  audioalterado = fopen("arquivoalterado.wav","wb");

  if (audioalterado == NULL)
   { 
    printf("\n\nERRO AO TENTAR ABRIR O ARQUIVO DE SAÍDA.");
     fclose(audioriginal);

     system("pause");
     return(0);

  }

  BYTES2 filtro;

  fwrite(header,sizeof(BYTE),44,audioalterado);

  int fim = 0;

  int teste = fread(&filtro,sizeof(BYTES2),1,audioriginal);

  filtro = (BYTES2)(filtro*n);

  if (teste==0)
  {
  fim = 1;
  }
  

  while (fim==0)
  {
    fwrite(&filtro,sizeof(BYTES2),1,audioalterado);
    teste = fread(&filtro,sizeof(BYTES2),1,audioriginal);
    filtro = (BYTES2)(filtro*n);

    if (teste==0)
  {
  fim = 1;
  }

  }
  

  // fecha os arquivos abertos
  fclose(audioriginal);
  fclose(audioalterado);

  printf("\n\nO PROGRAMA ALTEROU O VOLUME DO Aï¿½DIO COM SUCESSO.");

  system("pause");

  return(0);
}