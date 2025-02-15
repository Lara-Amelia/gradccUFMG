#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) //refazer modularizando(com funções)
{
    //le o nome de um arquivo e checa se existe ou não
    char arquivo_analisado[50]; //não precisa de * já que array em si é um ponteiro
    fgets(arquivo_analisado, 50, stdin);
    arquivo_analisado[strlen(arquivo_analisado)-1] = '\0';
    FILE *arquivo = fopen(arquivo_analisado, "r");
    if(arquivo == NULL)
    {
        printf("arquivo nao existe\n");
        return EXIT_FAILURE;
    }

    long int matriz1[5][5];
    for(int linha1 = 0; linha1 < 5; linha1++){
      for(int coluna1 = 0; coluna1 < 5; coluna1++)
      {
         fscanf(arquivo, "%ld", &matriz1[linha1][coluna1]);
      }
                                              }

    long int matriz2[5][5];
    for(int linha2 = 0; linha2 < 5; linha2++){
       for(int coluna2 = 0; coluna2 < 5; coluna2++){
       fscanf(arquivo, "%ld", &matriz2[linha2][coluna2]);
                                                   }
                                             }

    fclose(arquivo);
    long int matrizsoma[5][5];
    for(int i = 0; i < 5; i++){
       for(int j = 0; j < 5; j++){
        matrizsoma[i][j] = matriz1[i][j] + matriz2[i][j];
        printf("%ld ", matrizsoma[i][j]);
       }
        printf("\n");
    }
    return EXIT_SUCCESS;
}
