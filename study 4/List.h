#pragma once
#include "Node.h"
using namespace std;
template <typename T>
class List
{
public:
	List()
	{
		_head = nullptr;
		_count = 0;
	}
	void Add(const T& value)
	{
		Node<T>* newNode = new Node(value);
		if (_head == nullptr)
		{
			_head = newNode;  // Ставим указатель хеда на новый элемент 

		}
		AssignValue(*newNode);
	}
	//void Insert();
	//void Del(int);
	//void Show();
	//int Search(int);
	//~List();
private:
	Node<T>* _head;
	int _count;
	void AssignValue(Node<T>& node)
	{
		auto lastItem =&_head->GetPrevious();
		node.LinkBefore(*_head);
		if(lastItem != nullptr) node.LinkNextTo(*lastItem);
		_count++;
	}
};


