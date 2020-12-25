#pragma once
#include <stdexcept>
#include <string>
#include <iostream>

class Stack
{
private:
	static const int MAX_SIZE = 500;
	std::string* stack;
	int indexHead;
public:
	Stack() {
		this->indexHead = -1;
		this->stack = new std::string[MAX_SIZE];
	};

	void push(std::string elem) { //add elem to array and change index of head
		indexHead++;
		stack[indexHead] = elem;
	};

	std::string pop() {  //if stack is't empty
		if (!isEmpty()) {
			indexHead--;      //reduce index of head
			return stack[indexHead + 1];  //and return popped element 
		}
		else {
			throw std::runtime_error("Stack is empty in {function pop}");
		}
	}

	std::string top() { //get first elemetn
		if (isEmpty()) {
			throw std::runtime_error("Stack is empty in {function top}");
		}
		return stack[indexHead];
	}

	std::string top(int n) { //get n element of stack
		if (getSize() < n) {
			std::string err = "Stack size lower than " + std::to_string(n) + " {in function top(int)}";
			throw std::runtime_error(err);
		}
		return stack[indexHead - n + 1];
	}
 	
	int getSize() { //return size of array
		return indexHead + 1;
	}

	bool isEmpty() {
		return indexHead == -1;
	}

	void printStack() {
		if (indexHead == -1) {
			std::cout << "empty" << std::endl;
		}
		else {
			for (int i = indexHead; i >= 0; i--)
			{
				std::cout << stack[i] << "   ";
			}
		}
	}
};