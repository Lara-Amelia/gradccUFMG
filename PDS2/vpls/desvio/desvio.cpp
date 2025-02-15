#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

float calcula_media(float* valores, int n)
{
    float soma = 0;
    for(int j = 0; j < n; j++)
    {
        soma += valores[j];
    }
    float media = soma/n;
    return media;
}

double calcula_desvio(float media, float* valores, int n)
{
    double soma = 0;
    for(int i = 0; i < n; i++)
    {
        soma += pow(valores[i] - media, 2);
    }
    double desviop = sqrt(soma / n);   
    return desviop;
}    

int main(void)
{
    int n;
    cin >> n;
    //cout << n;
    float *valores = new float[n];
    for(int i = 0; i < n; i++)
    {
        //cout << "Digite o valor numero " << i + 1 << endl;
        cin >> valores[i];
        //cout << "valor " << valores[i] << " inserido na posicao " << i << endl;
    }
    float media = calcula_media(valores, n);
    //cout << media;
    double desvio_padrao = calcula_desvio(media, valores, n);

    cout << fixed << setprecision(4);
    cout << media << endl;
    cout << desvio_padrao << endl;
    delete[] valores;
    return 0;
}