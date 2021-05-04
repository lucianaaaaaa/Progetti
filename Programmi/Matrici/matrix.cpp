#include "matrix.h"
#include <iomanip>
#include <iostream>
#include <stdexcept>

//costruttore
Matrix::Matrix(int a=3, int b=3): nrow{a}, ncol{b} {
    array = new double*[a];
    for (int i=0; i<a; i++) {
        array[i] = new double [b];
    }
    for (int i=0;i<nrow; i++){
        for (int j=0;j<ncol; j++) {
            array[i][j]=0.0;
        }
    }
}

//bigthree
//costruttore copia
Matrix::Matrix(Matrix& c) {
    nrow = c.nrow;
    ncol = c.ncol;
    array = new double* [nrow];
    for (int i =0; i<nrow;i++) {
        array[i]=new double[ncol];
    }
    for (int i=0;i<nrow; i++){
        for (int j=0;j<ncol; j++) {
            array[i][j]=c.array[i][j];
        }
    }
}

//distruttore
Matrix::~Matrix() {
    for (int i=0;i<nrow;i++) {
        delete [] array[i];
    }
    delete[] array;
}

//operatore di assegnazione
Matrix Matrix::operator= (Matrix& mat) {
    for (int i=0; i<nrow; i++) {
        delete [] array[i];
    }
    delete [] array;

    nrow = mat.nrow;
    ncol = mat.ncol;
    array = new double* [mat.nrow];
    for (int i=0; i<nrow; i++) {
        array [i] = new double [ncol];
    }

    for (int i=0; i<nrow; i++) {
        for (int j=0; j<ncol; j++)
        array[i][j] = mat.array[i][j];
    }
    return *this;
}

//stampare la matrice
void Matrix::printMat () {
    for (int i=0; i<nrow; i++) {
        for (int j=0; j<ncol; j++)
        std::cout << std::setprecision(3) << array [i][j] << "  ";
    std::cout << std::endl;
    }
}

//impostare un valore
void Matrix::setValue (int x, int y, double obj) {
    if (x>=nrow || y>=ncol)
        throw std::invalid_argument ("");
    array[x][y] = obj;
}

//somma
Matrix Matrix::operator+(Matrix& mat) {
    //controlla validità operazione
    if (this->nrow!=mat.nrow || this->ncol!=mat.ncol) {
        std::cout << "Dimensioni incompatibili\n";
        throw std::invalid_argument ("");
    }

    
    //somma
    Matrix newMat (nrow,ncol);
    for (int i=0; i<nrow; i++) {
        for (int j=0; j<ncol; j++)
        newMat.array [i][j] = this->array [i][j] + mat.array[i][j];
    }

    
    return newMat;
}

Matrix Matrix::operator-(Matrix& mat) {
    //controlla validità operazione
    if (this->nrow!=mat.nrow || this->ncol!=mat.ncol) {
        std::cout << "Dimensioni incompatibili\n";
        throw std::invalid_argument ("");
    }
    
    //differenza
    Matrix newMat (nrow,ncol);
    for (int i=0; i<nrow; i++) {
        for (int j=0; j<ncol; j++)
        newMat.array [i][j] = this->array [i][j] - mat.array[i][j];
    }

    return newMat;
}

Matrix Matrix::operator*(Matrix& mat) {
    //controlla validità operazione
    if (this->ncol!=mat.nrow) {
        std::cout << "Dimensioni incompatibili\n";
        throw std::invalid_argument ("");
    }
    
    //prodotto
    Matrix newMat (this->nrow, mat.ncol);
    for (int i=0; i<newMat.nrow; i++) {
        for (int j=0; j<newMat.ncol; j++) {
            for (int h=0; h<mat.nrow; h++)
            newMat.array [i][j] += this->array[i][h] * (mat.array[h][j]);
        }
    }

    return newMat;
}

void Matrix::setRow (int x) {
    this->nrow = x;
}

void Matrix::setColumn (int y) {
    this->ncol = y;
}

int Matrix::getRow () const {
    return nrow;
}

int Matrix::getColumn () const {
    return ncol;
}
