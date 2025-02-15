#include <string>
#ifndef ONIBUS_H
#define ONIBUS_H

struct onibus
{
   std::string placa;
   int capacidade_max;
   int lotacao_atual;

   onibus(std::string placa, int capacidade_max);

   void subir_passageiros(int novos_passageiros);

   void descer_passageiros(int passageiros_descida);

   void transfere_passageiros(onibus* transferencia, int qtd_transferidos);

   void imprimir_estado();
};

#endif