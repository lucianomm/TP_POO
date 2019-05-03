#include "matrix.h"
#include <iostream>
using namespace std;

Matrix::Matrix()
{
   _ptr_matrix = new double*[1];
   _ptr_matrix[0] = new double[1];
}

 Matrix::Matrix(int rows, int columns, const double &value = 0) : _rows(rows), _columns(columns)
 {
     _ptr_matrix = new double*[rows];                                                    //cria linhas
     for(int i = 1; i <= _rows; i++) _ptr_matrix[i] = new double[columns];                 //cria vetores em cada linha, definindo uma Matrix completa
        for(int i = 1; i <= _rows; i++) {//preenchendo a Matrix criada com 'valor'
            for(int j = 1; j <= _columns; j++) {
                _ptr_matrix[i][j] = value;
            }
        }
 }
Matrix::Matrix(const Matrix &m) : _rows(m._rows), _columns(m._columns){
    for(int i = 0; i <= _rows; i++) {
        for(int j = 0; j <= _columns; j++) _ptr_matrix[i][j] = m._ptr_matrix[i][j];
    }
}

void Matrix::unit(){
    for(int i = 0; i <= _rows; i++){
        for(int j = 1; j <= _columns; j++){
            if(i == j) _ptr_matrix[i][j] = 1;
        }
    }
}
void Matrix::zeros(){
    for(int i = 0; i <= _rows; i++){
        for(int j = 1; j <= _columns; j++){
            _ptr_matrix[i][j] = 0;
        }
    }
}
void Matrix::ones(){
    for(int i = 0; i <= _rows; i++){
        for(int j = 1; j <= _columns; j++){
            _ptr_matrix[i][j] = 1;
        }
    }
}

ostream& operator << (ostream& op, const Matrix& m) {
    Matrix mt(m);
    const int ncols = mt.get_columns();
    const int nrows = mt.get_rows();
    double value;
    for (int j = 1; j <= ncols; j++){ //percorre primeiro as colunas
        for(int i = 1; i <= nrows; i++){
            value = mt.get_values(i, j);
            op << value <<" "; //depois percorre as linhas e imprime-as
        }
        op <<endl;
    }
    op << endl;
return op;
}
/*std::istream& operator >> (std::istream& op, Matrix& m) {
    delete[] m._ptr_matrix;
    m._ptr_matrix = new double*[rows];//cria linhas
    for(int i = 1; i<=m.get_rows();i++)m._ptr_matrix[i] = new double[m.getCols()];//cria vetores em cada linha, definindo uma Matrix completa
    for(int i = 1; i<=m.getCols();i++){
        for(int j = 1; j<=m.getCols(); j++){
            op >> _ptr_matrix[i][j];
        }
    }
    return op;
}*/
