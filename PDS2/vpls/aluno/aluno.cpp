#include "aluno.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

//construtor
aluno::aluno(std::string nome, int matricula, std::vector <int> &notas)
{
   this->nome_aluno = nome;
   this->matricula = matricula;
   this->notas_aluno = notas;
}

int aluno::nota_media() const
{
    int soma = 0;
    int media = 0;
    if(notas_aluno.empty())
    {
        return 0;
    }
    for(int v : notas_aluno)
    {
        soma += v;
    }
    media = soma/notas_aluno.size();
    return media;
}

int aluno::menor_nota() const
{
    if(notas_aluno.empty())
    {
        return 0;
    }
    auto min = min_element(notas_aluno.begin(), notas_aluno.end());
    return *min;
}

int aluno::maior_nota() const
{
    if(notas_aluno.empty())
    {
        return 0;
    }
    auto max = max_element(notas_aluno.begin(), notas_aluno.end());
    return *max;
}

std::string aluno::get_nome() const
{
   return nome_aluno;
}

int aluno::get_matricula() const
{
    return matricula;
}

const std::vector <int>& aluno:: get_notas() const
{
    return notas_aluno;
}

void aluno::display(std::vector <aluno> alunos_cadastrados)
{
    //ordena o vetor por nomes, em ordem alfabética
    std::sort(alunos_cadastrados.begin(), alunos_cadastrados.end(),
    [](const aluno &a, const aluno &b)
      {
        return a.get_nome() < b.get_nome();
      });
    for(const aluno &aluno_x : alunos_cadastrados)
    {
       std::cout << aluno_x.get_matricula() << " " << aluno_x.get_nome() << " ";
       for(const int &nota_x : aluno_x.get_notas())
       {
          std::cout << nota_x << " ";
       }
       std::cout << std::endl;
       std::cout << aluno_x.nota_media() << ".00";
       std::cout << " " << aluno_x.maior_nota() << " " << aluno_x.menor_nota() << std::endl; 
    }
}
