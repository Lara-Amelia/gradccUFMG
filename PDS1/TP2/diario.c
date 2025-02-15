#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
  char nome_aluno[100];
  int matricula;
  int notas[3];
              }aluno;

typedef struct{
  char nome_turma[100];
  char codigo[10];
  int alunos_por_turma;
  aluno alunos[6];
              }turma;

typedef struct{
  char nome_prof[100];
  int registro;
  int numero_turmas;
  turma turmas[2];
              }professor;

//CALCULA A NOTA FINAL DOS ALUNOS
int notafinal_aluno(int *notas)
{
   int nota_final = 0;
   int soma_notas = 0;
   for(int prova_x = 0; prova_x < 3; prova_x++)
   {
     soma_notas += notas[prova_x];
   }
   nota_final = soma_notas/3;
   return nota_final;
}

//OBTÉM O CONCEITO DO ALUNO COM BASE NA NOTA FINAL
char checa_conceito(int *nota_final)
{
    char conceito = 0;
    if(*nota_final < 40)
       conceito = 'F';
    else if(*nota_final >= 40 && *nota_final <=59)
       conceito = 'E';
    else if(*nota_final >= 60 && *nota_final <=69)
       conceito = 'D';
    else if(*nota_final >= 70 && *nota_final <= 79)
       conceito = 'C';
    else if(*nota_final >= 80 && *nota_final <= 89)
       conceito = 'B';
    else if(*nota_final >= 90 && *nota_final <= 100)
       conceito = 'A';
    return conceito;
}

void situacao_aluno(char conceito_aluno)
{
   if((conceito_aluno == 'A') || (conceito_aluno == 'B') || (conceito_aluno == 'C') || (conceito_aluno == 'D'))
     printf("Situacao: Aprovado\n");
   else if(conceito_aluno == 'E')
     printf("Situacao: Exame Especial\n");
   else if(conceito_aluno == 'F')
     printf("Situacao: Reprovado\n");
}

//REALIZA AS AÇÕES DO OPÇÃO 1
void info_prof(professor *p)
{
  printf("Professor %s\n", (*p).nome_prof);
  printf("Registro numero %d\n", (*p).registro);
  for(int m = 0; m < (*p).numero_turmas; m++)
  {
    printf("Turma %s - %s, %d alunos\n", (*p).turmas[m].codigo, (*p).turmas[m].nome_turma, (*p).turmas[m].alunos_por_turma);
  }
}

//REALIZA AS AÇÕES DA OPÇÃO 2
void info_aluno(int *matricula, char *codigo, professor *p)
{
  for(int count = 0; count < (*p).numero_turmas; count++)
  {
    //se o código inserido for igual ao código de alguma das turmas
    if(!(strcmp(codigo, (*p).turmas[count].codigo)))
    {
      for(int m = 0; m < (*p).turmas[count].alunos_por_turma; m++){
        if(*matricula == (*p).turmas[count].alunos[m].matricula)
        {
          printf("Aluno: %s\n", (*p).turmas[count].alunos[m].nome_aluno);
          printf("Matricula: %d\n", (*p).turmas[count].alunos[m].matricula);
          for(int numero_da_prova = 0; numero_da_prova < 3; numero_da_prova++){
            //consertar a formatação do printf
            printf("Prova %d: %d / ", (numero_da_prova + 1), (*p).turmas[count].alunos[m].notas[numero_da_prova]);
                                                                              }
          printf("\n");
          int nota_final = 0;
          char conceito = 0;
          nota_final = notafinal_aluno((*p).turmas[count].alunos[m].notas);
          conceito = checa_conceito(&nota_final);
          printf("Nota Final: %d - Conceito %c\n", nota_final, conceito);
        }
                                                                   }
    }
  }
}

//REALIZA AS AÇÕES DA OPÇÃO 3
void insere_aluno(professor *p, int *matricula, char *codigo, char *nome)
{
  //inicializar notas dos alunos inseridos como 0
  for(int count = 0; count < (*p).numero_turmas; count++)
  {
    if(!(strcmp(codigo, (*p).turmas[count].codigo))) //se o código for igual ao da turma buscada
    {
      (*p).turmas[count].alunos_por_turma++;
      int aluno_x;
      aluno_x = (*p).turmas[count].alunos_por_turma - 1;
      strcpy((*p).turmas[count].alunos[aluno_x].nome_aluno, nome);
      (*p).turmas[count].alunos[aluno_x].matricula = *matricula;
      for(int numero_prova = 0; numero_prova < 3; numero_prova++)
      {
          (*p).turmas[count].alunos[aluno_x].notas[numero_prova] = 0;
      }
      //debug - apagar depois
      printf("nro_alunos: %d\n", (*p).turmas[count].alunos_por_turma);
      printf("nome: %s\n", (*p).turmas[count].alunos[aluno_x].nome_aluno);
      printf("matricula: %d\n", (*p).turmas[count].alunos[aluno_x].matricula);
      printf("codigo: %s\n", (*p).turmas[count].codigo);
    }
  }
}

