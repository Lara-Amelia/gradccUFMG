#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <sstream>

class vpl
{
    private:
    int id;
    static int id_estatico;
    static int nro_objetos;

    public:
    vpl()
    {
       id_estatico++; 
       this-> id = id_estatico;
       nro_objetos++;
    }
    vpl(int id_novo)
    {
        this-> id = id_novo;
        nro_objetos++;
    }
    int get_id()
    {
       return id;
    }
    const vpl* get_endereço()
    {
       return this;
    }
    static int get_qtd()
    {
        return nro_objetos;
    }
    ~vpl()
    {
            nro_objetos--;
    }
};

int vpl::id_estatico = 0;
int vpl::nro_objetos = 0;

int main(void)
{
    std::list <vpl*> lista_ptrs;
    char entrada;
    int id_add;
    std::string dados;
    do
    {
        std::getline(std::cin, dados);
        std::istringstream info_lida(dados);
         if (info_lida >> entrada) 
         { 
            if (info_lida >> id_add) 
            { 
                std::cout << "escolha menu: " << entrada << ", id: " << id_add << std::endl;
            } 
            else 
            {
                std::cout << "escolha menu: " << entrada << " nenhum inteiro encontrado" << std::endl;
            }
        }
        switch(entrada)
        {
            case('A'):
            {
               vpl* novo_obj = new vpl();
               lista_ptrs.push_back(novo_obj);
               std::cout << novo_obj -> get_id() << " " << novo_obj->get_endereço() << std::endl;
            }
            break;
            case('C'):
            {
               if(id_add >= 0)
               {
                  std::cout << "ERRO" << std::endl;
                  break;
               }
               else
               {  
                  vpl* novo_obj = new vpl(id_add);
                  lista_ptrs.push_front(novo_obj);
                  std::cout << novo_obj -> get_id() << " " << novo_obj -> get_endereço() << std::endl;
               }
            }
            break;
            case('R'):
            {
                if(lista_ptrs.empty())
                {
                    std::cout << "ERRO" << std::endl;
                    break;
                }
                else //a lista não está vazia
                {
                    vpl* obj_remocao = lista_ptrs.front();
                    lista_ptrs.pop_front();
                    //to-do: consertar a não impressão do id
                    std::cout << obj_remocao->get_id() << obj_remocao->get_endereço() << std::endl;
                    delete obj_remocao;
                }
            }
            break;
            case('N'):
            {
                
                std::cout << vpl::get_qtd() << std::endl;
            }
            break;
            case('P'):
            {
                //to-do: consertar o nome da vriavel id_add (nem sempre é um id)
                if((id_add < 1) || (id_add > lista_ptrs.size()))
                {
                    std::cout << "ERRO" << std::endl;
                }
                else
                {
                    std::list<vpl*>::iterator it = lista_ptrs.begin();
                    std::advance(it, id_add - 1);
                    std::cout << (*it)->get_id() << (*it)->get_endereço() << std::endl;
                }
            }
            break;
            case('L'):
            {
               for(vpl* n: lista_ptrs)
               {
                  std::cout << n -> get_id() << n -> get_endereço() << std::endl;
               }
            }
            break;
        }
    } while (entrada != 'E');
    
    return 0;
}