#pragma once
#include "Node.h"
using namespace std;
template <typename T>
class List
{
public:
	List();
	void Add(const T& value);
	//void Insert();
	//void Del(int);
	//void Show();
	//int Search(int);
	//~List();
private:
	Node <T>* _head;
	int _count;
	void AssignValue(Node<T>& node);
};