//REALIZA AS AÇÕES DA OPÇÃO 4 DO MENU
void lanca_notas(professor *p, int *matricula, char *codigo, int *notas)
{
  for(int count = 0; count < (*p).numero_turmas; count++)
  {
    if(!(strcmp(codigo, (*p).turmas[count].codigo))) //se encontrar um codigo igual ao inserido
    {
      for(int m = 0; m < (*p).turmas[count].alunos_por_turma; m++)
      {
        if(*matricula == (*p).turmas[count].alunos[m].matricula) //se a matricula a lançar nota existir
        {
           for(int numero_da_prova = 0; numero_da_prova < 3; numero_da_prova++)
           {
              (*p).turmas[count].alunos[m].notas[numero_da_prova] = notas[numero_da_prova];
              //debug - apagar depois
              printf("nome do aluno: %s\n", (*p).turmas[count].alunos[m].nome_aluno);
              printf("matricula do aluno: %d\n", (*p).turmas[count].alunos[m].matricula);
              printf("nota prova %d: %d\n", (numero_da_prova+1), (*p).turmas[count].alunos[m].notas[numero_da_prova]);
           }
        }
      }
    }
  }
}

//REALIZA AS AÇÕES DA OPÇÃO 5 DO MENU
void info_turma(char *codigo, professor *p)
{
  for(int count = 0; count < (*p).numero_turmas; count++)
  {
    if(!(strcmp((*p).turmas[count].codigo, codigo))) //se houver uma turma com o código fornecido
    {
      printf("Informações da turma %s - %s\n", (*p).turmas[count].codigo, (*p).turmas[count].nome_turma);
      printf("%d alunos\n", (*p).turmas[count].alunos_por_turma);
      for(int aluno_x = 0; aluno_x < (*p).turmas[count].alunos_por_turma; aluno_x++)
      {
        printf("Aluno: %s\n", (*p).turmas[count].alunos[aluno_x].nome_aluno);
        printf("Matricula: %d\n", (*p).turmas[count].alunos[aluno_x].matricula);
      }
    }
  }
}

//REALIZA AS AÇÕES DA OPÇÃO 6 DO MENU
void situacao_alunos_turma(professor *p, char *codigo)
{
   for(int count = 0; count < (*p).numero_turmas; count++)
   {
     if(!(strcmp((*p).turmas[count].codigo, codigo)))//se existir uma turma com o código buscado
     {
        printf("Situacao na Turma %s - %s\n", (*p).turmas[count].codigo, (*p).turmas[count].nome_turma);
        for(int aluno_x = 0; aluno_x < (*p).turmas[count].alunos_por_turma; aluno_x++)
        {
            printf("Aluno: %s\n", (*p).turmas[count].alunos[aluno_x].nome_aluno);
            printf("Matricula: %d\n", (*p).turmas[count].alunos[aluno_x].matricula);
            int nota_final = notafinal_aluno((*p).turmas[count].alunos[aluno_x].notas);
            char conceito_aluno = checa_conceito(&nota_final);
            printf("Nota Final: %d - Conceito %c\n", nota_final, conceito_aluno);
            situacao_aluno(conceito_aluno);
            //falta a situação - criar nova função
        }
     }
   }
}

