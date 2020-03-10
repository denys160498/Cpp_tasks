#include "Node.h"

template <class T>
void Node<T>::setNext(Node* next)
{
	this->next = next;
}

template <class T>
void Node<T>::setData(T& d)
{
	data = d;
}

template <class T>
Node<T>::Node(T& d) :data(d), next(nullptr)
{
}

template <class T>
Node<T>* Node<T>::getNext()
{
	return this->next;
}

template <class T>
T Node<T>::getData()
{
	return this->data;
}