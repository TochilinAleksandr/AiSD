#pragma once

//Class node used for each element of list
class Node
{
public:
	Node(int data) {
		this->data = data;
		this->next = nullptr;
		this->prev = nullptr;
	}
	~Node() {
		this->data = NULL;
		this->next = nullptr;
		this->prev = nullptr;
	}
	int data; //data into the node 
	Node* next; //pointer to the next node
	Node* prev; //pointer to the previous element
};

