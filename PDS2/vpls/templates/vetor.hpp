//to-do: verificar diferenças com moodle
#ifndef VETOR_H
#define VETOR_H
#include <iostream>

template <typename T>
class Vetor
{
    private:
    T* Vetor;
    int n, atual;

    public:
    Vetor(int n)
    {
        this->n = n;
        this->atual = 0;
        Vetor = new T[n];
    }
    Vetor(T* vet)
    {
        this->n = vet->n;
        this->atual = vet->atual;
        T* copia = new T[vet->n];
        for(int i = 0; i < atual; i++)
        {
            copia[i] = vet[i];
        }
    }
    
    ~Vetor()
    {
        delete[] Vetor;
    }

    void SetElemento(int i, T x)
    {
       for(int j = this->atual; j > i; j--)
       {
          Vetor[j] = Vetor[j-1];
       }
       Vetor[i] = x;
       ++atual;
    }

    T GetElemento(int i)
    {
       return Vetor[i];
    }

    void AdicionaElemento(T x)
    {
        atual++;
        Vetor[atual] = x;
    }

    void Imprime()
    {
        for(int j = 0; j < atual; j++)
        {
            std::cout << Vetor[j] << " ";
        }
        std::cout << std::endl;
    }
};
#endif