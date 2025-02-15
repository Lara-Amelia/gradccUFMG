#include <stdio.h>
#include <stdlib.h>


int *cria_matriz(int n_linhas, int n_colunas)
{
  int *matriz = (int*) malloc(n_linhas*n_colunas*sizeof(int));
  return matriz;
}

void libera_matriz(int *matriz, int n_linhas, int n_colunas)
{
  free(matriz);
}

void preenche_matriz(int *m, int n_linhas, int n_colunas)
{
  for (int i = 0; i < n_linhas; i++)
  {
    for (int j = 0; j < n_colunas; j++)
    {
      printf("Digite o elemento a[%d][%d]: ", i, j);
      scanf("%d", &m[i*n_colunas + j]);
    }
  }
}

void imprime_matriz(int *m, int n_linhas, int n_colunas)
{
  for (int i = 0; i < n_linhas; i++)
  {
    for (int j = 0; j < n_colunas; j++)
    {
      printf("%3d", m[i*n_colunas +j]);
    }
    printf("\n");
  }
}


int main()
{
  int l,c;
  printf("Digite o número de linhas e colunas: ");
  scanf("%d %d", &l, &c);
  int *m = cria_matriz(l,c);
  preenche_matriz(m,l,c);
  imprime_matriz(m,l,c);
  libera_matriz(m,l,c);
  return EXIT_SUCCESS;
}
