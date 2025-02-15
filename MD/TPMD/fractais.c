#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//As expressões para o cálculo dos tamanhos das strings foram obtidas através das equações de recorrência

//Calcula o tamanho da string final do fractal i (Onda Senoidal 1 de von Koch)
float calcula_tamanho_koch(int iteracoes)
{
   float tamanho = 0;
   tamanho = (1.0/5.0)*((11*pow(6, iteracoes)) - 6);  
   return tamanho;
}

//Calcula o tamanho da string final do fractal ii (Preenchimento de Espaço de Hilbert)
float calcula_tamanho_hilbert(int iteracoes)
{
    float tamanho = 0;
    tamanho = ((10.0/3.0)*pow(4, iteracoes)) - 7.0/3.0;
    return tamanho;
}

//Calcula o tamanho da string final do fractal iii (Hexagonal Gosper de Mandelbrot)
float calcula_tamanho_gosper(int iteracoes)
{
    float tamanho = 0;
    tamanho = (pow(7, iteracoes)*10.0/3.0) - 4.0/3.0;
    return tamanho;
}

//Função utilizada para gerar o fractal i (Onda Senoidal 1 de von Koch)
void gerar_fractal_von_koch(int iteracoes, char *resultado_koch, char* temp_koch) 
{
   for(int j = 0; j < iteracoes; j++)
   {
       temp_koch[0] = '\0';
       int tamanho_string = strlen(resultado_koch);
       for (int i = 0; i < tamanho_string; i++) 
       {
           if (resultado_koch[i] == 'F') 
           {         
               strcat(temp_koch, "F+F--FF++F-F");
           } 
           else 
           {
               strncat(temp_koch, &resultado_koch[i], 1);  
           }
       }
       strcpy(resultado_koch, temp_koch);
    }
}

//Função utilizada para gerar os fractais ii e iii (Espaço de Hilbert e Hexagonal Gosper), com os símbolos X e Y
void gerar_fractais_ii_iii(int iteracoes, char *resultado, char* regrax, char* regray, char* temp)
{
    for(int j = 0; j < iteracoes; j++)
    {
        temp[0] = '\0';
        for(int i = 0; i < strlen(resultado); i++)
        {
           if(resultado[i] == 'X')
           {
               strcat(temp, regrax);
           }
           else if(resultado[i] == 'Y')
           {
               strcat(temp, regray);
           }
           else
           {   
               //concatena o caractere analisado à string temporária
               strncat(temp, &resultado[i], 1);
           }
       }
       strcpy(resultado, temp);
    }
}

