#include <iostream>
#include "HeapInt.hpp"

int main(void)
{
    HeapInt a(10);
    HeapInt b;

    std::cin >> b;
    if (a==b)
       std::cout << "Bingo!" << std::endl;

   HeapInt c = a;
   HeapInt d;
   HeapInt e;
   
   d = 5;
   e = a + b + c + d;
   std::cout << a << " " << b << " " << c << " " << d << " " << e << endl;
    return 0;
}