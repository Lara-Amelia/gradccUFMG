#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the expected size of the string based on recursion
int calcula_tamanho(int iteracoes)
{
   int tamanhon = 0;
   tamanhon = 1 + 9 * ((int)(pow(5, iteracoes) - 1) / 4);  // Apply the recurrence relation
   printf("Tamanho na iteração %d: %d\n", iteracoes, tamanhon);
   return tamanhon;
}

// Recursive function to generate the fractal
void gerar_fractal_von_koch(int iteracoes, char *resultado) 
{
    if (iteracoes == 0) 
    {
        return;
    }

    // Get the current length of the string (actual size of the result)
    int tamanho_string = strlen(resultado);

    // Create a temporary buffer for constructing the new string
    char *temp = (char *)malloc(tamanho_string * 9 + 1);
    temp[0] = '\0';  // Initialize as an empty string

    // Traverse the current string and apply the transformation rule
    for (int i = 0; i < tamanho_string; i++) 
    {
        if (resultado[i] == 'F') 
        {
            strcat(temp, "F++FF--F+F");  // Replace 'F' with the fractal rule
        } 
        else 
        {
            strncat(temp, &resultado[i], 1);  // Keep the other characters unchanged
        }
    }

    // Update the result with the new generated string
    strcpy(resultado, temp);

    // Free temporary memory used for building the string
    free(temp);

    // Recursive call to generate the next iteration of the fractal
    gerar_fractal_von_koch(iteracoes - 1, resultado);
}

int main() 
{
    char dados[100];
    int iteracoes = 0;
    printf("Digite o número de iterações desejado: \n");
    fgets(dados, 100, stdin);
    dados[strlen(dados)-1] = '\0';  // Remove the newline character
    sscanf(dados, "%d", &iteracoes);  

    // Calculate the size of the string after all iterations
    int tamanho_string = calcula_tamanho(iteracoes);

    // Allocate memory for the result string (final string size)
    char *resultado = (char *)malloc(tamanho_string + 1);
    resultado[0] = '\0';  // Initialize as an empty string

    // Add the initial axiom 'F'
    strcat(resultado, "F");

    // Generate the fractal by applying the transformation iteratively
    gerar_fractal_von_koch(iteracoes, resultado);

    // Print the result
    printf("Fractal von Koch após %d iterações: %s\n", iteracoes, resultado);
    printf("Tamanho da string: %ld\n", strlen(resultado));
    FILE *saida_koch = fopen("i.txt", "w");
    fprintf(saida_koch, "%s", resultado);
    fclose(saida_koch);

    // Free dynamically allocated memory
    free(resultado);

    return 0;
}

/*#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

//calcula o tamanho da string em uma certa iteração com base na expansão da equação de recorrência
int calcula_tamanho(int iteracoes)
{
   int tamanho0 = 1;
   int tamanho1 = 5;
   int tamanhon = 0;
   tamanhon = 1 + 9*(((int)pow(5, iteracoes)-1)/4);
   printf("tamanho na iteracao %d: %d\n", iteracoes, tamanhon);
   return tamanhon;
}

// gera o fractal de forma recursiva
void gerar_fractal_von_koch(int iteracoes, char **resultado, int tamanho_string) 
{
    if (iteracoes == 0) 
    {
        return;
    }

    //cria e inicializa como vazia uma string temporária que será usada na geração do resultado final
    //char temp[tamanho_string + 1];
    char *temp = (char *)malloc(tamanho_string + 1);
    temp[0] = '\0'; 

    //percorre a string atual e aplica a regra de substituição
    for (int i = 0; i < tamanho_string; i++) 
    {
        if (resultado[i] == 'F') 
        {
            strcat(temp, "F++FF--F+F");  // Substituir F pela regra
        } 
        else 
        {
            strncat(temp, resultado[i], 1);  // Manter os outros caracteres
        }
    }

    // Atualiza o resultado com a nova string gerada
    strcpy(*resultado, temp);

    // Chamada recursiva para a próxima iteração
    gerar_fractal_von_koch(iteracoes - 1, resultado, tamanho_string);
    free(temp);
}

int main() 
{
    char dados[100];
    int iteracoes = 0;
    printf("digite o número de iterações desejado: \n");
    fgets(dados, 100, stdin);
    dados[strlen(dados)-1] = '\0';
    sscanf(dados, "%d", &iteracoes);  
    int tamanho_string = calcula_tamanho(iteracoes);
    //char resultado[tamanho_string + 1];
    char *resultado = (char *)malloc(tamanho_string + 1);
    //inicializa resultado como uma string vazia
    resultado[0] = '\0';  
    //adiciona o axioma inical na string vazia
    strcat(resultado, "F");
    gerar_fractal_von_koch(iteracoes, &resultado, tamanho_string);
    printf("Fractal von Koch após %d iterações: %s\n", iteracoes, resultado);
    free(resultado);
    return 0;
}*/

