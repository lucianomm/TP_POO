//Matrix.h
/*1. Crie uma classe Matrix que permita que sejam feitas operações matemáticas similares às do Matlab
para Matrixes do tipo double.  A classe deve ser implementada de forma a permitir que os usuários manipulem
seus índices (linhas e colunas) começando de 1 (um) e não de 0 (zero).
Os elementos devem ser armazenados com estruturas criadas dinamicamente na memória através do uso de ponteiros
duplos (ou simples).

obs.: use os recursos aprendidos até o momento para tornar o código eficiente:
-sobrecarga de construtores e funções membro;
-argumentos default em construtores e funções membro, funções membro inline, passagem de argumentos por referência, etc.  ● argumentos e funções membro constantes (const) sempre que possível.

Criação e Destruição de Matrizes:

-Matrix(): cria uma Matrix vazia com números de linhas e colunas iguais a 0;
-Matrix(int linhas, int colunas, const double &valor = 0): cria uma Matriz com número de linhas e colunas
  iguais aos recebidos pelos argumentos e com todos os valores da Matriz preenchidos com a variável valor.
-Matrix(const Matrix &m):  construtor de cópia
-   ~Matrix(): destrutor */


#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED
#include <iostream>

using namespace std;
class Matrix {
private:
    double** _ptr_matrix;
    int _rows, _columns;                  //guardam respectivamente numero de linhas e colunas

public:
    Matrix();
    Matrix(int, int, const double&);
    Matrix(const Matrix&);

    int get_rows() const { return this->_rows; }
    int get_columns() const { return this->_columns; }
    double get_values(int i, int j) const { return this->_ptr_matrix[i][j]; }

    void unit();
    void zeros();
    void ones();

    //friend std::istream& operator>> (std::istream&, Matrix&);
    friend ostream& operator<< (ostream&, const Matrix&);
    
    ~Matrix() { delete[] _ptr_matrix; }
};


#endif
