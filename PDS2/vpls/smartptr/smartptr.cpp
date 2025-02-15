#include <iostream>
#include <memory>

class Teste
{
    private:
    int numero;

    public:
    Teste(): numero(0)
    {
        std::cout << "Construtor " << this->numero << std::endl; 
    }
    Teste(int valor): numero(valor)
    {
        std::cout << "Construtor " << this->numero << std::endl;
    }
    ~Teste()
    {
        std::cout << "Destrutor "<< this->numero << std::endl;
    }
    void setNumero(int valor)
    {
        this->numero = valor;
    }
};

int main(void)
{
    int n;
    std::cin >> n;
    if(n % 2 == 0) //se n for par
    {
        for(int c = 1; c <= n; c++)
        {
            Teste* dumbPtr = new Teste(c);
            std::unique_ptr<Teste> smtPtr (new Teste(c));
        }
    }
    else
    {
        std::shared_ptr<Teste> smtPtr (new Teste());
        for(int c = 1; c <= n; c++)
        {
            std::shared_ptr<Teste> smtPtrC = smtPtr;
            smtPtrC->setNumero(c);
            std::cout << smtPtr.use_count() << std::endl;
        }
    }
    return 0;
}