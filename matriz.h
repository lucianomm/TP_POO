//matriz.h
/*1. Crie uma classe Matriz que permita que sejam feitas operações matemáticas similares às do Matlab
para matrizes do tipo double.  A classe deve ser implementada de forma a permitir que os usuários manipulem
seus índices (linhas e colunas) começando de 1 (um) e não de 0 (zero).
Os elementos devem ser armazenados com estruturas criadas dinamicamente na memória através do uso de ponteiros
duplos (ou simples).

obs.: use os recursos aprendidos até o momento para tornar o código eficiente:
-sobrecarga de construtores e funções membro;
-argumentos default em construtores e funções membro, funções membro inline, passagem de argumentos por referência, etc.  ● argumentos e funções membro constantes (const) sempre que possível.

Criação e Destruição de Matrizes:

-Matriz(): cria uma matriz vazia com números de linhas e colunas iguais a 0;
-Matriz(int linhas, int colunas, const double &valor = 0): cria uma matriz com número de linhas e colunas
  iguais aos recebidos pelos argumentos e com todos os valores da matriz preenchidos com a variável valor.
-Matriz(const Matriz &m):  construtor de cópia
-   ~Matriz(): destrutor */


#ifndef MATRIZ_H_INCLUDED
#define MATRIZ_H_INCLUDED
#include <iostream>
using namespace std;
class matriz
{
private:
    double** ptm;
    int r, c; //guardam respectivamente numero de linhas e colunas

public:
    matriz();
    matriz(int, int, const double&);
    matriz(const matriz&);
    int getRows();
    int getCols();
    double getValues(int, int);
    void unit();
    void zeros();
    void ones();
    //friend std::istream& operator>> (std::istream&, matriz&);
    friend ostream& operator<< (ostream&, const matriz&);
    ~matriz();
};


#endif
