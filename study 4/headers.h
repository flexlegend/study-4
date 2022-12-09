#define _USE_MATH_DEFINES
#include <iostream>
#include <fstream>
#include <ctime>      //srand(time())
#include <cmath>      //abs()

class Polynom {
protected:
	int power;
	int* multipliers = nullptr;
	int pollength;
	char* polstr;
	int countDigits(int x);
	void numberToString(char* str, int num, int& index);
	void strsize();
	void toStr();
	Polynom* next;
	Polynom* prev;
public:
	Polynom();                              //конструктор по умолчанию
	Polynom(const Polynom& p);              //конструктор копирования
	Polynom(int ipower);                    //конструктор с параметрами
	~Polynom();

	virtual void print();                   //вывод многочлена
	int solve(int x);                       //вычисление значения многочлена для заданного параметра
	virtual Polynom add(Polynom a);         //сложение двух объектов класса

	Polynom operator + (const Polynom& a);
	friend Polynom operator - (const Polynom& a, const Polynom& b);
	Polynom& operator = (const Polynom& a);
	Polynom& operator ++ ();
	Polynom operator ++ (int);
	operator char* ();

	friend std::istream& operator >> (std::istream&, Polynom&);
	friend std::ostream& operator << (std::ostream&, Polynom&);
	void saveBin(std::ostream& os);
	void loadBin(std::istream& is);

	virtual void newPower(int index);

	void setMultiplier(int index, int mul);
	void setNodeNext(Polynom* nxt);
	void setNodePrev(Polynom* prv);

	int getMultiplier(int index);
	int getPower();
	Polynom* getNodeNext();
	Polynom* getNodePrev();
	virtual int getType() { return 1; }
};

class QuadraticEquation : public Polynom {
public:
	QuadraticEquation(int a = 0, int b = 0, int c = 0);
	QuadraticEquation(QuadraticEquation& t);

	Polynom add(Polynom a) override;

	Polynom& operator = (Polynom& a);

	void newPower(int index) override;
	void print() override;

	void findx();

	int getType() { return 2; }
};

class LinearFunction : public Polynom {
public:
	LinearFunction(int a = 0, int b = 0);
	LinearFunction(LinearFunction& t);

	Polynom add(Polynom a) override;

	Polynom& operator = (Polynom& a);

	void newPower(int index) override;
	void print() override;

	double angle();

	int getType() { return 3; }
};

//двунаправленная циклическая очередь
class DoubleQueue {
	Polynom* pbeg;
	int amount;
public:
	DoubleQueue() { pbeg = nullptr; amount = 0; }

	void add(Polynom* pol);
	Polynom* pop();
	void insert(Polynom* pol, int index);
	void del(int index);
	void print();
	int search(int power);

	~DoubleQueue();
};