#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>

// Tipos de dados relacionados a BMP baseados nos próprios da Microsoft

#include <stdint.h>

/**
 * Tipos de Dados Comuns
 *
 * Os tipos de dados nesta seção são essencialmente apelidos para os tipos de dados primitivos C/C++.
 *
 * Adaptado de http://msdn.microsoft.com/en-us/library/cc230309.aspx.
 * Consulte http://en.wikipedia.org/wiki/Stdint.h para obter mais informações sobre stdint.h.
 */
typedef uint8_t  BYTE;
typedef uint32_t DWORD;
typedef int32_t  LONG;
typedef uint16_t WORD;

/**
 * BITMAPFILEHEADER
 *
 * A estrutura BITMAPFILEHEADER contém informações sobre o tipo, tamanho
 * e layout de um arquivo que contém um DIB [bitmap independente de dispositivo].
 *
 * Adaptado de http://msdn.microsoft.com/en-us/library/dd183374(VS.85).aspx.
 */

#pragma pack(push, 1)
typedef struct 
{
    WORD   bfType;
    DWORD  bfSize;
    WORD   bfReserved1;
    WORD   bfReserved2;
    DWORD  bfOffBits;
} BITMAPFILEHEADER;

/**
 * BITMAPINFOHEADER
 *
 * A estrutura BITMAPINFOHEADER contém informações sobre as
 * dimensões e formato de cores de um DIB [bitmap independente de dispositivo].
 *
 * Adaptado de http://msdn.microsoft.com/en-us/library/dd183376(VS.85).aspx.
 */

typedef struct 
{
    DWORD  biSize;
    LONG   biWidth;
    LONG   biHeight;
    WORD   biPlanes;
    WORD   biBitCount;
    DWORD  biCompression;
    DWORD  biSizeImage;
    LONG   biXPelsPerMeter;
    LONG   biYPelsPerMeter;
    DWORD  biClrUsed;
    DWORD  biClrImportant;
} BITMAPINFOHEADER;

/**
 * RGBTRIPLE
 *
 * Esta estrutura descreve uma cor composta por intensidades relativas de
 * vermelho, verde e azul.
 *
 * Adaptado de http://msdn.microsoft.com/en-us/library/aa922590.aspx.
 */

typedef struct
{
    BYTE  rgbtBlue;   // Intensidade de azul
    BYTE  rgbtGreen;  // Intensidade de verde
    BYTE  rgbtRed;    // Intensidade de vermelho
} RGBTRIPLE;
#pragma pack(pop)

int main()
{

//aqui vou deixar como serto usar pt-br

setlocale(LC_ALL,"Portuguese_Brazil.1252");

printf("\n ESSE PROGRAMA FOI CRIADO PARA ADICIONAR UM FILTRO À UMA IMAGEM BMP.\n\n");

char nome[40];
int sair = 0;
int filtro = 0;
BITMAPINFOHEADER bi;
BITMAPFILEHEADER bf;

FILE *bmporiginal = NULL;

do
{
printf("PARA TER UMA IMAGEM BMP FILTRADA, PRIMEIRO DIGITE O NOME DO ENDEREÇO ONDE ELA ESTÁ NO COMPUTADOR, OU ENTÃO DIGITE 9 PARA FECHAR O PROGRAMA (NÃO ESQUEÇA DE USAR .bmp):");

fgets(nome,40,stdin);
nome[strcspn(nome, "\n")] = '\0';

if (strcmp(nome,"9")==0)
{
sair = 1;
break;
}


bmporiginal = fopen(nome,"rb");

if (bmporiginal == NULL)
{
printf("\n\nERRO AO ABRIR O ARQUIVO.\n\n");
continue;
}

    // Lê o cabeçalho do arquivo de entrada BITMAPFILEHEADER
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, bmporiginal);

    // Lê o cabeçalho do arquivo de entrada BITMAPINFOHEADER
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, bmporiginal);

        // Garante que o arquivo de entrada seja (provavelmente) um BMP 4.0 de 24 bits sem compressão
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(bmporiginal);
        printf("\n\nARQUIVO NÃO ESTÁ NO FORMATO BMP 4.0.\n\n");
        continue;
    }
    else
    {
    filtro = 1;
    }
    

} while ((filtro==0) || (sair==1));

    int height = abs(bi.biHeight);
    int width = bi.biWidth;

    // Aloca memória para a imagem
    RGBTRIPLE(*image)[width] = calloc(height, width * sizeof(RGBTRIPLE));
    if (image == NULL)
    {
        fclose(bmporiginal);
        printf("\n\nERRO");
        system("pause");
        return(0);
    }


 // Abre o arquivo de saída
    FILE *bmpcopia = fopen("imagemdaoriginalcomfiltro.bmp", "wb");
    if (bmpcopia == NULL)
    {
        fclose(bmpcopia);
        fclose(bmporiginal);
        free(image);
        printf("\nERRO AO ABRIR O ARQUIVO CÓPIA");
        system("pause");
        return(0);
    }
