#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char arquivo_analisado[50]; //não precisa de * já que array em si é um ponteiro
    printf("digite o nome do arquivo: \n");
    fgets(arquivo_analisado, 50, stdin);
    arquivo_analisado[strlen(arquivo_analisado)-1] = '\0';
    FILE *arquivo = fopen(arquivo_analisado, "rb");
    if(arquivo == NULL)
    {
        printf("arquivo nao existe\n");
        return EXIT_FAILURE;
    }
    char c;
    int qtd_letras = 0;
    while(fread(&c, sizeof(char), 1, arquivo) == 1){
      if(c == 'a')
      {
        qtd_letras++;
      }
                                                   }
    printf("%d\n", qtd_letras);
    fclose(arquivo);
    return EXIT_SUCCESS;
}
