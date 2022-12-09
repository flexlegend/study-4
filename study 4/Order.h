#pragma once
#include "Matrix.h"
#include <iostream>
#include <ctime>
#include <fstream>

class Order : public Matrix
{
private:
	int* _m;
	int _size;
public:
	Order();
	Order(int, int, int);
	Order(const Order&);

	~Order();
	
	void MakeArr();
	void Show();
	void Sort(); //сортировка по возрастанию
};

