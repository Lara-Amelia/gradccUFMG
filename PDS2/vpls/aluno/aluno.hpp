#ifndef ALUNO_H
#define ALUNO_H
#include <string>
#include <vector>

class aluno
{
   private:
   std::string nome_aluno;
   int matricula;
   std::vector <int> notas_aluno;

   public:
   //construtor
   aluno(std::string nome, int matricula, std::vector <int> &notas);

   //getter function - acessar os dados privados
   std::string get_nome() const;

   int get_matricula() const;
   
   const std::vector <int>& get_notas() const;
   
   int nota_media() const;
   
   int menor_nota() const;
   
   int maior_nota() const;
   
   void display(std::vector <aluno> alunos_cadastrados);
};
#endif