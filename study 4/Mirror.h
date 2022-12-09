#pragma once
#include "Matrix.h"
#include <iostream>
#include <ctime>
#include <fstream>

class Mirror : public Matrix
{
private:
	char* stroka;
public:
	Mirror();
	Mirror(const char*, int, int);
	Mirror(Mirror& copy);

	~Mirror();

	void SetStroka(const char*);
	void Show();
	void Show(const char*);
};

