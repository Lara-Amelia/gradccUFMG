#include "onibus.hpp"
#include <iostream>
#include <string>

using namespace std;


  onibus::onibus(string placa, int capacidade_max)
  {
    this->placa = placa;
    this->capacidade_max = capacidade_max;
    this->lotacao_atual = 0;
  }

  void onibus::subir_passageiros(int novos_passageiros)
  {
    if((lotacao_atual < capacidade_max) && (lotacao_atual + novos_passageiros <= capacidade_max))
    {
        lotacao_atual += novos_passageiros;
        cout << "passageiros subiram com sucesso" << endl;
    }  
    else 
    {
        cout << "ERRO: onibus lotado" << endl;
    }
  }

  void onibus::descer_passageiros(int passageiros_descida)
  {
    if(passageiros_descida > lotacao_atual)
    {
      cout << "ERRO: faltam passageiros" << endl;     
    }
    else
    {
        lotacao_atual -= passageiros_descida;
        cout << "passageiros desceram com sucesso" << endl;
    }
  }

  void onibus::transfere_passageiros(onibus* transferencia, int qtd_transferidos)
  {
    //caso existam problemas de lotação
    if((qtd_transferidos > this->lotacao_atual) || (transferencia->lotacao_atual + qtd_transferidos > transferencia->capacidade_max))
    {
        cout << "ERRO: transferencia cancelada" << endl;
    }
    else
    {
        transferencia->lotacao_atual += qtd_transferidos;
        this->lotacao_atual -= qtd_transferidos;
        cout << "transferencia de passageiros efetuada" <<endl;
    }
  }

  void onibus::imprimir_estado()
  {
    cout << this->placa << " (" << this->lotacao_atual << "/" << this->capacidade_max << ")" << endl;
  }