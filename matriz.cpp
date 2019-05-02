//matriz.cpp
#include "matriz.h"
#include <iostream>

using namespace std;
 matriz::matriz()
{
   ptm = new double*[1];
   ptm[0] = new double[1];

}

 matriz::matriz(int rows, int columns, const double &value = 0):r(rows), c(columns)
 {
     ptm = new double*[rows];//cria linhas
     for(int i = 1; i<=rows;i++)ptm[i] = new double[columns];//cria vetores em cada linha, definindo uma matriz completa
     for(int i = 1; i<=rows; i++){//preenchendo a matriz criada com 'valor'
         for(int j = 1; j<=columns; j++){
             ptm[i][j] = value;
         }
     }
 }
matriz::matriz(const matriz &m):r(m.r), c(m.c){
    for(int i = 0; i<=r;i++){
        for(int j = 0; j<=c;j++)ptm[i][j]=m.ptm[i][j];
    }
}
int matriz::getRows(){
     return r;
}
int matriz::getCols(){
    return c;
}
void matriz::unit(){
    for(int i = 0; i<=r; i++){
        for(int j = 1; j<=c; j++){
            if(i==j)ptm[i][j]=1;
        }
    }
}
void matriz::zeros(){
    for(int i = 0; i<=r; i++){
        for(int j = 1; j<=c; j++){
            ptm[i][j] = 0;
        }
    }
}
void matriz::ones(){
    for(int i = 0; i<=r; i++){
        for(int j = 1; j<=c; j++){
            ptm[i][j] = 1;
        }
    }
}
double matriz::getValues(int i, int j){
    return ptm[i][j];
}
ostream& operator << (ostream& op, const matriz& m) {
    matriz mt(m);
    const int ncols = mt.getCols();
    const int nrows = mt.getRows();
    double value;
    for (int j = 1; j<= ncols; j++){ //percorre primeiro as colunas
        for(int i = 1; i<=nrows; i++){
            value = mt.getValues(i,j);
            op << value <<" "; //depois percorre as linhas e imprime-as
        } 
        op <<endl;
    }
    op << endl;
return op;
}
/*std::istream& operator >> (std::istream& op, matriz& m) {
    delete[] m.ptm;
    m.ptm = new double*[rows];//cria linhas
    for(int i = 1; i<=m.getRows();i++)m.ptm[i] = new double[m.getCols()];//cria vetores em cada linha, definindo uma matriz completa
    for(int i = 1; i<=m.getCols();i++){
        for(int j = 1; j<=m.getCols(); j++){
            op >> ptm[i][j];
        }
    }
    return op;
}*/
matriz::~matriz()
{
    delete[] ptm;
}