//REALIZA A AÇÃO DA OPÇÃO 7 DO MENU
void exporta_dados(professor *p, char *arquivo_exportacao)
{
  FILE *arquivo2 = fopen(arquivo_exportacao, "w");
  fprintf(arquivo2, "DADOS EXPORTADOS\n\n\n");
  fprintf(arquivo2, "Professor %s - Registro %d\n\n\n", (*p).nome_prof, (*p).registro);
  for(int count = 0; count < (*p).numero_turmas; count++)
  {
    fprintf(arquivo2, "Turma %s - %s\n\n", (*p).turmas[count].codigo, (*p).turmas[count].nome_turma);
    for(int aluno_x = 0; aluno_x < (*p).turmas[count].alunos_por_turma; aluno_x++)
    {
      fprintf(arquivo2, "Aluno: %s\n\n", (*p).turmas[count].alunos[aluno_x].nome_aluno);
      fprintf(arquivo2, "Matricula: %d\n\n", (*p).turmas[count].alunos[aluno_x].matricula);
      int nota_final = notafinal_aluno((*p).turmas[count].alunos[aluno_x].notas);
      char conceito = checa_conceito(&nota_final);
      fprintf(arquivo2, "Nota Final: %d - Conceito %c - ", nota_final, conceito);
      if((conceito == 'A') || (conceito == 'B') || (conceito == 'C') || (conceito == 'D'))
        fprintf(arquivo2, "APROVADO\n\n");
      else if(conceito == 'E')
        fprintf(arquivo2, "EXAME ESPECIAL\n\n");
      else if(conceito == 'F')
        fprintf(arquivo2, "REPROVADO\n\n");
    }
  }
}

