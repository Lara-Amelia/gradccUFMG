#include <stdio.h>

//char 1 byte
//shor int 2 bytes
//int 4 bytes
//double 8 bytes
typedef struct{
  char c;
  short int s;
} structA;

typedef struct{
   char s;
   int c;
   short int i;
} structB;

typedef struct{
   char c;
   double d;
   int s;
} structC;

typedef struct{
   double d;
   char s;
   int c;
}structD;

int main(void)
{
    printf("tamanho struct A: %lu\n", sizeof(structA));
    printf("tamanho struct B: %lu\n", sizeof(structB));
    printf("tamanho struct C: %lu\n", sizeof(structC));
    printf("tamanho struct D: %lu\n", sizeof(structD));
    return 0;
}
