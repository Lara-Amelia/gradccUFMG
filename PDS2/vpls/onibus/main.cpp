#include <iostream>
#include <string>
#include "onibus.hpp"
#include "empresa.hpp"

using namespace std;

int main(void)
{
    empresa* nova_empresa = new empresa;
    char opcao_menu;
    do
    {
        cin >> opcao_menu;
        cin.ignore();
        switch (opcao_menu)
        {
            case('C'):
            {
               string placa_cadastro;
               int lotacao_max_cadastro;
               getline(cin, placa_cadastro, ' ');
               cin >> lotacao_max_cadastro;
               if(nova_empresa->busca_onibus(placa_cadastro)!=nullptr)
               {
                  cout << "ERRO: onibus repetido" << endl;  
               }
               else if(nova_empresa->adicionar_onibus(placa_cadastro, lotacao_max_cadastro))
               {
                  //nova_empresa->imprimir_estado();
                  cout << "novo onibus cadastrado" << endl;
               }
            }break;

            case('S'):
            { 
                string placa_subir;
                int passag_subir;
                getline(cin, placa_subir, ' ');
                cin >> passag_subir;
                onibus* onibus_subida = nova_empresa->busca_onibus(placa_subir);
                if(onibus_subida == nullptr)
                {
                    cout << "ERRO: onibus inexistente" << endl;
                }
                else
                {
                    onibus_subida->subir_passageiros(passag_subir);
                }
            }break;

            case('D'):
            {
                string placa_descida;
                int passag_desc;
                getline(cin, placa_descida, ' ');
                cin >> passag_desc;
                onibus* onibus_descida = nova_empresa->busca_onibus(placa_descida);
                if(onibus_descida == nullptr)
                {
                    cout << "ERRO: onibus inexistente" << endl;
                }
                else
                {
                    onibus_descida->descer_passageiros(passag_desc);
                }
            }break;

            case('T'):
            {
                string placa1;
                string placa2;
                int num_transferidos;
                getline(cin, placa1, ' ');
                getline(cin, placa2, ' ');
                cin >> num_transferidos;
                onibus* onibus_saida = nova_empresa->busca_onibus(placa1);
                onibus* onibus_entrada = nova_empresa->busca_onibus(placa2);
                if((onibus_saida == nullptr) || (onibus_entrada == nullptr))
                {
                    cout << "ERRO: onibus inexistente" << endl;
                }
                else
                {
                    onibus_saida->transfere_passageiros(onibus_entrada, num_transferidos);
                }
            }break;
            case ('I'):
            {
               nova_empresa->imprimir_estado();
            }break;
        }
    } while (opcao_menu != 'F');
    
    return 0;
}