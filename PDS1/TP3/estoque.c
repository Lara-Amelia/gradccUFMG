#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct produto{
   int identificador;
   char nome[50];
   char departamento[50];
   float preco;
   struct produto *esq;
   struct produto *dir;
                       }produto;

//Aloca espaço para um novo nó e insere as informações recebidas em uma struct produto
produto* novo_noh(int identificador, char *nome, char *departamento, float preco);

/*Recebe o novo nó e percorre a árvore já existente, inserindo o nó no local correto -
  é usada na leitura do arquivo e na opção 3 do menu*/
produto* insere_na_arvore(produto *pai, produto *prod_lido);

//Lê as informações do arquivo e utiliza as funções anteriores para gerar a Árvore Binária de Busca
void le_arquivo(produto **p, char *arquivo_entrada);

/* Realiza as ações da opção 1 do menu - percorre a árvore existente
   até encontrar (ou não) a ID desejada e imprime os produtos no caminho percorrido*/
produto* busca_produto(produto *raiz, int id_busca);


//As 3 funções seguintes são utilizadas para a opção 2 do menu ////////////////////////////////////////////

//conta quantos produtos do departamento buscado existem na árvore
void conta_dpto(produto *raiz, char *dpto_busca, int *numero);

//busca e armazena os produtos do departamento buscado em um vetor de produtos
produto* busca_dpto(produto *raiz, char *dpto_busca, produto *vetor, int *indice, int numero);

//ordena o vetor de produtos obtido de acordo com as suas IDs
void ordena_vetor_id(produto *vetor, int numero);

///////////////////////////////////////////////////////////////////////////////////////////////////////////


//As 3 funções seguintes são utilizadas para a opção 4 do menu////////////////////////////////////////////

//conta a quantidade de produtos com preço menor ou igual ao orçamento dado
void conta_precos(produto *raiz, float orcamento, int *numero);

//busca e armazena os produtos com valor menor ou igual ao orçamento em um vetor de produtos
produto* busca_precos(produto *raiz, float orcamento, produto *vetor, int *indice, int numero );

//ordena o vetor de produtos obtido em ordem crescente de preços
void ordena_vetor_preco(produto *vetor, int numero);

/////////////////////////////////////////////////////////////////////////////////////////////////////////

//Libera a memória utilizada na Árvore Binária de Busca
void libera_arvore(produto *raiz);


int main(int argc, char **argv)
{
    if(argc < 2)
    {
        printf("Erro, favor digitar o nome do arquivo de entrada.\n");
        exit(1);
    }
    char *arquivo_entrada = argv[1];
    produto *raiz = NULL;
    le_arquivo(&raiz, arquivo_entrada);
    printf("1 - Procurar por ID\n2 - Procurar por Departamento\n3 - Inserir Produto\n4 - Filtrar por Preco\n5 - Sair\n");
    char dados[120];
    int opcao_menu;
    do{
        fgets(dados, 3, stdin);
        dados[strlen(dados) - 1] = '\0';
        sscanf(dados, "%d", &opcao_menu);
        switch(opcao_menu)
        {
            case 1: {
                       int id_pesquisa;
                       fgets(dados, 5, stdin);
                       dados[strlen(dados) - 1] = '\0';
                       sscanf(dados, "%d", &id_pesquisa);

                       busca_produto(raiz, id_pesquisa);
                    }
            break;
            case 2: {
                        char dpto_busca[50];
                        int numero = 0;
                        fgets(dados, 55, stdin);
                        dados[strlen(dados) - 1] = '\0';
                        sscanf(dados, "%s", dpto_busca);

                        conta_dpto(raiz, dpto_busca, &numero);
                        if(numero == 0)
                        {
                           printf("Departamento vazio!\n");
                        }
                        else
                        {
                           int indice = 0;
                           produto *vetor = NULL;
                           vetor = (produto*)realloc(vetor, sizeof(produto) * numero);
                           if(vetor == NULL)
                           {
                              printf("Erro ao alocar memória\n");
                              exit(2);
                           }
                           busca_dpto(raiz, dpto_busca, vetor, &indice, numero);
                           ordena_vetor_id(vetor, numero);
                           free(vetor);
                        }
                    }
            break;
            case 3: {
                       int id_insercao;
                       char nome_insercao[50];
                       char dpto_insercao[50];
                       float preco_insercao;
                       fgets(dados, 120, stdin);
                       dados[strlen(dados) - 1] = '\0';
                       sscanf(dados, "%d %s %s %f", &id_insercao, nome_insercao, dpto_insercao, &preco_insercao);

                       produto *novo = novo_noh(id_insercao, nome_insercao, dpto_insercao, preco_insercao);
                       insere_na_arvore(raiz, novo);
                    }
            break;
            case 4: {
                       float vlr_orcamento;
                       int numero = 0;
                       fgets(dados, 10, stdin);
                       dados[strlen(dados) - 1] = '\0';
                       sscanf(dados, "%f", &vlr_orcamento);

                       conta_precos(raiz, vlr_orcamento, &numero);
                       if(numero == 0)
                       {
                          printf("Sem resultados para o filtro!\n");
                       }
                       else
                       {
                          int indice = 0;
                          produto *vetor = NULL;
                          vetor = (produto*)realloc(vetor, sizeof(produto) * numero);
                          if(vetor == NULL)
                          {
                             printf("Erro ao alocar memória\n");
                             exit(3);
                          }
                          busca_precos(raiz, vlr_orcamento, vetor, &indice, numero);
                          ordena_vetor_preco(vetor, numero);
                          free(vetor);
                       }
                    }
            break;
            case 5: {
                       libera_arvore(raiz);
                    }
            break;
        }
      }while(opcao_menu != 5);
    return 0;
}