int main(int argc, char **argv)
{
  if(argc < 3){
    printf("erro, digite o nome dos 2 arquivos\n");
    exit(1);
              }
  char *arquivo_lido = argv[1];
  char *arquivo_exportacao = argv[2];
  FILE *arquivo = fopen(arquivo_lido, "r");
  if(arquivo == NULL){
    printf("erro ao abrir o arquivo\n");
    exit(2);
                     }
  char dados[300];
  professor prof;

  //LÊ O NOME DO PROFESSOR
  fgets(prof.nome_prof, 300, arquivo);
  prof.nome_prof[strlen(prof.nome_prof) - 1] = '\0';

  //LÊ O REGISTRO DO PROFESSOR
  fgets(dados, 300, arquivo);
  dados[strlen(dados) - 1] = '\0';
  sscanf(dados, "%d", &prof.registro);

  //LÊ O NÚMERO DE TURMAS DO PROFESSOR
  fgets(dados, 300, arquivo);
  dados[strlen(dados) - 1] = '\0';
  sscanf(dados, "%d", &prof.numero_turmas);

  //LÊ OS NOMES E CÓDIGOS DAS TURMAS DO PROFESSOR
  for(int i = 0; i < prof.numero_turmas; i++)
  {
     fgets(prof.turmas[i].nome_turma, 100, arquivo);
     prof.turmas[i].nome_turma[strlen(prof.turmas[i].nome_turma) - 1] = '\0';
     fgets(prof.turmas[i].codigo, 10, arquivo);
     prof.turmas[i].codigo[strlen(prof.turmas[i].codigo) - 1] = '\0';
  }

  //LÊ O NÚMERO DE ALUNOS DA PRIMEIRA TURMA
  int numero_da_turma = 1;
  fgets(dados, 5, arquivo);
  dados[strlen(dados) - 1] = '\0';
  sscanf(dados, "%d", &prof.turmas[0].alunos_por_turma);

  //LÊ O NOME E A MATRICULA DOS ALUNOS DA TURMA 1
  for(int j = 0; j < prof.turmas[0].alunos_por_turma; j++)
  {
    fgets(prof.turmas[0].alunos[j].nome_aluno, 100, arquivo);
    prof.turmas[0].alunos[j].nome_aluno[strlen(prof.turmas[0].alunos[j].nome_aluno) - 1] = '\0';
    fgets(dados, 15, arquivo);
    dados[strlen(dados) - 1] = '\0';
    sscanf(dados, "%d", &prof.turmas[0].alunos[j].matricula);
    //INICIALIZA AS NOTAS DE TODOS OS ALUNOS COMO 0
    for(int numero_da_prova = 0; numero_da_prova < 3; numero_da_prova++)
    {
      prof.turmas[0].alunos[j].notas[numero_da_prova] = 0;
    }
  }

  //LÊ O NÚMERO DE ALUNOS DA SEGUNDA TURMA, CASO EXISTA
  if(prof.numero_turmas == 2)
  {
    numero_da_turma++;
    fgets(dados, 5, arquivo);
    dados[strlen(dados) - 1] = '\0';
    sscanf(dados, "%d", &prof.turmas[1].alunos_por_turma);

    //LÊ OS NOMES E MATRICULAS DOS ALUNOS DA SEGUNDA TURMA, CASO ELA EXISTA
    for(int j = 0; j < prof.turmas[1].alunos_por_turma; j++)
    {
      fgets(prof.turmas[1].alunos[j].nome_aluno, 100, arquivo);
      prof.turmas[1].alunos[j].nome_aluno[strlen(prof.turmas[1].alunos[j].nome_aluno) - 1] = '\0';
      fgets(dados, 15, arquivo);
      dados[strlen(dados) - 1] = '\0';
      sscanf(dados, "%d", &prof.turmas[1].alunos[j].matricula);
      for(int numero_da_prova = 0; numero_da_prova < 3; numero_da_prova++)
      {
        prof.turmas[1].alunos[j].notas[numero_da_prova] = 0;
      }
    }
  }
  fclose(arquivo);

  //IMPRIME O MENU DE AÇÕES DO DIÁRIO DE CLASSE
  printf("1 - Informacoes do Professor\n2 - Informacoes do Aluno\n3 - Inserir Aluno\n4 - Lancar Notas\n5 - Informacoes da Turma\n6 - Situacao dos Alunos\n7 - Exportar Dados\n");

  //LÊ A OPÇÃO QUE SE DESEJA REALIZAR E DIRECIONA AS AÇÕES DE ACORDO COM A AÇÃO ESCOLHIDA
  int opcao_menu;
  do{
      fgets(dados, 5, stdin);
      sscanf(dados, "%d", &opcao_menu);
      switch(opcao_menu)
      {
        case 1: {
                   info_prof(&prof);
                }
        break;
        case 2: {
                   int matricula_pesquisa;
                   char codigo_turma_pesquisa[20];
                   fgets(dados, 10, stdin);
                   dados[strlen(dados) - 1] = '\0';
                   sscanf(dados, "%d", &matricula_pesquisa);
                   fgets(codigo_turma_pesquisa, 15, stdin);
                   codigo_turma_pesquisa[strlen(codigo_turma_pesquisa) - 1] = '\0';
                   info_aluno(&matricula_pesquisa, codigo_turma_pesquisa, &prof);
                   //falta média e conceito no caso 2 - fazer uma nova situação
                }
        break;
        case 3: {
                   char nome_inserido[50];
                   int matricula_inserida;
                   char cod_turma_insercao[10];
                   fgets(nome_inserido, 50, stdin);
                   nome_inserido[strlen(nome_inserido) - 1] = '\0';
                   fgets(dados, 15, stdin);
                   dados[strlen(dados) - 1] = '\0';
                   sscanf(dados, "%d", &matricula_inserida);
                   fgets(cod_turma_insercao, 10, stdin);
                   cod_turma_insercao[strlen(cod_turma_insercao) - 1] = '\0';
                   insere_aluno(&prof, &matricula_inserida, cod_turma_insercao, nome_inserido);
               }
        break;
        case 4: {
                   int matricula_lancamento;
                   char cod_turma_lancamento[10];
                   int notas_lancamento[3];
                   fgets(dados, 15, stdin);
                   dados[strlen(dados) - 1] = '\0';
                   sscanf(dados, "%d", &matricula_lancamento);
                   fgets(cod_turma_lancamento, 10, stdin);
                   cod_turma_lancamento[strlen(cod_turma_lancamento) - 1] = '\0';
                   fgets(dados, 15, stdin);
                   dados[strlen(dados) - 1] = '\0';
                   sscanf(dados, "%d %d %d", &notas_lancamento[0], &notas_lancamento[1], &notas_lancamento[2]);
                   lanca_notas(&prof, &matricula_lancamento, cod_turma_lancamento, notas_lancamento);
                }
        break;
        case 5: {
                   char cod_turma_pesquisada[10];
                   fgets(cod_turma_pesquisada, 10, stdin);
                   cod_turma_pesquisada[strlen(cod_turma_pesquisada) - 1] = '\0';
                   info_turma(cod_turma_pesquisada, &prof);
                }
        break;
        case 6: {
                  char cod_turma_buscada[10];
                  fgets(cod_turma_buscada, 10, stdin);
                  cod_turma_buscada[strlen(cod_turma_buscada) - 1] = '\0';
                  situacao_alunos_turma(&prof, cod_turma_buscada);
                }
        break;
        case 7: {
                  exporta_dados(&prof, arquivo_exportacao);
                }
        break;
    }
  }while (opcao_menu != 7);
  return 0;
}
