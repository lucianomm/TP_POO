#include "matrix.h"
#include <iostream>
using namespace std;


//_____________________________________________________________________________________________________
//
//      CONSTRUCTORS
//
// with parameters
Matrix::Matrix(int rows, int columns, const double &value /* = 0 */) : _rows(rows), _columns(columns) {
    alloc_arrays();                             // allocates memory
    for (int i = 0; i < _rows; i++) {
        for (int j = 0; j < _columns; j++) {
            _ptr[i][j] = value;                 // fills positions with 'value'
        }
    }
}

// copy
Matrix::Matrix(const Matrix& m) : _rows(m._rows), _columns(m._columns) {
    alloc_arrays();
    for (int i = 0; i < this->_rows; i++) {
        for (int j = 0; j < this->_columns; j++) {  // copies the values from one
            this->_ptr[i][j] = m._ptr[i][j];        // matrix into the other
        }
    }
}

//_____________________________________________________________________________________________________
//
//      TRANSFORMATIONS
//
// identity
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

// zeros
void Matrix::zeros() {
    for (int i = 0; i < _rows; i++) {
        for (int j = 0; j < _columns; j++) _ptr[i][j] = 0;  // switch every element for '0'
    }
}

// ones
void Matrix::ones() {
    for (int i = 0; i < _rows; i++) {
        for (int j = 0; j < _columns; j++) _ptr[i][j] = 1;  // same logic as 'zeros()'
    }
}

//_____________________________________________________________________________________________________
//
//      OPERATOR OVERLOADS
//
// std::cout
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

// std::cin
istream& operator >> (istream& op, Matrix& m) {
    cout << endl << "Lines: ";      // asks for new dimensions
    op >> m._rows;
    cout << "Columns: ";
    op >> m._columns;

    delete[] m._ptr;                // deletes old and allocates new pointers
    m._ptr = new double*[m._rows];  // with the modified specifications
    for (int i = 0; i < m._rows; i++) m._ptr[i] = new double[m._columns];

    for (int i = 0; i < m.get_rows(); i++) {
        for (int j = 0; j < m.get_columns(); j++) {
            cout << "[" << i + 1 << "]" << "[" << j + 1 << "]" << ": ";
            op >> m._ptr[i][j];     // receives new values as indicated by std::cout
        }
    }
    return op;
}

// atribution
Matrix& Matrix::operator= (const Matrix& right) {
    if (this == &right) return *this;       // solves auto-atribution

    _rows = right._rows;                    // sets new dimensions
    _columns = right._columns;              // and reallocates
    delete[] _ptr;                          // pointers
    alloc_arrays();

    for (int i = 0; i < _rows; i++) {
        for (int j = 0; j < _columns; j++) {
            _ptr[i][j] = right._ptr[i][j];  // sets right values into desired matrix
        }
    }
    return *this;
}

// Returns the value of a given location when used A(m,n) | m >= 1 && n >= 1
double& Matrix::operator() (const int &row, const int &column) {
    return this->_ptr[row - 1][column - 1];     // not zero relative
}

// Operator overload for Matrix sum
Matrix Matrix::operator+ (Matrix &B) {
    Matrix sum(B.get_rows(), B.get_columns());                  // creates return matrix
    double** ptr = sum.get_ptr();                               // gets pointer to change values

    for (int i = 0; i < sum.get_rows(); i++) {
        for (int j = 0; j < sum.get_columns(); j++) {
            ptr[i][j] = this->_ptr[i][j] + B.get_value(i,j);    // adds
        }
    }
    return sum;
}

// Overload for matrix subtraction
Matrix Matrix::operator- (Matrix &B) {
    Matrix sub(B.get_rows(), B.get_columns());                  // creates return matrix
    double** ptr = sub.get_ptr();                               // gets pointer to change values

    for (int i = 0; i < sub.get_rows(); i++) {
        for (int j = 0; j < sub.get_columns(); j++) {
            ptr[i][j] = this->_ptr[i][j] - B.get_value(i,j);    // subtracts
        }
    }
    return sub;
}

Matrix Matrix::operator* (Matrix &B) {
    Matrix mult(this->get_rows(), B.get_columns());                 // A[m,n] * B[p,q] -> C[m,q]
    double** ptr = mult.get_ptr();

    if (this->get_columns() == B.get_rows()) {                      // checks viability
        double temp = 0;                                            // stores temporary sum

        for (int i = 0; i < this->get_rows(); i++) {
            for (int j = 0; j < B.get_columns(); j++) {
                temp = 0;

                for (int k = 0; k < this->get_columns(); k++) {     // iterate each row and column in each scalar multiplication
                    temp += this->_ptr[i][k] * B.get_value(k, j);   // sum that results in one element of mult
                }
                ptr[i][j] = temp;
            }
        }
        return mult;
    }
    else return *this;
}

// multiplies by scalar
Matrix Matrix::operator* (double scalar) {
    Matrix result(this->_rows, this->_columns);                 // creates matrix off same size
    double** ptr = result.get_ptr();                            // gets pointer

    for (int i = 0; i < result.get_rows(); i++) {
        for (int j = 0; j < result.get_columns(); j++) {
            ptr[i][j] = this->_ptr[i][j] * scalar;              // multiplies each value by desired scalar
        }
    }
    return result;
}

Matrix Matrix::operator~ () {
    Matrix transp(this->get_columns(), this->get_rows());
    double** ptr = transp.get_ptr();

    for (int i = 0; i < this->get_columns(); i++) {
        for (int j = 0; j < this->get_rows(); j++) {
            ptr[i][j] = this->_ptr[j][i];
        }
    }
    return transp;
}

// bool Matrix::operator== (const Matrix&) {
//     bool result = false;
//     /* */
//     return result;
// }

// bool Matrix::operator!= (const Matrix&) {
//     bool result = false;
//     /* */
//     return result;
// }


Matrix::~Matrix() {
	for(int i = 0; i < _rows; i++) delete[] this->_ptr[i];
	delete[] this->_ptr;       // deletes all pointers created
}