produto* novo_noh(int identificador, char *nome, char *departamento, float preco)
{
    produto *novo = NULL;
    //Aloca espaço para o novo nó a ser inserido na árvore
    novo = (produto*)malloc(sizeof(produto));
    if(novo == NULL)
    {
        printf("Erro ao alocar memória\n");
        exit(4);
    }
    //Insere as informações do nó na struct e inicializa os ponteiros para nós filhos como NULL
    (*novo).identificador = identificador;
    strcpy((*novo).nome, nome);
    strcpy((*novo).departamento, departamento);
    (*novo).preco = preco;
    (*novo).esq = NULL;
    (*novo).dir = NULL;
    return novo;
}

//Insere o produto recebido na árvore - Leitura do arquivo e opção 3 do menu
produto* insere_na_arvore(produto *raiz, produto *prod_lido)
{
    if(raiz == NULL) //ao encontrar o ponteiro nulo onde será colocado o novo nó
    {
       return prod_lido;
    }
    if((*prod_lido).identificador < (*raiz).identificador)
    {
        (*raiz).esq = insere_na_arvore((*raiz).esq, prod_lido);
    }
    else if((*prod_lido).identificador > (*raiz).identificador)
    {
        (*raiz).dir = insere_na_arvore((*raiz).dir, prod_lido);
    }
    return raiz;
}

//Faz a leitura do arquivo de entrada e a "montagem" da Árvore Binária de Busca
void le_arquivo(produto **raiz, char *arquivo_entrada)
{
    FILE *arquivo = fopen(arquivo_entrada, "r");
    if(arquivo == NULL)
    {
       printf("Erro ao abrir o arquivo de entrada\n");
       exit(5);
    }
    char dados[120];

    //Lê os dados do primeiro produto e cria a raiz inicial da árvore binária
    if(fgets(dados, 120, arquivo) != NULL)
    {
      int id;
      char nome[50];
      char dpto[50];
      float preco;
      dados[strcspn(dados, "\n")] = '\0';
      sscanf(dados, "%d %s %s %f", &id, nome, dpto, &preco);
      *raiz = novo_noh(id, nome, dpto, preco); //aloca o primeiro nó
    }

    //Lê os demais produtos do arquivo e encaminha os dados lidos para a função de inserção na árvore
    while((fgets(dados, 120, arquivo)) != NULL)
    {
        int id;
        char nome[50];
        char dpto[50];
        float preco;
        dados[strcspn(dados, "\n")] = '\0';
        sscanf(dados, "%d %49s %49s %f", &id, nome, dpto, &preco);
        //aloca espaço para o produto lido
        produto *novo = novo_noh(id, nome, dpto, preco);
        //insere o produto lido na árvore
        insere_na_arvore(*raiz, novo);
    }
    fclose(arquivo);
}

//Realiza as ações da opção 1 do menu
produto* busca_produto(produto *raiz, int id_busca)
{
     if(raiz == NULL)
     {
        printf("Produto nao encontrado!\n");
        return NULL;
     }
     printf("(%s) %s - R$%.2f\n", (*raiz).departamento, (*raiz).nome, (*raiz).preco);

     if(id_busca < (*raiz).identificador)
        return busca_produto((*raiz).esq, id_busca);

     else if(id_busca > (*raiz).identificador)
        return busca_produto((*raiz).dir, id_busca);

     else
        return raiz;
}

//Conta quantos produtos do departamento buscado existem na árvore - opção 2 do menu
void conta_dpto(produto *raiz, char *dpto_busca, int *numero)
{
   if(raiz == NULL)
   {
      return; //finaliza a recursão ao chegar em um ponteiro nulo (sem informação)
   }
   else
   {
      conta_dpto((*raiz).esq, dpto_busca, numero); //percorre a subárvore esquerda da árvore

      //incrementa a variável número caso seja encontrado um produto do dpto desejado
      if(!(strcmp((*raiz).departamento, dpto_busca)))
      {
         (*numero)++;
      }

      conta_dpto((*raiz).dir, dpto_busca, numero); //percorre a subárvore direita da árvore
   }
}

