#pragma once

template <class T>
class MyList 
{
private:
	struct Node
	{
		Node(T, Node*);

		T value;
		Node* next;
	};

	int size;
	Node* head;
	Node* tail;
public:
	MyList();
	~MyList();

	void push_back(T);
	void push_front(T);
	void pop_back();
	void pop_front();
	void print() const;
	void clean_up();

};
