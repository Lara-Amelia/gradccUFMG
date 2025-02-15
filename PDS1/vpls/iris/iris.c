#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct{
    float comp_sepala;
    float larg_sepala;
    float comp_petala;
    float larg_petala;
    char tipo[50];
              }iris;

void classificar(iris *nao_id, iris reg_id[], int n)
{
   float dist[n];
   float menor = INFINITY;
   int indice_menor = 0;
   for(int j = 0; j < n; j++)
   {
       dist[j] = 0;
       dist[j] += pow((*nao_id).comp_sepala - reg_id[j].comp_sepala, 2);
       dist[j] += pow((*nao_id).larg_sepala - reg_id[j].larg_sepala, 2);
       dist[j] += pow((*nao_id).comp_petala - reg_id[j].comp_petala, 2);
       dist[j] += pow((*nao_id).larg_petala - reg_id[j].larg_petala, 2);
       printf("distancia %d: %f\n", j+1, dist[j]);
       if(menor >= dist[j])
       {
          menor = dist[j];
          printf("menor distancia: %f\n", menor);
          indice_menor = j;
       }
   }
   if(indice_menor != -1)
   {
       printf("%s\n", reg_id[indice_menor].tipo);
   }
}

int main(void)
{
  char dados[100];
  int n;
  fgets(dados, 15, stdin);
  dados[strlen(dados) - 1] = '\0';
  sscanf(dados, "%d", &n);
  iris registros[n];
  for(int i = 0; i < n; i++)
  {
      fgets(dados, 100, stdin);
      dados[strlen(dados) - 1] = '\0';
      sscanf(dados, "%f %f %f %f %s", &registros[i].comp_sepala, &registros[i].larg_sepala, &registros[i].comp_petala, &registros[i].larg_sepala, registros[i].tipo);
  }
  iris nao_identificada = {0.0, 0.0, 0.0, 0.0, "desconhecido"};
  fgets(dados, 100, stdin);
  dados[strlen(dados) - 1] = '\0';
  sscanf(dados, "%f %f %f %f", &nao_identificada.comp_sepala, &nao_identificada.larg_sepala, &nao_identificada.comp_petala, &nao_identificada.larg_petala);
  classificar(&nao_identificada, registros, n);
  return 0;
}
