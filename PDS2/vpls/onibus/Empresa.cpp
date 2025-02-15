#include "onibus.hpp"
#include "empresa.hpp"
#include <iostream>
#include <string>

using namespace std;

  empresa::empresa()
  {
    qtd_onibus = 0;
    for(int i = 0; i < 20; i++)
    {
        vetor_onibus[i] = nullptr;
    }
  }

  onibus* empresa::adicionar_onibus(std::string placa_novo, int lotacao_max_novo)
  {
    onibus* novo_onibus = new onibus(placa_novo, lotacao_max_novo);
    vetor_onibus[qtd_onibus] = novo_onibus;
    qtd_onibus++;
    if(novo_onibus != nullptr)
    {
        return novo_onibus;
    }
    else
    {
        return nullptr;
    }
  }

  onibus* empresa::busca_onibus(std::string placa_busca)
  {
    for(int i = 0; i < qtd_onibus; i++)
    {
       if(vetor_onibus[i]->placa == placa_busca)
       {
          return vetor_onibus[i];
       }
    }
    //retorna o ponteiro nulo caso não encontre a placa em nenhum dos ônibus do vetor
    return nullptr;
  }

  void empresa::imprimir_estado()
  {
    for(int i = 0; i < qtd_onibus; i++)
    {
        cout << vetor_onibus[i]->placa << " (" << vetor_onibus[i]->lotacao_atual << "/" << vetor_onibus[i]->capacidade_max << ")" << endl;
       //cout << vetor_onibus[i]->placa << " " << vetor_onibus[i]->lotacao_atual << " " << vetor_onibus[i]->capacidade_max << endl;
    }
  }