#ifndef EMPRESA_H
#define EMPRESA_H
#include <string>
#include "onibus.hpp"

struct empresa
{
  int qtd_onibus;
  onibus* vetor_onibus[20];
  //construtor default
  empresa();

  onibus* adicionar_onibus(std::string placa, int lotacao_max);
  
  onibus* busca_onibus(std::string placa);

  void imprimir_estado();
};

#endif
