#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX_LEN 10000

float calcula_tamanho_hilbert(int iteracoes)
{
    float tamanho = 0;
    tamanho = ((10.0/3.0)*pow(4, iteracoes)) - 4.0/3.0;
    printf("função - tamanho com %d iteracoes: %d\n", iteracoes, (int)tamanho);
    return tamanho;
}

void gerar_esp_hilbert(int iteracoes, char *resultado, int tamanho_hilbert)
{
    if(iteracoes == 0)
    {
        return;
    }
    char* temp = (char*)malloc(tamanho_hilbert);
    temp[0] = '\0';

    for(int i = 0; i < strlen(resultado); i++)
    {
        if(resultado[i] == 'X')
        {
            strcat(temp, "-YF+XFX+FY-");
        }
        else if(resultado[i] == 'Y')
        {
            strcat(temp, "+XF-YFY-FX+");
        }
        else
        { 
            //concatena o caractere analisado à string temporária
            strncat(temp, &resultado[i], 1);
        }
    }
    strcpy(resultado, temp);
    gerar_esp_hilbert(iteracoes - 1, resultado, tamanho_hilbert);
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

int main(void)
{
    char axioma = 'X';
    char regrax[12] = "-YF+XFX+FY-";
    char regray[12] = "+XF-YFY-FX+";
    int iteracoes;
    char dados[50];
    printf("digite o número de iterações desejadas: ");
    fgets(dados, 50, stdin);
    dados[strlen(dados) - 1] = '\0';
    sscanf(dados, "%d", &iteracoes);
    int tamanho_hilbert = calcula_tamanho_hilbert(iteracoes);
    char* resultado = (char*)malloc(tamanho_hilbert);
    //inicializa resultado como uma string vazia
    resultado[0] = '\0';
    strcat(resultado, "X");
    gerar_esp_hilbert(iteracoes, resultado, tamanho_hilbert);
    printf("string antes de remoção: %s\n", resultado);
    printf("tamano da string antes da remoção: %ld\n", strlen(resultado));
    remove_xy(resultado);
    FILE *saida_hilbert = fopen("ii.txt", "w");
    fprintf(saida_hilbert, "%s", resultado);
    fclose(saida_hilbert);
    printf("string com %d iteracoes: %s\n", iteracoes, resultado);
    printf("tamanho da string resultante: %ld\n", strlen(resultado));
    return 0;
}
