#include "matrix.h"
#include <iostream>
using namespace std;

Matrix::Matrix(int rows, int columns, const double &value /* = 0 */) : _rows(rows), _columns(columns) {
    alloc_arrays();                             // allocates memory
    for (int i = 0; i < _rows; i++) {
        for (int j = 0; j < _columns; j++) {
            _ptr[i][j] = value;                 // fills positions with 'value'
        }
    }
}

Matrix::Matrix(const Matrix& m) : _rows(m._rows), _columns(m._columns) {
    alloc_arrays();
    for (int i = 0; i < this->_rows; i++) {
        for (int j = 0; j < this->_columns; j++) {  // copies the values from one
            this->_ptr[i][j] = m._ptr[i][j];        // matrix into the other
        }
    }
}

void Matrix::unit() {
    if (_rows == _columns) {                        // checks for valid dimensions
        for (int i = 0; i < _rows; i++) {
            for (int j = 0; j < _columns; j++) {
                if(i == j) _ptr[i][j] = 1;          // main diagonal -> 1
                else _ptr[i][j] = 0;                // rest -> 0
            }
        }
    } else cout << "Invalid dimensions!" << endl;   // if not, error
}

void Matrix::zeros() {
    for (int i = 0; i < _rows; i++) {
        for (int j = 0; j < _columns; j++) _ptr[i][j] = 0;  // switch every element for '0'
    }
}

void Matrix::ones() {
    for (int i = 0; i < _rows; i++) {
        for (int j = 0; j < _columns; j++) _ptr[i][j] = 1;  // same logic as 'zeros()'
    }
}

ostream& operator << (ostream& op, const Matrix& m) {
    Matrix matrix(m);                               // copies desired matrix
    const int n_columns = matrix.get_columns();     // and gets atributes
    const int n_rows = matrix.get_rows();

    for (int i = 0; i < n_rows; i++) {
        for (int j = 0; j < n_columns; j++) {
            op << matrix.get_value(i, j) << " ";    // prints line by line
        }
        op << endl;
    }
    op << endl;
    return op;
}

istream& operator >> (istream& op, Matrix& m) {
    // delete[] m._ptr;
    // m._ptr = new double*[rows];//cria linhas
    // for(int i = 1; i<=m.get_rows();i++)m._ptr[i] = new double[m.get_columns()]; //cria vetores em cada linha, definindo uma Matrix completa
    // for(int i = 1; i<=m.get_columns();i++){
    //     for(int j = 1; j<=m.get_columns(); j++){
    //         op >> _ptr[i][j];
    //     }
    // }
    return op;
}

Matrix operator+ (const Matrix &A, const Matrix &B) {
    Matrix aux(A);
    /* */
    return aux;
}

Matrix operator- (const Matrix &A, const Matrix &B) {
    Matrix aux(A);
    /* */
    return aux;
}

Matrix operator* (const Matrix &A, const Matrix &B) {
    Matrix aux(A);
    /* */
    return aux;
}

bool Matrix::operator== (const Matrix&) {
    bool result = false;
    /* */
    return result;
}

bool Matrix::operator!= (const Matrix&) {
    bool result = false;
    /* */
    return result;
}


Matrix::~Matrix() {
	for(int i = 0; i < _rows; i++) delete[] this->_ptr[i];
	delete[] this->_ptr;       // deletes all pointers created
}