// Determina o preenchimento das linhas de varredura
    int padding = (4 - (width * sizeof(RGBTRIPLE)) % 4) % 4;

// Itera sobre as linhas de varredura do arquivo de entrada
    for (int i = 0; i < height; i++)
    {
        // Lê a linha para a matriz de pixels
        fread(image[i], sizeof(RGBTRIPLE), width, bmporiginal);

        // Pule sobre o preenchimento
        fseek(bmporiginal, padding, SEEK_CUR);
    }


filtro = 0;
int num = 0;
float calculo = 0;
float reflexo = ((int)width/2);
int reflex = 0;
int w = 0;
float sepiaRed = 0,sepiaGreen = 0,sepiaBlue = 0;
float media = 1;
int cal = 0;
float GX[3],GY[3];

for (int i = 0; i < 3; i++)
{
GX[i]=0;
GY[i]=0;
}


int ***clone = (int ***)malloc(height * sizeof(int **));
for (int i = 0; i < height; i++) {
    clone[i] = (int **)malloc(width * sizeof(int *));
    for (int j = 0; j < width; j++) {
        clone[i][j] = (int *)malloc(3 * sizeof(int));
    }
} //RED - 0 GREEN - 1 BLUE 2

for ( int i = 0; i < height; i++)
    {
    for (int j = 0; j < width; j++)
    {
     
     clone[i][j][0] = 0;
     clone[i][j][1] = 0;
     clone[i][j][2] = 0;
    
    }
    }


