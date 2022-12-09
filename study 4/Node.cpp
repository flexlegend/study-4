#include "Node.h"

template<typename T>
Node<T>::Node(const T& object)
{
	_object = object;
	_next = nullptr;
	_previous = nullptr;
}

template<typename T>
void Node<T>::LinkNextTo(const Node<T>& previousNode)
{
	_previous = previousNode;
	previousNode._next = this;
}

template<typename T>
void Node<T>::LinkBefore(const Node<T>& nextNode)
{
	_next = nextNode;
	nextNode._previous = this;
}

template<typename T>
T& Node<T>::GetValue()const
{
	return _object;
}

template<typename T>
Node<T>& Node<T>::GetNext() const
{
	return _next;
}

template<typename T>
Node<T>& Node<T>::GetPrevious() const
{
	return _previous;
}
