#include <iostream>
#include <exception>
#include <vector>

class NegativeResultException : public std::exception
{
    public:
    int valor;

    NegativeResultException(int n): valor(n) {} 

    virtual const char* what() const throw()
    {
        return "Erro: Resultado Negativo";
    }
};

int main(void)
{
    std::vector <int> vetor = {-20, -10, 0, 10, 20};
    int n;
    try
    {
        std::cin >> n;
        if((n < 0) || (n >= vetor.size()))
        {
            throw std::out_of_range("Erro: Parametro invalido");
        }
        if(vetor.at(n) < 0)
        {
            throw NegativeResultException(vetor.at(n));
        }
        if(vetor.at(n) == 0)
        {
            throw std::logic_error("Erro: O resultado não deve ser zero");
        }
        std::cout << vetor.at(n) << std::endl;
    }
    catch(const std::out_of_range& e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(const NegativeResultException& e)
    {
        std::cerr << e.what() << std::endl;
        std:: cout << e.valor << std::endl;
    }
    catch(const std::logic_error& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}