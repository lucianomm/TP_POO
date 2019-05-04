#include "matrix.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    Matrix A(4, 4, 5);
    cout << "matriz 4x4 de 5s" << endl;
    cout << "A:" << "\n" << A << endl;

    Matrix B(2, 7);
    cout << "matriz 2x7 sem valor" << endl;
    cout << "B:" << "\n" << B << endl;

    Matrix Z(A);
    cout << "copia A para Z" << endl;
    cout << "Z:" << "\n" << Z << endl;

    A.unit();
    cout << "A -> identidade:" << endl;
    cout << A << endl;

    A(2, 1) = 10;                      // altera o valor de uma posição de A
    cout << "altera A(2, 1) para 10" << endl;
    cout << "A:" << "\n" << A << endl;

    B.ones();                       // modifica todos os elementos de X com 1s
    cout << "modifica todos os elementos de B para 1" << endl;
    cout << "B:" << "\n" << B << endl;

    Matrix C = Z + A;
    cout << "Z + A" << endl;
    cout << "C:" << "\n" << C << endl;

    Matrix D = A - Z;
    cout << "A - Z" << endl;
    cout << "D:" << "\n" << D << endl;

    D = D * 2;
    cout << "D * 2" << endl;
    cout << "D:" << "\n" << D << endl;

    Matrix Y;
    cout << "Y com construtor default" << Y << endl;
    cout << "modifica Y" << endl;
    cin >> Y;                        // leitura de dados para dentro da Matrix Y
    cout << "Y:" << "\n" << Y << endl;

    Matrix W;
    W =~ Y;
    cout << "transposta de Y" << endl;
    cout << "W:" << "\n" << W << endl;

    Matrix M = C * D;
    cout << "C * D" << endl;
    cout << "M:" << "\n" << M << endl;

    C=A+A;                          // Soma
    std::cout << "C = A + A" << "\n";
    std::cout << "C:" << "\n" << C << endl;
    C-=A;                           // Subtração
    std::cout << "C -= A" << "\n";
    std::cout << "C:" << "\n" << C << endl;
    A=C-A;                          // Subtração
    std::cout << "A = C - A" << "\n";
    std::cout << "A:" << "\n" << A << endl;
    A+=A;                           // Soma
    std::cout << "A += A" << "\n";
    std::cout << "A:" << "\n" << A << endl;
    A=~C;                           // A é igual a transposta de C
    std::cout << "A =~ C" << "\n";
    std::cout << "A:" << "\n" << A << endl;
    Z*=2;                           // multiplicação por uma constante
    Z=A*C;                          // multiplicação de Matrixes
    Z*=C;                           // multiplicação de Matrixes
    std::cout << "Teste de igualdade A==C:" << endl;
    if (A == C)                       // verifica a igualdade entre A e C
    std::cout << "A == C" << "\n";
    if (A != C)                       // verifica a desigualdade entre A e C
    std::cout << "A != C" << "\n";

    return 0;
}
