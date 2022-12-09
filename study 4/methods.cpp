#include "headers.h"

using namespace std;

int Polynom::countDigits(int x)
{
	int n = 0;
	if (x == 0) return 1;
	for (int i = abs(x); i > 0; i /= 10) n++;
	return n;
}

void Polynom::numberToString(char* str, int num, int& index)
{
	int k = countDigits(num);
	if (num < 0) str[index++] = '-';

	for (int i = k; i > 0; i--) str[index++] = '0' + num / (int)pow(10, i - 1) % 10;
}

void Polynom::strsize()
{
	int n = 0;
	for (int i = power, nz = 0; i >= 0; i--) {
		if (i == 0) {
			if (nz == 0) n += countDigits(multipliers[0]);
			if (nz > 0 && multipliers[0] != 0) n += 3 + countDigits(multipliers[0]);
			continue;
		}

		if (multipliers[i] == 0) continue;
		nz++;

		if (i == power) {
			if (multipliers[i] < 0) n++;
			if (abs(multipliers[i]) != 1) n += 3 + countDigits(multipliers[i]);
			if (i > 1) n += 2 + countDigits(i);
			if (i == 1) n++;
			continue;
		}

		n += 3;

		if (abs(multipliers[i]) != 1) n += 3 + countDigits(multipliers[i]);
		n++;
		if (i > 1) n += 1 + countDigits(i);
	}
	pollength = n;
}

void Polynom::toStr()
{
	strsize();
	int k = 0;
	if (polstr != nullptr) delete[] polstr;
	polstr = new char[pollength + 1]{};
	for (int i = power, nz = 0; i >= 0; i--) {
		if (i == 0) {
			if (nz == 0) numberToString(polstr, multipliers[0], k);
			if (nz > 0 && multipliers[0] != 0) {
				polstr[k++] = ' ';
				polstr[k++] = (multipliers[i] > 0) ? '+' : '-';
				polstr[k++] = ' ';
				numberToString(polstr, abs(multipliers[0]), k);
			}
			continue;
		}

		if (multipliers[i] == 0) continue;
		nz++;

		if (i == power) {
			if (multipliers[i] < 0) polstr[k++] = '-';
			if (abs(multipliers[i]) != 1) {
				numberToString(polstr, abs(multipliers[i]), k);
				polstr[k++] = ' ';
				polstr[k++] = '*';
				polstr[k++] = ' ';
			}
			if (i > 1) {
				polstr[k++] = 'x';
				polstr[k++] = '^';
				numberToString(polstr, i, k);
			}
			if (i == 1) polstr[k++] = 'x';
			continue;
		}

		polstr[k++] = ' ';
		polstr[k++] = (multipliers[i] > 0) ? '+' : '-';
		polstr[k++] = ' ';

		if (abs(multipliers[i]) != 1) {
			numberToString(polstr, abs(multipliers[i]), k);
			polstr[k++] = ' ';
			polstr[k++] = '*';
			polstr[k++] = ' ';
		}
		polstr[k++] = 'x';
		if (i > 1) {
			polstr[k++] = '^';
			numberToString(polstr, i, k);
		}
	}
}

Polynom::Polynom()
{
	power = 0;
	multipliers = new int[1];
	multipliers[0] = 0;
	pollength = 0;
	polstr = nullptr;
	next = prev = nullptr;
}

Polynom::Polynom(const Polynom& p)
{
	this->power = p.power;
	this->multipliers = new int[p.power + 1];
	for (int i = 0; i < power + 1; i++)
		this->multipliers[i] = p.multipliers[i];
	this->pollength = 0;
	this->polstr = nullptr;
	this->next = p.next;
	this->prev = p.prev;
}

Polynom::~Polynom()
{
	if (multipliers != nullptr) delete[] multipliers;
	if (polstr != nullptr) delete[] polstr;
}

Polynom::Polynom(int ipower) {
	power = ipower;
	multipliers = new int[power + 1];
	for (int i = 0; i < power + 1; i++) multipliers[i] = 0;
	pollength = 0;
	polstr = nullptr;
	next = prev = nullptr;
}

void Polynom::print()
{
	toStr();
	cout << polstr << endl;
}

int Polynom::solve(int x)
{
	int t = 0;
	for (int i = 0; i <= power; i++) {
		t += multipliers[i] * (int)pow(x, i);
	}
	return t;
}

Polynom Polynom::add(Polynom a)
{
	Polynom t;
	if (a.power >= this->power) t.newPower(a.power);
	else t.newPower(this->power);

	for (int i = 0; i < t.power + 1; i++) {
		if (i <= a.power && i <= this->power) t.multipliers[i] = a.multipliers[i] + this->multipliers[i];
		if (i <= a.power && i > this->power) t.multipliers[i] = a.multipliers[i];
		if (i > a.power && i <= this->power) t.multipliers[i] = this->multipliers[i];
	}
	return t;
}

