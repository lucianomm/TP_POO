#include "matrix.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    Matrix A(4, 4, 5);
    cout << "A:" << "\n" << A << endl;

    Matrix B(2, 7);
    cout << "B:" << "\n" << B << endl;

    Matrix Z(A);
    cout << "Z:" << "\n" << Z << endl;

    cout << "A -> identidade:" << endl;
    A.unit();
    cout << A << endl;

    Matrix Y;
    Y.unit();                       // inicializa Y com a Matrix identidade
    cout << "Y:" << "\n" << Y << endl;
    // A(2,1)=10;                      // altera o valor de uma posição de A

    Z.zeros();
    cout << "Z:" << "\n" << Z << endl;

    //cout << A << endl;
    // C=A+A;                          // Soma
    // C-=A;                           // Subtração
    // A=C-A;                          // Subtração
    // A+=A;                           // Soma
    // A=~C;                           // A é igual a transposta de C

    B.ones();                       // modifica todos os elementos de X com 1s
    cout << "B:" << "\n" << B << endl;

    //cout << A << endl;
    // X*=2;                           // multiplicação por uma constante
    // C=A*X;                          // multiplicação de Matrixes
    // C*=X;                           // multiplicação de Matrixes
    // if (A == C)                     // verifica a igualdade entre A e C
    // if(X != Y)                      // verifica a desigualdade entre A e C
    // cin >> Y                        // leitura de dados para dentro da Matrix Y

    return 0;
}
