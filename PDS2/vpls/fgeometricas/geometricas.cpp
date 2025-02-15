#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <iomanip>

class Ponto
{ 
    private:
    int coord_x, coord_y;

    public:
    Ponto() : coord_x(0), coord_y(0) {}

    Ponto(int x, int y) : coord_x(x), coord_y(y) {}

    int get_coordy()
    { 
       return this->coord_y;
    }

    int get_coordx()
    {
        return this->coord_x;
    }

    void set_coordy(int y)
    {
        this->coord_y = y;
    }

    void set_coordx(int x)
    {
        this->coord_x = x; 
    }
};

class FiguraGeometrica
{
    protected:
    Ponto centro;

    public:
    FiguraGeometrica(int x, int y) : centro(x, y) {}

    virtual void Desenha()
    {
        int x = centro.get_coordx();
        int y = centro.get_coordy();
        std::cout << x << " " << y << " ";
    }
    virtual float CalculaArea() = 0; //método virtual puro
    virtual ~FiguraGeometrica() {}
};

class Retangulo : public FiguraGeometrica
{
    private:
    int comprimento, largura;

    public:

    Retangulo(int x, int y, int comp, int larg)
    : FiguraGeometrica(x, y), comprimento(comp), largura(larg) {}

    float CalculaArea() override
    {
        float area = 0;
        area = this->comprimento * this->largura;
        return area;
    }

    void Desenha () override
    {
        FiguraGeometrica::Desenha();
        std::cout << "RETANGULO" <<std::endl;
    }

    ~Retangulo() override {}
};

class Circulo: public FiguraGeometrica
{
    private:
    int raio;

    public:
    Circulo(int x, int y, int r)
    : FiguraGeometrica(x, y), raio(r) {}

    void Desenha() override
    {
        FiguraGeometrica::Desenha();
        std::cout << "CIRCULO" << std::endl;
    }

    float CalculaArea() override
    {
        float area = 0;
        area = std::pow(this->raio, 2) * M_PI;
        return area;
    }
    ~Circulo() override{}
};

class Triangulo: public FiguraGeometrica
{
    private:
    int base, altura;

    public:
    Triangulo(int x, int y, int b, int h)
    : FiguraGeometrica(x, y), base(b), altura(h) {}

    void Desenha() override
    {
        FiguraGeometrica::Desenha();
        std::cout << "TRIANGULO" << std::endl;
    }
    float CalculaArea() override
    {
        float area = 0;
        area = (this->base * this->altura)/2;
        return area;
    }
    ~Triangulo() override{}
};

int main(void)
{
    std::vector <FiguraGeometrica*> figuras;
    std::string dados;
    char opcao_menu;
    int info1, info2, info3, info4;
    do
    {
        std::getline(std::cin, dados);
        std::istringstream info_lida(dados);
        info_lida >> opcao_menu;
        int valor = 0;
        int contador = 0;
        while (info_lida >> valor) 
        {
           if (contador == 0) info1 = valor;
           else if (contador == 1) info2 = valor;
           else if (contador == 2) info3 = valor;
           else if (contador == 3) info4 = valor;
           ++contador;
        }

        switch (opcao_menu)
        {
            case ('R'):
            {
                Retangulo* novo_ret = new Retangulo(info1, info2, info3, info4);
                figuras.push_back(novo_ret);
            }
            break;
            case('C'):
            {
                Circulo* novo_circ = new Circulo(info1, info2, info3);
                figuras.push_back(novo_circ);
            }
            break;
            case('T'):
            {
                Triangulo* novo_t = new Triangulo(info1, info2, info3, info4);
                figuras.push_back(novo_t);
            }
            break;
            case('D'):
            {
                for(FiguraGeometrica* n : figuras)
                {
                    n->Desenha();
                }
            }
            break;
            case('A'):
            {
                float soma = 0;
                for(FiguraGeometrica* n : figuras)
                {
                    soma += n->CalculaArea();
                }
                std::cout << std::fixed << std::setprecision(2)<< soma << std::endl;
            }
            break;
            case('E'):
            {
                for(FiguraGeometrica* n : figuras)
                {
                    delete n;
                }
            }
            break;
        }
    } while (opcao_menu != 'E');
    
    return 0;
}
