#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string entrada;
    getline(cin, entrada);
    char* inversa = (char*)malloc(entrada.length()*sizeof(char));
    for(int i = 0; i < entrada.length(); i++)
    {
        inversa[i] = entrada[entrada.length() - 1 - i];
    }
    inversa[entrada.length()] = '\0';
    //cout << inversa;
    bool eh_palindromo = (entrada == inversa);
    if(eh_palindromo == 1)
      cout << "SIM";
    else
      cout << "NAO";  
    return 0;
    free(inversa);
}