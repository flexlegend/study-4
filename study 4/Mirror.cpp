#include "Mirror.h"

Mirror::Mirror()
{
	stroka = nullptr;
}

Mirror::Mirror(const char* a, int rows, int cols) : Matrix(rows, cols)
{
	if (a == nullptr) 
	{
		return;
	}
	stroka = new char[strlen(a) + 1];
	strcpy(stroka, a);
}

Mirror::Mirror(Mirror& X) : Matrix(X)
{
	stroka = nullptr;
	if (X.stroka != nullptr) {
		stroka = new char[strlen(X.stroka) + 1];
		strcpy(stroka, X.stroka);
	}
}

Mirror::~Mirror()
{
	delete[] stroka;
}

void Mirror::SetStroka(const char* a)
{
	if (a != nullptr) {
		stroka = new char[strlen(a) + 1];
		strcpy(stroka, a);
	}
}

void Mirror::Show()
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

	if (stroka != nullptr) {
		cout << stroka << endl;
	}
}

void Mirror::Show(const char* a)
{
	if (a != nullptr) {
		cout << a << endl;
	}
}