//Procura e armazena em um vetor os produtos do departamento buscado existentes na árvore - opção 2 do menu
produto* busca_dpto(produto *raiz, char *dpto_busca, produto *vetor, int *indice, int numero)
{
   if(*indice >= numero || raiz == NULL) //para a recursão caso encontre um nó vazio ou ultrapasse os limites da memória alocada
   {
      return vetor;
   }
   busca_dpto((*raiz).esq, dpto_busca, vetor, indice, numero); //percorre a subárvore esquerda da árvore

   //caso seja encontrado um nó do departamento desejado, o armazena no vetor
   if(!(strcmp((*raiz).departamento, dpto_busca)))
   {
       vetor[*indice] = *raiz;
       (*indice)++;
       if(*indice >= numero) //para a recursão caso o limite da memória alocada seja ultrapassado
       {
           return vetor;
       }
   }

   busca_dpto((*raiz).dir, dpto_busca, vetor, indice, numero); //percorre a subárvore direita da árvore
   return vetor;
}

//Ordena os produtos do vetor obtido em ordem crescente de IDs - opção 2 do menu
void ordena_vetor_id(produto *vetor, int numero)
{
   produto temp;

 /* Compara o conteúdo de cada posição do vetor com o conteúdo da posição seguinte -
    caso o elemento analisado (posição i) seja maior que o seguinte (posição j), os conteúdos das posições analisadas são trocados */
   for(int i = 0; i < numero - 1; i++)
   {
      for(int j = i + 1; j < numero; j++)
      {
         if(vetor[i].identificador > vetor[j].identificador)
         {
            temp = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = temp;
         }
      }
   }

   //imprime as informações do vetor já ordenado
   for(int m = 0; m < numero; m++)
   {
      printf("(%s) %s - R$ %.2f\n", vetor[m].departamento, vetor[m].nome, vetor[m].preco);
   }
}

//Conta quantos produtos com preço dentro do orçamento desejado existem na árvore - opção 4 do menu
void conta_precos(produto *raiz, float orcamento, int *numero)
{
   if(raiz == NULL)
   {
      return;
   }
   else
   {
      conta_precos((*raiz).esq, orcamento, numero); //percorre a subárvore esquerda da árvore

      //incrementa a variável número se for encontrado um produto com preço menor ou igual ao orçamento
      if((*raiz).preco <= orcamento)
      {
         (*numero)++;
      }

      conta_precos((*raiz).dir, orcamento, numero); //percorre a subárvore direita da árvore
   }
}

//Procura e armazena em um vetor os produtos com preço dentro do orçamento existentes na árvore - opção 4 do menu
produto* busca_precos(produto *raiz, float orcamento, produto *vetor, int *indice, int numero)
{
   if(*indice >= numero || raiz == NULL) //para a recursão caso encontre um nó vazio ou sejam ultrapassados os limites da memória alocada para o vetor
   {
      return vetor;
   }
   busca_precos((*raiz).esq, orcamento, vetor, indice, numero);
   if((*raiz).preco <= orcamento)
   {
      vetor[*indice] = *raiz;
      (*indice)++;
      if(*indice >= numero)
      {
          return vetor; //para a recursão caso sejam ultrapassados os limites da memória alocada para o vetor
      }
   }
   busca_precos((*raiz).dir, orcamento, vetor, indice, numero);
   return vetor;
}

//Ordena o vetor obtido em ordem crescente de preços - opção 4 do menu
void ordena_vetor_preco(produto *vetor, int numero)
{
   produto temp;

   /* Compara o conteúdo de cada posição do vetor com o conteúdo da posição seguinte -
    caso o elemento analisado (posição i) seja maior que o seguinte (posição j), os conteúdos das posições analisadas são trocados */
   for(int i = 0; i < numero - 1; i++)
   {
      for(int j = i + 1; j < numero; j++)
      {
         if(vetor[i].preco > vetor[j].preco)
         {
            temp = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = temp;
         }
      }
   }

   //imprime as informações do vetor já ordenado
   for(int m = 0; m < numero; m++)
   {
      printf("(%s) %s - R$ %.2f\n", vetor[m].departamento, vetor[m].nome, vetor[m].preco);
   }
}

//Libera a memória alocada para os nós da árvore ao finalizar a execução do programa (opção 5 do menu)
void libera_arvore(produto *raiz)
{
   if(raiz == NULL)            //para a recursão caso encontre um nó vazio
   {
      return;
   }
   libera_arvore((*raiz).esq); //libera subárvores da esquerda
   libera_arvore((*raiz).dir); //libera subárvores da direita
   free(raiz);                 //libera a raiz da árvore (primeiro nó)
}
