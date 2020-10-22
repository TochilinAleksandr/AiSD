#pragma once
#include <cstring>
#include <iostream>
#include "node.h"

//class List

class List
{
private:
	Node* head; //first node of list
	Node* end; //last node of list
	size_t size; //size of list
	bool isEmptyEnd();

public:
	List();
	~List();

	void push_back(int elem);

	void push_front(int elem);

	void pop_back();
	
	void pop_front();

	void insert(int, size_t);

	int at(size_t);

	void remove(size_t);

	size_t get_size();

	void print_to_console();

	void clear();

	void set(size_t, int);

	bool isEmpty();

	void push_front(List);
};

