#include "Matrix.h"

Matrix::Matrix()
{
    _rows = 0;
    _cols = 0;
    _matrix1 = 0;
}

Matrix::Matrix(int rows, int cols)
{
    _rows = rows;
    _cols = cols;
    _matrix1 = this->_matrix1;
    int** _matrix1 = new int* [_rows];
    for (int i = 0; i < _rows; i++)
    {
        _matrix1[i] = new int[_cols];
    }

    for (int i = 0; i < _rows; i++)
    {
        for (int j = 0; j < _cols; j++)
        {
            _matrix1[i][j] = rand() % 100;
        }
    }
}

Matrix::Matrix(const Matrix& X)
{
    _rows = X._rows;
    _cols = X._cols;
    _matrix1 = new int* [_rows];
    for (int i = 0; i < _rows; i++)
    {
        _matrix1[i] = new int[_cols];
    }

    for (int i = 0; i < _rows; i++)
    {
        for (int j = 0; j < _cols; j++)
        {
            this->_matrix1[i][j] = X._matrix1[i][j];
        }
    }
}

void Matrix::MakeMatrix()
{
    cin >> _rows;
    _cols = _rows;
    int** matrix1 = new int* [_rows];
    for (int i = 0; i < _rows; i++)
    {
        matrix1[i] = new int[_cols];
    }

    for (int i = 0; i < _rows; i++)
    {
        for (int j = 0; j < _cols; j++)
        {
            matrix1[i][j] = rand() % 100;
        }
    }
    _matrix1 = matrix1;
}

