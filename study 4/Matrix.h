#pragma once
#include <iostream>
#include <ctime>
#include <fstream>
using namespace std;
class Elem;
class Matrix
{
protected:
    int _rows;
    int _cols;
    int** _matrix1;
public:
    Matrix();
    Matrix(int, int);
    Matrix(const Matrix& X);
    void MakeMatrix();
    virtual void Show();
    Matrix Transposition();
    Matrix AdditionMatrix(const Matrix&);
    Matrix operator+(const Matrix&);
    friend Matrix operator-(const Matrix&, const Matrix&);
    Matrix& operator=(const Matrix&);
    Matrix operator++(int);
    Matrix& operator++();
    operator int();
    friend ofstream& operator<<(ofstream&, Matrix&);
    friend fstream& operator<<(fstream&, Matrix&);
    friend fstream& operator>>(fstream&, Matrix&);
    ~Matrix();
};