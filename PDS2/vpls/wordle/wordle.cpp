#include <iostream>
#include <string>
#include <fstream>
#include <cctype>

using namespace std;

void comparacao(string entrada, string saida, int j)
{
    for(int c = 0; c < 5; c++)
    {
        if((entrada[j] == saida[c]) || (tolower(entrada[j]) == saida[c]))
        {
            saida[c] = '*';
        }
    } 
    return;
}

bool checagem(string comparada, string comparacao, int j)
{
    bool esta_na_string = 0;
    for(unsigned int c = 0; c < comparacao.length(); c++)
    {
        if(comparada[j] == comparacao[c])
        {
            esta_na_string = 1;
            break;
        }
    }
    return esta_na_string;
}

int main(void)
{
    ifstream in("palavras.txt", fstream :: in);
    //verifica se o arquivo foi aberto
    if(!in.is_open()) 
    {   
       cout << "Falha ao abrir o arquivo de entrada" << endl; 
       return 1;
    }   
    else
       cout << "Arquivo aberto com sucesso!" << endl;
    int numero_palavras;
    in >> numero_palavras;
    cout << numero_palavras << endl;
    string* palavras = new string[numero_palavras];
    for (int i = 0; i < numero_palavras; ++i) 
    {
        in >> palavras[i];  
        cout << "Palavra número "<< i+1 << ": " << palavras[i] << endl;
    }
    int numero_chave;
    cin >> numero_chave;
    cout << "número escolhido: " << numero_chave << endl;
    string chave = palavras[numero_chave - 1]; 
    cout << "palavra escolhida: " << chave << endl;
    int tentativas = 0;
    string entrada;
    string saida = "*****";
    string letras_fora;
    string restos;
    while (tentativas < 5)
    {
        cin >> entrada;
        tentativas++;
        if(entrada == chave)
        {
            cout << "GANHOU!" << endl;
            break;
        }

        for(int j = 0; j < 5; j++)
        {
            if(entrada[j] == chave[j])
            { 
               comparacao(entrada, saida, j);
               saida[j] = chave[j];
            }
            else if(entrada[j] != chave[j])
            {
                /*bool esta_na_palavra = 0;
                for(int c = 0; c < 5; c++)
                {
                    if(entrada[j] == chave[c])
                    {
                        esta_na_palavra = 1;
                        break;
                    }
                }*/
                               
                if(checagem(entrada, chave, j) == 1)
                {
                   comparacao(entrada, saida, j);
                   saida[j] = tolower(entrada[j]); 
                } 
                else
                {
                    /*bool esta_no_resto = 0;
                    for(unsigned int r = 0; r < letras_fora.length(); r++)
                    {
                       if(entrada[j] == letras_fora[r])
                       {
                          esta_no_resto = 1;
                          break; 
                       }  
                    }*/
                    if(checagem(entrada, letras_fora, j) == 1)
                    {
                        letras_fora += toupper(entrada[j]);
                    }
                    saida[j] = '*';
                }
            }
        }
        restos = "(" + letras_fora + ")";
        cout << saida << " ";
        cout << restos << endl;
        if((tentativas == 5) && (entrada != chave))
        {
            cout << "PERDEU! " << chave << endl;
            break;
        }
    }
    return 0;
}
