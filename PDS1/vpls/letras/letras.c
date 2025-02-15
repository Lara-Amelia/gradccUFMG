#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc<2)
    {
        printf("erro, favor passar o nome do arquivo\n");
        return EXIT_FAILURE;
    }
    char *arquivo_analisado = argv[1];
    FILE *arquivo = fopen(arquivo_analisado, "r");
    if(arquivo == NULL)
    {
        printf("nao foi possivel abrir o arquivo\n");
        return EXIT_FAILURE;
    }
    char c;
    int qtd_letras = 0;
    for(int i=0; ; i++)
    {
        c = fgetc(arquivo);
        printf("%c", c);
        if(c == 'a')
          {qtd_letras++;
            continue;}
        else if(c == EOF)
        {   printf("fim do arquivo\n");
            break;
        }
    }
    fclose(arquivo);
    printf("%d\n", qtd_letras);
    return EXIT_SUCCESS;
}
