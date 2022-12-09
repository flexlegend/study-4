#include "List.h"

template<typename T>
List<T>::List()
{
	_head = nullptr;
	_count = 0;
}

template<typename T>
void List<T>::Add(const T& value)
{
	Node<T>* newNode = new Node(value);
	if (_head == nullptr)
	{
		_head = newNode;  // Ставим указатель хеда на новый элемент 
	}
	AssignValue(newNode);
}

template<typename T>
void List<T>::AssignValue(Node<T>& node)
{
	_head->LinkNextTo(node);	
	_count++;
}