void Matrix::Show()
{
    for (int i = 0; i < _rows; i++)
    {
        for (int j = 0; j < _cols; j++)
        {
            cout << _matrix1[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
    cout << "MATRIX" << endl;
}

Matrix Matrix::Transposition()
{
    Matrix T;
    for (int j = 0; j < _cols; j++)
    {
        for (int i = 0; i < _rows; i++)
        {
            T._matrix1[i][j] = _matrix1[i][j];
        }
        cout << endl;
    }
    return T;
}

Matrix Matrix::AdditionMatrix(const Matrix& M)
{
    Matrix T(M);
    if (this->_rows == M._cols && this->_cols == _rows)
    {
        for (int i = 0; i < _rows; i++)
        {
            for (int j = 0; j < _cols; j++)
            {
                T._matrix1[i][j] = this->_matrix1[i][j] + M._matrix1[i][j];
            }
        }
        return T;
    }
    else if (this->_rows != M._cols || this->_cols != _rows)
    {
        cout << "Вводите одинаковую размерность матриц" << endl;
    }
    return Matrix();
}

Matrix Matrix::operator+(const Matrix& M)
{
    Matrix T(M);
    if (this->_rows == M._cols && this->_cols == _rows)
    {
        for (int i = 0; i < _rows; i++)
        {
            for (int j = 0; j < _cols; j++)
            {
                T._matrix1[i][j] = this->_matrix1[i][j] + M._matrix1[i][j];
            }
        }
        return T;
    }
    else if (this->_rows != M._cols || this->_cols != _rows)
    {
        cout << "Вводите одинаковую размерность матриц" << endl;
    }
    return Matrix();
}

Matrix operator-(const Matrix& M, const Matrix& X)
{
    Matrix T(M);
    if (X._rows == M._cols && X._cols == M._rows)
    {
        for (int i = 0; i < X._rows; i++)
        {
            for (int j = 0; j < X._cols; j++)
            {
                T._matrix1[i][j] = (X._matrix1[i][j] - M._matrix1[i][j]);
            }
        }
        return T;
    }
    else if (X._rows != M._cols || X._cols != M._rows)
    {
        cout << "Размерность матриц не совпадает" << endl;
    }
    return Matrix();
}


ofstream& operator<<(ofstream& ff, Matrix& M)
{
    ofstream fout;
    fout.open("text1.txt");
    for (int i = 0; i < M._rows; i++)
    {
        for (int j = 0; j < M._cols; j++)
        {
            fout << M._matrix1[i][j] << "\t";
        }
        fout << endl;
    }
    fout.close();
    return fout;
}

fstream& operator<<(fstream& ff, Matrix& M)
{
    fstream FileBin;
    FileBin.open("text1.bin", ios_base::binary | ios::out);
    FileBin.write((char*)&M._rows, sizeof(M._cols));
    for (int i = 0; i < M._rows; i++)
    {
        for (int j = 0; j < M._cols; j++)
        {
            FileBin.write((char*)&M._matrix1[i][j],sizeof(M._rows));
        }
        FileBin << endl;
    }
    FileBin.close();
    return FileBin;
}

fstream& operator>>(fstream& ff, Matrix& M)
{
    fstream FileBin;
    FileBin.open("text1.bin", ios::binary | ios::in);
    FileBin.read((char*)&M._rows, sizeof(M._rows));
    if (M._rows <= 0) return FileBin;    // если пустая выйти
    if (M._matrix1 != NULL)              // если существует - удалить
    {
        for (int i = 0; i < M._rows; i++)
        {
            delete[] M._matrix1[i];
        }
        delete[] M._matrix1;
    }
    M._matrix1 = new int* [M._rows];
    for (int i = 0; i < M._rows; i++)
    {
        M._matrix1[i] = new int[M._cols];
    }
    for (int i = 0; i < M._rows; i++)
    {
        for (int j = 0; j < M._cols; j++)
        {
            FileBin.read((char*)&M._matrix1[i][j], sizeof(M._matrix1[i][j]));
        }
        FileBin << endl;
    }
    M.Show();
    FileBin.close();
    return FileBin;
}

Matrix& Matrix::operator=(const Matrix& X)
{
    if (this == &X)
        return *this;
    for (int i = 0; i < _rows; i++)
    {
        for (int j = 0; j < _cols; j++)
        {
            _matrix1[i][j] = 0;
        }
    }
    for (int i = 0; i < _rows; i++)
    {
        for (int j = 0; j < _cols; j++)
        {
            _matrix1[i][j] = X._matrix1[i][j];
        }
    }
    return *this;
}
 
 Matrix Matrix::operator++(int) // постфиксный
{
    Matrix tmp(*this);
    ++(*this);
    return tmp;
}

Matrix& Matrix::operator++() // префиксный
{
    for (int i = 0; i < this->_rows; i++)
    {
        for (int j = 0; j < this->_cols; j++)
        {
            this->_matrix1[i][j]++;
        }
    }
    return *this;
}

Matrix::operator int()
{
    int t;
    if (_rows == 1) return this->_matrix1[0][0];
    else if (_rows == 2)
    {
        t = this->_matrix1[0][0] * this->_matrix1[1][1] - this->_matrix1[0][1] * this->_matrix1[1][0];
        return t;
    }
    else if (_rows == 3)
    {
        t = ((this->_matrix1[0][0]) * (this->_matrix1[1][1]) * (this->_matrix1[2][2]) + (this->_matrix1[0][1]) *
            (this->_matrix1[1][2]) * (this->_matrix1[2][0]) + (this->_matrix1[0][2]) * (this->_matrix1[1][0]) * 
            (this->_matrix1[2][1])) - ((this->_matrix1[0][2]) * (this->_matrix1[1][1]) * (this->_matrix1[2][0]) + 
                (this->_matrix1[0][0]) * (this->_matrix1[1][2]) * (this->_matrix1[2][1]) + (this->_matrix1[2][2]) *
                (this->_matrix1[0][1]) * (this->_matrix1[1][0]));
        return t;
    }
    return 0;
}

Matrix::~Matrix()
{
    for (int i = 0; i < _rows; i++)
    {
        delete[] _matrix1[i];
    }
    delete[] _matrix1;
}


