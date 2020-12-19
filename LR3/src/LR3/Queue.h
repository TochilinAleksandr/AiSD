#pragma once
#pragma once
#include <stdexcept>
#include <iostream>

class Queue
{
private:
	static const int MAX_SIZE = 500;
	int* queue;
	int indexHead;
	int indexTail;

public:
	Queue() {
		this->indexHead = 0;
		this->indexTail = 0;
		this->queue = new int[MAX_SIZE];
	};

	void push(int elem) { //raise index of tail and push new elem to the end of queue
		queue[indexTail] = elem; 
		indexTail++;
		
	};

	int pop() {  //raise head and return head elem
		if (!isEmpty()) {
			indexHead++;
			return queue[indexHead - 1];
		}
		else {
			throw std::runtime_error("Stack is empty");
		}
	}

	bool isEmpty() {   //tail and head equal
		return indexHead == indexTail;
	}

	void printQueue() {
		if (isEmpty()) {
			std::cout << "empty" << std::endl;
		}
		else {
			for (int i = indexTail - 1; i >= indexHead; i--)
			{
				std::cout << queue[i] << " ";
			}
		}
	}
};