Polynom Polynom::operator+(const Polynom& a)
{
	Polynom t;
	if (a.power >= this->power) t.newPower(a.power);
	else t.newPower(this->power);

	for (int i = 0; i < t.power + 1; i++) {
		if (i <= a.power && i <= this->power) t.multipliers[i] = a.multipliers[i] + this->multipliers[i];
		if (i <= a.power && i > this->power) t.multipliers[i] = a.multipliers[i];
		if (i > a.power && i <= this->power) t.multipliers[i] = this->multipliers[i];
	}
	return t;
}

Polynom operator-(const Polynom& a, const Polynom& b)
{
	Polynom t;
	if (a.power >= b.power) t.newPower(a.power);
	else t.newPower(b.power);

	for (int i = 0; i < t.power + 1; i++) {
		if (i <= a.power && i <= b.power) t.multipliers[i] = a.multipliers[i] - b.multipliers[i];
		if (i <= a.power && i > b.power) t.multipliers[i] = a.multipliers[i];
		if (i > a.power && i <= b.power) t.multipliers[i] = -b.multipliers[i];
	}
	return t;
}

Polynom& Polynom::operator=(const Polynom& a)
{
	if (this == &a) return *this;
	this->newPower(a.power);
	this->pollength = a.pollength;
	for (int i = 0; i < a.power + 1; i++) this->multipliers[i] = a.multipliers[i];
	return *this;
}

Polynom& Polynom::operator++()
{
	for (int i = 0; i <= power; i++) this->multipliers[i]++;
	return *this;
}

Polynom Polynom::operator++(int)
{
	Polynom prev(*this);
	for (int i = 0; i <= power; i++) this->multipliers[i]++;
	return prev;
}

Polynom::operator char* ()
{
	toStr();
	char* t = new char[pollength + 1]{};
	for (int i = 0; i <= pollength; i++) t[i] = polstr[i];
	return t;
}

istream& operator >> (istream& is, Polynom& p)
{
	is >> p.power;
	if (!p.multipliers) delete[] p.multipliers;
	p.multipliers = new int[p.power + 1];
	for (int i = 0; i <= p.power; i++) is >> p.multipliers[i];
	return is;
}

ostream& operator << (ostream& os, Polynom& p)
{
	p.toStr();
	os << p.polstr << '\n';
	return os;
}

void Polynom::saveBin(ostream& os)
{
	os.write((char*)&this->power, sizeof(int));
	for (int i = 0; i < this->power + 1; i++)
		os.write((char*)&this->multipliers[i], sizeof(int));
}

void Polynom::loadBin(istream& is)
{
	is.read((char*)&this->power, sizeof(int));
	if (this->multipliers) delete[] multipliers;
	this->multipliers = new int[power + 1];
	for (int i = 0; i < this->power + 1; i++)
		is.read((char*)&this->multipliers[i], sizeof(int));
}
//throw
void Polynom::setMultiplier(int index, int mul)
{
	if (index < 0 || index > power) throw "Polynom::setMultiplier - Index out of range";
	multipliers[index] = mul;
}

void Polynom::setNodeNext(Polynom* nxt) { this->next = nxt; }

void Polynom::setNodePrev(Polynom* prv) { this->prev = prv; }
//throw
void Polynom::newPower(int index)
{
	if (index < 0) throw "Polynom::newPower - Incorrect index";
	delete[] multipliers;
	power = index;
	multipliers = new int[index + 1];
	for (int i = 0; i < power + 1; i++) multipliers[i] = 0;
}

int Polynom::getMultiplier(int index)
{
	if (index > this->power) return 0;
	return multipliers[index];
}

int Polynom::getPower() { return power; }

Polynom* Polynom::getNodeNext() { return next; }

Polynom* Polynom::getNodePrev() { return prev; }



QuadraticEquation::QuadraticEquation(int a, int b, int c) : Polynom(2) {
	multipliers[2] = a;
	multipliers[1] = b;
	multipliers[0] = c;
}

QuadraticEquation::QuadraticEquation(QuadraticEquation& t) : Polynom(t) {}

Polynom QuadraticEquation::add(Polynom a)
{
	Polynom t(2);
	t.setMultiplier(0, a.getMultiplier(0) + this->getMultiplier(0));
	if (t.getPower() > 0) t.setMultiplier(1, a.getMultiplier(1) + this->getMultiplier(1));
	if (t.getPower() > 1) t.setMultiplier(2, a.getMultiplier(2) + this->getMultiplier(2));

	return t;
}

Polynom& QuadraticEquation::operator=(Polynom& a)
{
	if (this == &a) return *this;
	for (int i = 0; i < 3; i++) this->multipliers[i] = a.getMultiplier(i);
	return *this;
}

void QuadraticEquation::newPower(int index) { return; };

