#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
     char nome[50];
     int idade;
     char telefone[20]; //maximo 20 caracteres(loop while)
              }cadastro;

int main(void)
{
    //OBTEM O NOME DO ARQUIVO E GERA O SEU PONTEIRO DE ARQUIVO
    char arquivo_analisado[50];
    fgets(arquivo_analisado, 50, stdin);
    arquivo_analisado[strlen(arquivo_analisado)-1] = '\0';

    FILE *arquivo;
    arquivo = fopen(arquivo_analisado, "r+b");
    //CHECA SE O ARQUIVO EXISTE OU NÃO
    if(arquivo == NULL)
      {
       perror("Error");
       return EXIT_FAILURE;
      }
    //DEFINE A QUANTIDADE DE CONTATOS QUE PODEM EXISTIR NA AGENDA
    cadastro agenda[100];
    char dados[100];
    cadastro leitura;
    int nro_registros = 0; //usado em inserir e em excluir

    //LÊ OS REGISTROS QUE JÁ EXISTEM NO ARQUIVO
    while(fread(&leitura, sizeof(cadastro), 1, arquivo) == 1)
    {
      strcpy(agenda[nro_registros].nome, leitura.nome);
      agenda[nro_registros].idade = leitura.idade;
      strcpy(agenda[nro_registros].telefone, leitura.telefone);
      nro_registros++;
    }

    fclose(arquivo);

    cadastro inserido;
    char acao[20];
    do{
      fgets(dados, 30, stdin);
      dados[strlen(dados)-1]= '\0';
      if(strlen(dados) == 0)
      {
         break;
      }
      sscanf(dados, "%s", acao);

      if(!strcmp(acao, "Inserir"))
      {
         if(nro_registros >= 100)
           printf("Espaco insuficiente");
         else
         {
          fgets(dados, 100, stdin);
          dados[strlen(dados)-1] = '\0';
          sscanf(dados, "%s %d %s", inserido.nome, &inserido.idade, inserido.telefone);
          agenda[nro_registros] = inserido;
          nro_registros++;

          arquivo = fopen(arquivo_analisado, "ab"); //ABRE O ARQUIVO PARA APPEND
          if(arquivo == NULL)
           {perror("Error");
            return EXIT_FAILURE;}
          if(fwrite(&inserido, sizeof(cadastro), 1, arquivo)!=1)
             printf("erro na escrita");
          else
             printf("Registro %s %d %s inserido\n", inserido.nome, inserido.idade, inserido.telefone);
         }
         fclose(arquivo); //FECHA O ARQUIVO
      }

      else if(!strcmp(acao, "Exibir"))
      {
         char nome_pesquisa[50];
         cadastro busca;
         int encontrado = 0;

         arquivo = fopen(arquivo_analisado, "rb");
         if(arquivo == NULL)
         {
            perror("Erro");
            return EXIT_FAILURE;
         }
         //LE O NOME DO CADASTRO QUE SE DESEJA EXIBIR
         fgets(dados, 50, stdin);
         dados[strlen(dados)-1] = '\0';
         sscanf(dados, "%s", nome_pesquisa);
         while(fread(&busca, sizeof(cadastro), 1, arquivo) == 1)
         {
            printf("registro existente: %s %d %s\n", busca.nome, busca.idade, busca.telefone);
            if(!strcmp(busca.nome, nome_pesquisa))
            {
                printf("Registro %s %d %s exibido\n", busca.nome, busca.idade, busca.telefone);
                encontrado = 1;
                break;
            }
         }
         if(!encontrado) //para ocorrer, encontrado=0
           {printf("Registro inválido\n");}
         fclose(arquivo);
      }

      else if(!strcmp(acao, "Alterar"))
      {
         char nome_pesquisa[50];
         cadastro busca;
         int encontrado = 0;
         arquivo = fopen(arquivo_analisado, "r+b");
         //LÊ O NOME DO ARQUIVO QUE SERÁ ALTERADO
         fgets(dados, 50, stdin);
         dados[strlen(dados)-1] = '\0';
         sscanf(dados, "%s", nome_pesquisa);

         while(fread(&busca, sizeof(cadastro), 1, arquivo) == 1)
         {
            if(!strcmp(busca.nome, nome_pesquisa))
            {
               fgets(dados, 100, stdin);
               dados[strlen(dados)-1] = '\0';
               sscanf(dados, "%s %d %s", busca.nome, &busca.idade, busca.telefone);
               if(fwrite(&busca, sizeof(cadastro), 1, arquivo) == 1)
               {
                  fseek(arquivo, -sizeof(cadastro), SEEK_CUR);
                  fwrite(&busca, sizeof(cadastro), 1, arquivo);
                  encontrado = 1;
                  printf("Registro %s %d %s alterado\n", busca.nome, busca.idade, busca.telefone);
                  break;
               }
            }
            if(!encontrado)
            {
              printf("Registro %s inválido\n", nome_pesquisa);
            }
         }
         fclose(arquivo);
      }

      else if(!strcmp(acao, "Excluir"))
      {
         char nome_pesquisa[50];
         cadastro busca;
         int encontrado = 0;
         fgets(dados, 50, stdin);
         dados[strlen(dados)-1] = '\0';
         sscanf(dados, "%s", nome_pesquisa);
         //ABRE ARQUIVO ORIGINA E CHECA SE CORREU BEM
         arquivo = fopen(arquivo_analisado, "rb");
         if(arquivo == NULL)
         {
            perror("Error");
            return EXIT_FAILURE;
         }
         //CRIA ARQUIVO TEMPORÁRIO E CHECA SE CORREU BEM
         FILE *temp = fopen("temp.bin", "wb");
         if(temp == NULL)
         {
            perror("Error");
            fclose(arquivo);
            return EXIT_FAILURE;
         }
         //LÊ OS REGISTROS NO ARQUIVO ORIGINAL
         while(fread(&busca, sizeof(cadastro), 1, arquivo) == 1)
         {
            if(strcmp(busca.nome, nome_pesquisa)) //strcmp retorna valor diferente de 0 quando são diferentes
            {
               fwrite(&busca, sizeof(cadastro), 1, temp); //ESCREVE OS REGISTRSO DIFERENTES EM TEMP
            }
            else //strings são iguais
            {
               printf("Registro %s %d %s excluído\n", busca.nome, busca.idade, busca.telefone);
               //O REGISTRO QUE SE QUER EXCLUIR NÃO É REESCRITO EM TEMP
               encontrado = 1;
               nro_registros--;
            }
         }
         fclose(arquivo);
         fclose(temp);
         if(!encontrado)
         {
            printf("Registro %s inválido\n", nome_pesquisa);
            remove("temp.bin"); //SE O ARQUIVO A SER EXCLUÍDO NÃO FOI ENCONTRADO, NÃO HÁ NECESSIDADE PARA O ARQUIVO TEMPORÁRIO
         }
         else
         {
            remove(arquivo_analisado);
            rename("temp.bin", arquivo_analisado); //RENOMEIA temp.bin PARA O NOME DO ARQUIVO ORIGINAL
         }

      }

 }while(1);
      return EXIT_SUCCESS;
}
