#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include <string>
#include <cctype>

bool alfanum(char c)
{
    return std::isalnum(c);
}

std::string minusculas(std::string &palavra)
{
    for(unsigned int i = 0; i < palavra.length(); i++)
    {
        palavra[i] = tolower(palavra[i]);
    }
    return palavra;
}

int main(void)
{
    std::string nome_arquivo;
    std::cin >> nome_arquivo;
    std::ifstream in(nome_arquivo, std::ifstream::in);
    if(!in.is_open())
    {
        std::cout << "Falha ao abrir o arquivo de entrada" << std::endl;
    }
    /*else
    {
        std::cout << "arquivo aberto com sucesso" << std::endl;
    }*/
    //as palavras são as chaves e os valores são a quantidade de vezes que se repetem
    std::map<std::string, int> palavras;
    char c;
    std::string palavra;
    while(in.get(c))
    {
       if(alfanum(c))
       {
          palavra += c;
       }  
       else if(!palavra.empty())
       {
          palavra = minusculas(palavra);
          palavras[palavra] += 1; //insere no map e incremente a contagem de quantas vezes aparece
          palavra = "";
       }
    }
    if(!palavra.empty())
    {
        palavra = minusculas(palavra);
        palavras[palavra] += 1;
    }
    in.close();
    for(const auto& pair : palavras)
    {
        std::cout << pair.first << " " << pair.second << std::endl;
    }
    return 0;
}