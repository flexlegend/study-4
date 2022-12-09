#include "Order.h"

Order::Order()
{
   int _m = 0;
   int _size = 0;
}

Order::Order(int size, int rows, int cols) : Matrix(rows, cols)
{
    _size = size;
    _m = this->_m;
   
    int* _m = new int[_size];
    for (int i = 0; i < _size; i++)
    {
        _m[i] = rand() % 25;
    }
    cout << endl;

    for (int i = 0; i < _size; i++)
    {
        cout << _m[i] << endl;
    }
    cout << endl;
}

Order::Order(const Order& X) : Matrix(X)
{
    _size = X._size;
    int* _m = new int[_size];
    for (int i = 0; i < _size; i++)
    {
        this->_m[i] = X._m[i];
    }
}

void Order::MakeArr()
{
    cout << "Введите количество цифр" << endl;
    cin >> _size;
    int *m= new int[_size];
    for (int i = 0; i < _size; i++)
    {
        m[i] = rand() % 25;
    }
    _m = m;
}

void Order::Show() 
{
    cout << "order show" << endl;
    Matrix::Show();
    for (int i = 0; i < _size; i++)
    {
        cout << _m[i] << endl;
    }
    cout << endl;
    cout << "ORDER" << endl;
}

void Order::Sort()
{
    int tmp, i, j;

    for (i = 0; i < _size - 1; ++i)
    {
        for (j = 0; j < _size - 1; ++j)
        {
            if (_m[j + 1] < _m[j])
            {
                tmp = _m[j + 1];
                _m[j + 1] = _m[j];
                _m[j] = tmp;
            }
        }
    }
}

Order::~Order()
{
        delete[] _m;
}
