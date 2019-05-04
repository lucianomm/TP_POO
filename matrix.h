#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED
#include <iostream>
using namespace std;

class Matrix {
private:
    double** _ptr;             // 2D vector
    int _rows, _columns;

    void alloc_arrays() {
        _ptr = new double*[_rows];                                          // creates vector
        for (int i = 0; i < _rows; i++) _ptr[i] = new double[_columns];     // each position points to another vector
    }

public:
    Matrix() : _rows(0), _columns(0) { alloc_arrays(); }    // creates matrix w/ 0 rows and columns
    Matrix(int rows, int columns, const double &value = 0); // receives dimensions and value (optional)
    Matrix(const Matrix&);                                  // copy constructor

    int get_rows() const { return _rows; }                      // returns # rows
    int get_columns() const { return _columns; }                // returns # columns
    double get_value(int i, int j) const { return _ptr[i][j]; } // returns the value of a given position
    double** get_ptr() const { return _ptr; }

    void unit();    // transforms into identity matrix -- checks for correct dimensions, otherwise doesn't change
    void zeros();   //     "        "  zeros      "
    void ones();    //     "        "  ones       "

    friend istream& operator>> (istream&, Matrix&);         // modifies '>>' to receive inputs to change empty matrices
    friend ostream& operator<< (ostream&, const Matrix&);   // modifies '<<' to output matrices directly

    double& operator()(const int &, const int &);
    Matrix& operator= (const Matrix&);
    Matrix operator+ (Matrix&); // allows A = B + C
    Matrix operator- (Matrix&); // allows A = B - C
    Matrix operator* (Matrix&); // allows A = B * C
    Matrix operator* (double);  // allows A = B * x, x -> (-inf, +inf)
    Matrix operator~ ();        // allows A = B^(t)
    bool operator== (const Matrix&);  // allows A == B
    bool operator!= (const Matrix&);  // allows A != B
    Matrix operator-= (Matrix&);// allows A -= B
    Matrix operator+= (Matrix&);// allows A += B
    Matrix operator*= (Matrix&);// allows A *= B
    Matrix operator*= (double);// allows A *= B

    ~Matrix();      // destructor
};

#endif // MATRIX_H_INCLUDED
