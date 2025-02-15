#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

float tamanho_gosper(int iteracoes)
{
    float tamanho = 0;
    tamanho = (pow(7, iteracoes)*10/3) - 4/3;
    printf("função recorrencia - tamanho na iteracao %d: %d\n", iteracoes, (int)tamanho);
    return tamanho;
}

void gerar_arrowhead(int iteracoes, char *resultado, int length_gosper)
{
    if(iteracoes == 0)
    {
        return;
    }
    char* temp = (char*)malloc(length_gosper + 1);
    temp[0] = '\0';

    for(int i = 0; i < strlen(resultado); i++)
    {
        if(resultado[i] == 'X')
        {
            strcat(temp, "X+YF++YF-FX--FXFX-YF+");
        }
        else if(resultado[i] == 'Y')
        {
            strcat(temp, "-FX+YFYF++YF+FX--FX-Y");
        }
        else
        { 
            //concatena o caractere analisado à string temporária
            strncat(temp, &resultado[i], 1);
        }
    }
    strcpy(resultado, temp);
    gerar_arrowhead(iteracoes - 1, resultado, length_gosper);
}

void remove_xy(char *resultado)
{
    int i = 0, j = 0;
    while(resultado[i] != '\0')
    {
        if((resultado[i] != 'X') && (resultado[i]) != 'Y')
        {
            resultado[j] = resultado[i];
            j++;
        }
        i++;
    }
    resultado[j] = '\0';
    return;
}


int main (void)
{
    char axioma[10] = "XF";
    char regrax[50] = "X+YF++YF-FX--FXFX-YF+";
    char regray[50] = "-FX+YFYF++YF+FX--FX-Y";
    int iteracoes;
    //to-do: mudar para uso de alocação dinâmica
    
    char dados[50];
    printf("digite o número de iterações desejado: \n");
    fgets(dados, 50, stdin);
    dados[strlen(dados) - 1] = '\0';
    sscanf(dados, "%d", &iteracoes);
    printf("numero de iteracoes: %dACABAAQUI \n", iteracoes);
    int length_gosper = tamanho_gosper(iteracoes);
    char *resultado = (char *)malloc(length_gosper + 1);
    resultado [0] = '\0';
    strcat(resultado, "XF");
    gerar_arrowhead(iteracoes, resultado, length_gosper);
    printf("string antes da remoção: %s\n", resultado);
    printf("tamanho da string antes da remoção: %ld\n", strlen(resultado));
    remove_xy(resultado);
    FILE *saida_gosper = fopen("iii.txt", "w");
    fprintf(saida_gosper, "%s", resultado);
    fclose(saida_gosper);
    printf("tamanho da string apos a remoção: %ld\n", strlen(resultado));
    printf("string com %d iteracoes: %s\n", iteracoes, resultado);
    free(resultado);
    return 0;
}
