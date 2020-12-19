#pragma once
#include <stdexcept>

class Stack
{
private:
	static const int MAX_SIZE = 500;
	int* stack;
	int indexHead;
public:
	Stack() {
		this->indexHead = -1;
		this->stack = new int[MAX_SIZE];
	};
	
	void push(int elem) { //add elem to array and change index of head
		indexHead++;
		stack[indexHead] = elem;
	};

	int pop() {  //if stack is't empty
		if (!isEmpty()) {
			indexHead--;      //reduce index of head
			return stack[indexHead + 1];  //and return popped element 
		}
		else {
			throw std::runtime_error("Stack is empty");
		}
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
				std::cout << stack[i] << " ";
			}
		}
	}
};