do
{
printf("\nO ARQUIVO É BMP 4.0, AGORA POR FAVOR, DIGITE O NÚMERO DO FILTRO QUE VOCÊ DESEJA USAR NA SUA IMAGEM BMP:\n\n");

printf("1 - ESCALA DE CINZA\n");
printf("2 - SÉPIA\n");
printf("3 - REFLETIR\n");
printf("4 - BLUR\n");
printf("5 - SIMETRIA\n"); //BONUS QUE EU QUIZ FAZER KKK
printf("6 - ARESTAS\n");
printf("7 - SAIR DO PROGRAMA\n\n");

scanf("%d",&num);


switch (num)
{
case 1:

    
    for ( int i = 0; i < height; i++)
    {
    for (int j = 0; j < width; j++)
    {
     
     calculo = ((image[i][j].rgbtBlue+image[i][j].rgbtGreen+image[i][j].rgbtRed)/3);
     calculo = (int)calculo;   
     image[i][j].rgbtBlue = calculo;
     image[i][j].rgbtGreen = calculo;
     image[i][j].rgbtRed = calculo;
    
    }
    }
    
    filtro = 1;
    break;

case 2:

for ( int i = 0; i < height; i++)
    {
    for (int j = 0; j < width; j++)
    {

    


     sepiaRed = 0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue;
     sepiaGreen = .349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue;
     sepiaBlue = 0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue;


     sepiaRed = (int)sepiaRed;
     sepiaGreen = (int)sepiaGreen;
     sepiaBlue = (int)sepiaBlue;
      
     if (sepiaRed>255)
    {
    sepiaRed=255;
    }
    if (sepiaBlue>255)
    {
    sepiaRed=255;
    }
    if (sepiaGreen>255)
    {
    sepiaGreen=255;
    }
    
    
     image[i][j].rgbtBlue = sepiaBlue;
     image[i][j].rgbtGreen = sepiaGreen;
     image[i][j].rgbtRed = sepiaRed;
    
    }
    }
    
    filtro = 1;
    break;

case 3:
      
    for ( int i = 0; i < height; i++)
    {
    w = width;
    for (int j = 0; j < reflexo; j++)
    {
    
    reflex = image[i][j].rgbtBlue;
    image[i][j].rgbtBlue = image[i][w].rgbtBlue;
    image[i][w].rgbtBlue = reflex;


    reflex = image[i][j].rgbtGreen;
    image[i][j].rgbtGreen = image[i][w].rgbtGreen;
    image[i][w].rgbtGreen = reflex;

    
    reflex = image[i][j].rgbtRed;
    image[i][j].rgbtRed = image[i][w].rgbtRed;
    image[i][w].rgbtRed = reflex;

    w--;
  
    }   
    }

    filtro = 1;
    break;

case 4:


    for (int i = 0; i < height; i++)
    {
    for (int j = 0; j < width; j++)
    {

    if ((i>0)&&(j>0))
    {
    clone[i][j][0] = clone[i][j][0]+image[i-1][j-1].rgbtRed;
    clone[i][j][2] = clone[i][j][2]+image[i-1][j-1].rgbtBlue;
    clone[i][j][1] = clone[i][j][1]+image[i-1][j-1].rgbtGreen;
    media++;
    }

    
    if (i>0)
    {
    clone[i][j][0] = clone[i][j][0]+image[i-1][j].rgbtRed;
    clone[i][j][2] = clone[i][j][2]+image[i-1][j].rgbtBlue;
    clone[i][j][1] = clone[i][j][1]+image[i-1][j].rgbtGreen;
    media++;
    }

    if ((i>0)&&(j+1<width))
    {
    clone[i][j][0] = clone[i][j][0]+image[i-1][j+1].rgbtRed;
    clone[i][j][2] = clone[i][j][2]+image[i-1][j+1].rgbtBlue;
    clone[i][j][1] = clone[i][j][1]+image[i-1][j+1].rgbtGreen;
    media++;
    }

    if (j>0)
    {
    clone[i][j][0] = clone[i][j][0]+image[i][j-1].rgbtRed;
    clone[i][j][2] = clone[i][j][2]+image[i][j-1].rgbtBlue;
    clone[i][j][1] = clone[i][j][1]+image[i][j-1].rgbtGreen;
    media++;
    }

    if (j+1<width)
    {
    clone[i][j][0] = clone[i][j][0]+image[i][j+1].rgbtRed;
    clone[i][j][2] = clone[i][j][2]+image[i][j+1].rgbtBlue;
    clone[i][j][1] = clone[i][j][1]+image[i][j+1].rgbtGreen;
    media++;
    }

    if ((i+1<height)&&(j>0))
    {
    clone[i][j][0] = clone[i][j][0]+image[i+1][j-1].rgbtRed;
    clone[i][j][2] = clone[i][j][2]+image[i+1][j-1].rgbtBlue;
    clone[i][j][1] = clone[i][j][1]+image[i+1][j-1].rgbtGreen;
    media++;
    }

    if (i+1<height)
    {
    clone[i][j][0] = clone[i][j][0]+image[i+1][j].rgbtRed;
    clone[i][j][2] = clone[i][j][2]+image[i+1][j].rgbtBlue;
    clone[i][j][1] = clone[i][j][1]+image[i+1][j].rgbtGreen;
    media++;
    }

    if ((i+1<height)&&(j+1<width))
    {
    clone[i][j][0] = clone[i][j][0]+image[i+1][j+1].rgbtRed;
    clone[i][j][2] = clone[i][j][2]+image[i+1][j+1].rgbtBlue;
    clone[i][j][1] = clone[i][j][1]+image[i+1][j+1].rgbtGreen;
    media++;
    }
 
    clone[i][j][0] = clone[i][j][0]+image[i][j].rgbtRed;
    clone[i][j][2] = clone[i][j][2]+image[i][j].rgbtBlue;
    clone[i][j][1] = clone[i][j][1]+image[i][j].rgbtGreen;

    cal = (int)(clone[i][j][0]/media); 
    clone[i][j][0] = cal;


    cal = (int)(clone[i][j][1]/media);
    clone[i][j][1] = cal;

  
    cal = (int)(clone[i][j][2]/media);
    clone[i][j][2] = cal;


    media = 1;

    }
    }


    for ( int i = 0; i < height; i++)
    {
    for (int j = 0; j < width; j++)
    {
     
    image[i][j].rgbtRed = clone[i][j][0];
    image[i][j].rgbtGreen = clone[i][j][1];
    image[i][j].rgbtBlue = clone[i][j][2];
    
    }
    }
            
    filtro = 1;
    break;

case 5:

    for ( int i = 0; i < height; i++)
    {
    w = width;
    for (int j = 0; j < reflexo; j++)
    {
    
    image[i][w].rgbtBlue = image[i][j].rgbtBlue;

    image[i][w].rgbtGreen = image[i][j].rgbtGreen;

    image[i][w].rgbtRed = image[i][j].rgbtRed;

    w--;
  
    }   
    }


    filtro = 1;

    break;




case 6:

for (int i = 0; i < height; i++)
    {
    for (int j = 0; j < width; j++)
    {

    if ((i>0)&&(j>0))
    {
    GX[0] = (-1*image[i-1][j-1].rgbtRed);
    GX[2] = (-1*image[i-1][j-1].rgbtBlue);
    GX[1] = (-1*image[i-1][j-1].rgbtGreen);

    GY[0] = (-1*image[i-1][j-1].rgbtRed);
    GY[2] = (-1*image[i-1][j-1].rgbtBlue);
    GY[1] = (-1*image[i-1][j-1].rgbtGreen);
    }
    else
    {
    GX[0] = (-1*0);
    GX[2] = (-1*0);
    GX[1] = (-1*0);

    GY[0] = (-1*0);
    GY[2] = (-1*0);
    GY[1] = (-1*0);
    }
    

    
    if (i>0)
    {
    GX[0] = (GX[0]+(0*image[i-1][j].rgbtRed));
    GX[2] = (GX[2]+(0*image[i-1][j].rgbtBlue));
    GX[1] = (GX[1]+(0*image[i-1][j].rgbtGreen));

    GY[0] = (GX[0]+(-2*image[i-1][j].rgbtRed));
    GY[2] = (GX[2]+(-2*image[i-1][j].rgbtBlue));
    GY[1] = (GX[1]+(-2*image[i-1][j].rgbtGreen));
    }
    else
    {
    GX[0] = (GX[0]+(0*0));
    GX[2] = (GX[2]+(0*0));
    GX[1] = (GX[1]+(0*0));

    GY[0] = (GX[0]+(-2*0));
    GY[2] = (GX[2]+(-2*0));
    GY[1] = (GX[1]+(-2*0));
    }

    if ((i>0)&&(j+1<width))
    {
    
    GX[0] = (GX[0]+(1*image[i-1][j+1].rgbtRed));
    GX[2] = (GX[2]+(1*image[i-1][j+1].rgbtBlue));
    GX[1] = (GX[1]+(1*image[i-1][j+1].rgbtGreen));

    GY[0] = (GX[0]+(-1*image[i-1][j+1].rgbtRed));
    GY[2] = (GX[2]+(-1*image[i-1][j+1].rgbtBlue));
    GY[1] = (GX[1]+(-1*image[i-1][j+1].rgbtGreen));

    }

    else
    {
    GX[0] = (GX[0]+(1*0));
    GX[2] = (GX[2]+(1*0));
    GX[1] = (GX[1]+(1*0));

    GY[0] = (GX[0]+(-1*0));
    GY[2] = (GX[2]+(-1*0));
    GY[1] = (GX[1]+(-1*0));
    }

    if (j>0)
    {
    
    GX[0] = (GX[0]+(-2*image[i][j-1].rgbtRed));
    GX[2] = (GX[2]+(-2*image[i][j-1].rgbtBlue));
    GX[1] = (GX[1]+(-2*image[i][j-1].rgbtGreen));

    GY[0] = (GX[0]+(0*image[i][j-1].rgbtRed));
    GY[2] = (GX[2]+(0*image[i][j-1].rgbtBlue));
    GY[1] = (GX[1]+(0*image[i][j-1].rgbtGreen));

    }

    else
    {
    GX[0] = (GX[0]+(-2*0));
    GX[2] = (GX[2]+(-2*0));
    GX[1] = (GX[1]+(-2*0));

    GY[0] = (GX[0]+(0*0));
    GY[2] = (GX[2]+(0*0));
    GY[1] = (GX[1]+(0*0));
    }

    if (j+1<width)
    {
    
    GX[0] = (GX[0]+(2*image[i][j+1].rgbtRed));
    GX[2] = (GX[2]+(2*image[i][j+1].rgbtBlue));
    GX[1] = (GX[1]+(2*image[i][j+1].rgbtGreen));

    GY[0] = (GX[0]+(0*image[i][j+1].rgbtRed));
    GY[2] = (GX[2]+(0*image[i][j+1].rgbtBlue));
    GY[1] = (GX[1]+(0*image[i][j+1].rgbtGreen));

    }

    else
    {
    GX[0] = (GX[0]+(2*0));
    GX[2] = (GX[2]+(2*0));
    GX[1] = (GX[1]+(2*0));

    GY[0] = (GX[0]+(0*0));
    GY[2] = (GX[2]+(0*0));
    GY[1] = (GX[1]+(0*0));
    }

    if ((i+1<height)&&(j>0))
    {

    GX[0] = (GX[0]+(-1*image[i+1][j-1].rgbtRed));
    GX[2] = (GX[2]+(-1*image[i+1][j-1].rgbtBlue));
    GX[1] = (GX[1]+(-1*image[i+1][j-1].rgbtGreen));

    GY[0] = (GX[0]+(1*image[i+1][j-1].rgbtRed));
    GY[2] = (GX[2]+(1*image[i+1][j-1].rgbtBlue));
    GY[1] = (GX[1]+(1*image[i+1][j-1].rgbtGreen));

    }

    else
    {
    GX[0] = (GX[0]+(-1*0));
    GX[2] = (GX[2]+(-1*0));
    GX[1] = (GX[1]+(-1*0));

    GY[0] = (GX[0]+(1*0));
    GY[2] = (GX[2]+(1*0));
    GY[1] = (GX[1]+(1*0));
    }

    if (i+1<height)
    {
    
    GX[0] = (GX[0]+(0*image[i+1][j].rgbtRed));
    GX[2] = (GX[2]+(0*image[i+1][j].rgbtBlue));
    GX[1] = (GX[1]+(0*image[i+1][j].rgbtGreen));

    GY[0] = (GX[0]+(2*image[i+1][j].rgbtRed));
    GY[2] = (GX[2]+(2*image[i+1][j].rgbtBlue));
    GY[1] = (GX[1]+(2*image[i+1][j].rgbtGreen));

    }

    else
    {
    GX[0] = (GX[0]+(0*0));
    GX[2] = (GX[2]+(0*0));
    GX[1] = (GX[1]+(0*0));

    GY[0] = (GX[0]+(2*0));
    GY[2] = (GX[2]+(2*0));
    GY[1] = (GX[1]+(2*0));
    }

    if ((i+1<height)&&(j+1<width))
    {
    
    GX[0] = (GX[0]+(1*image[i+1][j+1].rgbtRed));
    GX[2] = (GX[2]+(1*image[i+1][j+1].rgbtBlue));
    GX[1] = (GX[1]+(1*image[i+1][j+1].rgbtGreen));

    GY[0] = (GX[0]+(1*image[i+1][j+1].rgbtRed));
    GY[2] = (GX[2]+(1*image[i+1][j+1].rgbtBlue));
    GY[1] = (GX[1]+(1*image[i+1][j+1].rgbtGreen));

    }

    else
    {
    GX[0] = (GX[0]+(1*0));
    GX[2] = (GX[2]+(1*0));
    GX[1] = (GX[1]+(1*0));

    GY[0] = (GX[0]+(1*0));
    GY[2] = (GX[2]+(1*0));
    GY[1] = (GX[1]+(1*0));
    }
 
    GX[0] = (GX[0]+(0*image[i][j].rgbtRed));
    GX[2] = (GX[2]+(0*image[i][j].rgbtBlue));
    GX[1] = (GX[1]+(0*image[i][j].rgbtGreen));

    GY[0] = (GX[0]+(0*image[i][j].rgbtRed));
    GY[2] = (GX[2]+(0*image[i][j].rgbtBlue));
    GY[1] = (GX[1]+(0*image[i][j].rgbtGreen));

    clone[i][j][0] = (int)sqrt(GX[0]*GX[0]+GY[0]*GY[0]);
    clone[i][j][1] = (int)sqrt(GX[1]*GX[1]+GY[1]*GY[1]);
    clone[i][j][2] = (int)sqrt(GX[2]*GX[2]+GY[2]*GY[2]);

    if (clone[i][j][0]>255)
    {
    clone[i][j][0]=255;
    }

   if (clone[i][j][1]>255)
    {
    clone[i][j][1]=255;
    } 

   if (clone[i][j][2]>255)
    {
    clone[i][j][2]=255;
    }

    if (clone[i][j][0]<0)
    {
    clone[i][j][0]=0;
    }

   if (clone[i][j][1]<0)
    {
    clone[i][j][1]=0;
    } 

   if (clone[i][j][2]<0)
    {
    clone[i][j][2]=0;
    }


    


for (int i = 0; i < 3; i++)
{
      GX[i]=0;
      GY[i]=0;
}

    }
    }


    for ( int i = 0; i < height; i++)
    {
    for (int j = 0; j < width; j++)
    {
     
    image[i][j].rgbtRed = clone[i][j][0];
    image[i][j].rgbtGreen = clone[i][j][1];
    image[i][j].rgbtBlue = clone[i][j][2];
    
    }
    }





    filtro = 1;
    break;

    case 7:

    free(image);
    fclose(bmpcopia);
    fclose(bmporiginal);
    for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
        free(clone[i][j]);
    }
    free(clone[i]);
}
free(clone);

    printf("\n\nSAINDO DO PROGRAMA.\n\n");

    system("pause");
    return(0);

    break;

default:   
    break;
}

} while (filtro == 0);


   



    // Escreve o cabeçalho do arquivo de saída BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, bmpcopia);

    // Escreve o cabeçalho do arquivo de saída BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, bmpcopia);

    // Escreve os novos pixels para o arquivo de saída
    for (int i = 0; i < height; i++)
    {
        // Escreve a linha para o arquivo de saída
        fwrite(image[i], sizeof(RGBTRIPLE), width, bmpcopia);

        // Escreve o preenchimento no final da linha
        for (int k = 0; k < padding; k++)
        {
            fputc(0x00, bmpcopia);
        }
    }

    // Libera a memória para a imagem e clone
    free(image);

    for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
        free(clone[i][j]);
    }
    free(clone[i]);
}
free(clone);



    // Fecha o arquivo de entrada
    fclose(bmporiginal);

    // Fecha o arquivo de saída
    fclose(bmpcopia);

  


printf("IMAGEM GERADA COM SUCESSO,VOCÊ PODE ENCONTRAR ELA NA PASTA DO EXEC DO PROGRAMA.");


system("pause");

return(0);
}