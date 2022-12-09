#pragma once
using namespace std;
template <typename T> 
class Node
{
public:
	Node() {};
	Node(const T& object);
	void LinkNextTo(const Node<T>& previousNode);
	void LinkBefore(const Node<T>& nextNode);
	T& GetValue()const;
	Node <T>& GetNext()const;
	Node <T>& GetPrevious()const;
private:
	Node* _next;
	Node* _previous;
	T* _object;
};