void QuadraticEquation::print()
{
	//вызов метода получения строки из базового класса
	toStr();

	cout << polstr << " = 0" << endl;
}

void QuadraticEquation::findx()
{
	double a, b, c;
	a = multipliers[2];
	b = multipliers[1];
	c = multipliers[0];
	
	double x1, x2;
	if (!a && !b && !c) { cout << "x = R" << endl; return; }
	if (!a && !b &&  c) { cout << "x1 and x2 not exist" << endl; return; }
	if ((a || b) && !c) { cout << "x = 0" << endl; return; }
	if (!a &&  b &&  c) { cout << "x = " << -c / b << endl; return; }
	if ((b * b - 4 * a * c) < 0) { cout << "x1 and x2 not exist" << endl; return; }
	x1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
	x2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
	cout << "x1 = " << x1 << ", x2 = " << x2 << endl;
}



LinearFunction::LinearFunction(int a, int b) : Polynom(1)
{
	multipliers[1] = a;
	multipliers[0] = b;
}

LinearFunction::LinearFunction(LinearFunction& t) : Polynom(t) {}

Polynom LinearFunction::add(Polynom a)
{
	Polynom t(1);
	t.setMultiplier(0, a.getMultiplier(0) + this->getMultiplier(0));
	if (t.getPower() > 0) t.setMultiplier(1, a.getMultiplier(1) + this->getMultiplier(1));

	return t;
}

Polynom& LinearFunction::operator=(Polynom& a)
{
	if (this == &a) return *this;
	for (int i = 0; i < 2; i++) this->multipliers[i] = a.getMultiplier(i);
	return *this;
}

void LinearFunction::newPower(int index) { return; };

void LinearFunction::print()
{
	//вызов метода получения строки из базового класса
	toStr();

	cout << "y = " << polstr << endl;
}

double LinearFunction::angle()
{
	double a = atan(multipliers[1]) * 180 / M_PI;
	int t = a * 100000;
	if (t % 10 >= 5) t += 10;
	a = t / 100000.0;

	return a;
}



void DoubleQueue::add(Polynom* pol)
{
	Polynom* t = nullptr;
	switch (pol->getType()) {
	case 1:
		t = new Polynom(*pol);
		break;
	case 2:
		t = new QuadraticEquation((QuadraticEquation&)*pol);
		break;
	case 3:
		t = new LinearFunction((LinearFunction&)*pol);
		break;
	}

	if (pbeg == nullptr) {
		pbeg = t;
		pbeg->setNodeNext(pbeg);
		pbeg->setNodePrev(pbeg);
	}
	else {
		Polynom* pr = pbeg->getNodePrev();
		pbeg->setNodePrev(t);
		pr->setNodeNext(t);
		t->setNodeNext(pbeg);
		t->setNodePrev(pr);
	}
	amount++;
}

Polynom* DoubleQueue::pop()
{
	if (amount == 0) return nullptr;
	Polynom* ret = pbeg;
	Polynom* tn = pbeg->getNodeNext();
	Polynom* tp = pbeg->getNodePrev();
	tp->setNodeNext(tn);
	tn->setNodePrev(tp);
	pbeg = tn;
	ret->setNodeNext(nullptr);
	ret->setNodePrev(nullptr);
	amount--;
	return ret;
}

void DoubleQueue::insert(Polynom* pol, int index)
{
	Polynom* t = pbeg;
	for (int i = 0; i < index; i++) t = t->getNodeNext();
	Polynom* tp = t->getNodePrev();
	Polynom* tc = t;
	switch (pol->getType()) {
	case 1:
		t = new Polynom(*pol);
		break;
	case 2:
		t = new QuadraticEquation((QuadraticEquation&)*pol);
		break;
	case 3:
		t = new LinearFunction((LinearFunction&)*pol);
		break;
	}
	tp->setNodeNext(t);
	tc->setNodePrev(t);
	t->setNodeNext(tc);
	t->setNodePrev(tp);
	amount++;
}

void DoubleQueue::del(int index)
{
	Polynom* t = pbeg;
	for (int i = 0; i < index; i++) t = t->getNodeNext();
	Polynom* tn = t->getNodeNext();
	Polynom* tp = t->getNodePrev();
	tp->setNodeNext(tn);
	tn->setNodePrev(tp);
	if (index == 0) pbeg = tn;
	delete t;
	amount--;
}

void DoubleQueue::print()
{
	Polynom* t = pbeg;
	for (int i = 0; i < amount; i++) {
		cout << i << ":\t";
		t->print();
		t = t->getNodeNext();
	}
}

int DoubleQueue::search(int power)
{
	Polynom* t = pbeg;
	for (int i = 0; i < amount; i++) {
		if (t->getPower() == power)
			return i;
		t = t->getNodeNext();
	}

	return -1;
}

DoubleQueue::~DoubleQueue()
{
	while (amount) del(0);
}