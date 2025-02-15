#include "aluno.hpp"
#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <sstream>

int main(void)
{
    std::string input;
    std::string nome_novo_aluno;
    int matricula_novo_aluno;
    int nota;
    std::vector <int> notas_novo_aluno;
    std::vector <aluno> alunos_cadastrados; 
    //faz a leitura dos dados de quantos alunos se desejar
    do
    {
        input.clear();
        std::cout << "digite o nome do aluno" << std::endl;
        std::getline(std::cin, input);
        if(input != "END")
           nome_novo_aluno = input;
        else
           break;
        std::cout << "digite a matricula do aluno" << std::endl;   
        std::cin >> matricula_novo_aluno;   
        std::cin.ignore();
        input.clear();
        std::cout << "digite as notas do aluno terminando em -1" << std::endl;
        std::getline(std::cin, input);
        std::istringstream stream(input);
        while(stream >> nota)
        {
            if(nota == -1)
            { break;
              std::cout << "fim da leitura de notas" << std::endl;
            }
            else
            {
               notas_novo_aluno.push_back(nota);
            }  
        }
        aluno novo_aluno(nome_novo_aluno, matricula_novo_aluno, notas_novo_aluno);
        alunos_cadastrados.push_back(novo_aluno);
        notas_novo_aluno.clear();
    }while(input != "END");
    if(!alunos_cadastrados.empty())
    {
        alunos_cadastrados[0].display(alunos_cadastrados);
    }
    return 0;
}