#ifndef HEAPINT_H
#define HEAPINT_H
#include <iostream>

class HeapInt
{
    private:
    int* ptrInt;

    public:
    HeapInt();
    HeapInt(int valor);
    HeapInt(const HeapInt &copiar);
    ~HeapInt();
    HeapInt& operator = (int valor);
    HeapInt& operator = (HeapInt &outro);
    HeapInt operator + (HeapInt &somar);
    HeapInt operator - (HeapInt &subtrair);
    bool operator == (HeapInt &comparar);
    std::ostream& operator << (std::ostream& os);
    std::istream& operator >> (std::istream& is);
    void HeapInt::setValor(int value);
};

#endif