//Função utilizada para remover os símbolos X e Y na geração dos fractais ii e iii
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
    //Obtém a quantidade de iterações da entrada padrão
    printf("Digite o número de iterações desejado: \n");
    char dados[50];
    int iteracoes;
    fgets(dados, 50, stdin);
    dados[strlen(dados) - 1] = '\0';
    sscanf(dados, "%d", &iteracoes);

    //Utiliza a função para o tamanho do fractal de Koch (i) na iteração desejada
    //"Prepara" as strings que serão utilizadas na geração do fractal de Koch
    int tamanho_koch = calcula_tamanho_koch(iteracoes);
    char* resultado_koch = (char*)malloc(tamanho_koch + 1);
    if(resultado_koch == NULL)
    {
        printf("Erro na alocação de memória para resultado_koch\n");
        return EXIT_FAILURE;
    }
    resultado_koch[0] = '\0';
    char* temp_koch = (char*)malloc(tamanho_koch + 1);
    if(temp_koch == NULL)
    {
        printf("Erro na alocação de memória para temp_koch\n");
        return EXIT_FAILURE;
    }
    temp_koch[0] = '\0';

    //Utiliza a função para o tamanho do fractal de Hilbert (ii) na iteração desejada
    //"Prepara" as strings que serão utilizadas na geração do fractal de Hilbert
    int tamanho_hilbert = calcula_tamanho_hilbert(iteracoes);
    char* resultado_hilbert = (char*)malloc(tamanho_hilbert + 1);
    if(resultado_hilbert == NULL)
    {
        printf("Erro na alocação de memória para resultado_hilbert\n");
        return EXIT_FAILURE;
    }
    resultado_hilbert[0] = '\0';
    char* temp_hilbert = (char*)malloc(tamanho_hilbert + 1);
    if(temp_hilbert == NULL)
    {
        printf("Erro na alocação de memória para temp_hilbert\n");
        return EXIT_FAILURE;
    }
    temp_hilbert[0] = '\0';

    //Utiliza a função para o tamanho do fractal Gosper (iii) na iteração desejada
    //"Prepara" as strings que serão utilizada sna geração do fractal Gosper
    int tamanho_gosper = calcula_tamanho_gosper(iteracoes);
    char* resultado_gosper = (char*)malloc(tamanho_gosper + 1);
    if(resultado_gosper == NULL)
    {
        printf("Erro na alocação de memória para resultado_gosper\n");
        return EXIT_FAILURE;
    }
    resultado_gosper[0] = '\0';
    char* temp_gosper = (char*)malloc(tamanho_gosper + 1);
    if(temp_gosper == NULL)
    {
        printf("Erro na alocação de memória para temp_gosper\n");
        return EXIT_FAILURE;
    }
    temp_gosper[0] = '\0';

    //Utiliza a função gerar_fractal_von_koch para gerar a string do fractal de Koch (i) 
    strcat(resultado_koch, "F");
    gerar_fractal_von_koch(iteracoes, resultado_koch, temp_koch);
    //Faz a impressão do resultado obtido no arquivo de saída correspondente, i.txt
    FILE *saida_koch = fopen("i.txt", "w");
    if(saida_koch == NULL)
    {
        printf("Houve um erro para abrir o arquivo i.txt\n");
        return EXIT_FAILURE;
    }
    else
    {
        fprintf(saida_koch, "%s", resultado_koch);
        fclose(saida_koch);
    }
    free(temp_koch);
    free(resultado_koch);

    //Utiliza as funções gerar_fractais_ii_iii e remove_xy para obter o fractal de Hilbert (ii)
    char axioma_hilbert[5] = "X";
    strcat(resultado_hilbert, axioma_hilbert);
    char regrax_hilbert[12] = "-YF+XFX+FY-";
    char regray_hilbert[12] = "+XF-YFY-FX+";
    gerar_fractais_ii_iii(iteracoes, resultado_hilbert, regrax_hilbert, regray_hilbert, temp_hilbert);
    remove_xy(resultado_hilbert);
    //Faz a impressão do resultado obtido no arquivo de saída correspondente, ii.txt
    FILE *saida_hilbert = fopen("ii.txt", "w");
    if(saida_hilbert == NULL)
    {
        printf("Houve um erro para abrir o arquivo ii.txt\n");
        return EXIT_FAILURE;
    }
    else
    {
        fprintf(saida_hilbert, "%s", resultado_hilbert);
        fclose(saida_hilbert);
    }
    free(temp_hilbert);
    free(resultado_hilbert);

    //Utiliza as funções gerar_fractais_ii_iii para gerar o fractal Gosper (iii)
    char axioma_gosper[5] = "XF";
    strcat(resultado_gosper, axioma_gosper);
    char regrax_gosper[50] = "X+YF++YF-FX--FXFX-YF+";
    char regray_gosper[50] = "-FX+YFYF++YF+FX--FX-Y";
    gerar_fractais_ii_iii(iteracoes, resultado_gosper, regrax_gosper, regray_gosper, temp_gosper);
    remove_xy(resultado_gosper);
    //Faz a impressão do resultado obtido no arquivo de saída correspondente, iii.txt
    FILE *saida_gosper = fopen("iii.txt", "w");
    if(saida_gosper == NULL)
    {
        printf("Houve um erro para abrir o arquivo iii.txt\n");
        return EXIT_FAILURE;
    }
    else
    {
        fprintf(saida_gosper, "%s", resultado_gosper);
        fclose(saida_gosper);
    }
    free(temp_gosper);
    free(resultado_gosper);
    return 0;
}