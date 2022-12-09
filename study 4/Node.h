#pragma once

template <typename T> 
class Node
{
public:
	Node(const T& object)
	{
		_object = &object;
		_next = nullptr;
		_previous = nullptr;
	}
	
	void LinkNextTo(Node<T>& previousNode)
	{
		_previous = &previousNode;
		previousNode._next = this;
	}
	
	void LinkBefore(Node<T>& nextNode)
	{
		_next = &nextNode;
		nextNode._previous = this;
	}
	
	const T& GetValue() const { return *_object; }
	Node<T>& GetNext() const { return *_next; }
	Node<T>& GetPrevious() const { return *_previous; }
private:
	Node* _next;
	Node* _previous;
	const T* _object = nullptr;
};

