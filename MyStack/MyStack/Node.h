#pragma once

template <class T>
class Node
{
	T data;
	Node* next;
public:
	Node(T&);
	void setNext(Node*);
	Node* getNext();
	void setData(T&);
	T getData();

};