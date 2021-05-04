#ifndef MATRIX_H
#define MATRIX_H

class Matrix {
    public:
    //costruttore
    explicit Matrix (int a, int b);

    //big three
    Matrix(Matrix& c);
    ~Matrix();
    Matrix operator=(Matrix& mat);

    //funzioni
    void printMat();
    void setValue (int x, int y, double obj);
    void setRow (int x);
    void setColumn (int y);
    int getRow () const;
    int getColumn () const;
    Matrix operator+(Matrix& mat);
    Matrix operator-(Matrix& mat);
    Matrix operator*(Matrix& mat);


    private:
    int nrow;
    int ncol;
    double ** array;
};

#endif