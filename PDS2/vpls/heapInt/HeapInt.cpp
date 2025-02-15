#include "HeapInt.hpp"
#include <iostream>

HeapInt::HeapInt(): ptrInt(new int(0)) {}
HeapInt::HeapInt(int valor): ptrInt(new int(valor)) {}

HeapInt& HeapInt::operator = (int valor)
{
    if(!ptrInt)
    {
        ptrInt = new int(valor);
    }
    else
    {
        *ptrInt = valor;
    }
    return *this;
} 

HeapInt& HeapInt::operator = (HeapInt& outro)
{
    if(this != &outro)
    {
        delete ptrInt;
        if(outro.ptrInt)
        {
            ptrInt = new int(*outro.ptrInt);
        }
        else
        {
            ptrInt = nullptr;
        }
    }
    return *this;
}

HeapInt::HeapInt(const HeapInt& copiar)
{
    if (copiar.ptrInt) 
    {
        ptrInt = new int(*copiar.ptrInt); 
    } 
    else 
    {
        ptrInt = nullptr;
    }
}

HeapInt::~HeapInt()
{
    delete ptrInt;
}

HeapInt HeapInt::operator + (HeapInt& somar)
{
    HeapInt soma(0); 
    if ((somar.ptrInt != nullptr) && (this->ptrInt != nullptr))
    {
        soma = *(somar.ptrInt) + *(this->ptrInt);
    }
    return soma;
}

HeapInt HeapInt::operator - (HeapInt &subtrair)
{
    HeapInt resultado(0);
    if((subtrair.ptrInt != nullptr) && (this->ptrInt != nullptr))
    {
        resultado = *(this->ptrInt) - *(subtrair.ptrInt); 
    }
    return resultado;
}

bool HeapInt::operator == (HeapInt &comparar)
{
    if((comparar.ptrInt != nullptr) && (this->ptrInt != nullptr))
    {
        if(*(comparar.ptrInt) == *(this->ptrInt))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

std::ostream& HeapInt::operator<<(std::ostream& os) 
{
    os << *ptrInt;  
    return os;      
}

std::istream& HeapInt::operator>>(std::istream& is) 
{
    int value;
    is >> value;      
    setValor(value); 
    return is;        
}

void HeapInt::setValor(int value) 
{
    if (!ptrInt) 
    {
        ptrInt = new int(value);  
    } 
    else 
    {
        *ptrInt = value;
    }
}

/*
HeapInt a(10);
   HeapInt b;

   cin >> b;
   if (a==b)
      cout << "Bingo!" << endl;

   HeapInt c = a;
   HeapInt d;
   HeapInt e;
   
   d = 5;
   e = a + b + c + d;
   cout << a << " " << b << " " << c << " " << d << " " << e << endl;
*/