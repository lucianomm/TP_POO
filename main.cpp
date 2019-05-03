#include "matrix.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
// Matrix Y;
Matrix X(3,1), A(3,3), C(3,3);
// Matrix W = C;
// Matrix Z(A);
int numeroLinhas = A.get_rows();
int numeroColunas = A.get_columns();
double value = A.get_value(2,2);
A.unit();
// Y.unit();                       // inicializa Y com a Matrix identidade
// A(2,1)=10;                      // altera o valor de uma posição de A
A.zeros();
// Y.zeros();                      // modifica todos os elementos de Y para o valor zero
// C=A+A;                          // Soma
// C-=A;                           // Subtração
// A=C-A;                          // Subtração
// A+=A;                           // Soma
// A=~C;                           // A é igual a transposta de C
X.ones();                       // modifica todos os elementos de X com 1s
// X*=2;                           // multiplicação por uma constante
// C=A*X;                          // multiplicação de Matrixes
// C*=X;                           // multiplicação de Matrixes
// if (A == C)                     // verifica a igualdade entre A e C
// if(X != Y)                      // verifica a desigualdade entre A e C
cout << A << endl;              // Impressão de Matrixes
// cin >> Y                        // leitura de dados para dentro da Matrix Y

    return 0;
}
