#pragma once
#include <algorithm>
#include <iostream>
#include <string>
#include "Iterator.h"
#include "Stack.h"
#include "Queue.h"

class Heap
{
private:
	void heapify(int index);
	int getIndex(int key);
	static const int MAX_SIZE = 500;
	int* h;
	int heapSize; 
	//dft iterator extends iterator
	class DFT_Iterator : public Iterator { 
		private: 
			int curIndex;
			Heap* heap;
			Stack* stack;
		public:
			DFT_Iterator(Heap* heap);
			void next() override;
			bool hasNext() override;
			int getCur() override;
	};
	//bft iterator extends iterator
	class BFT_Iterator : public Iterator {
		private:
			int curIndex;
			Heap* heap;
			Queue* queue;
		public:
			BFT_Iterator(Heap* heap);
			void next() override;
			bool hasNext() override;
			int getCur() override;
	};
	//make iterators friend class to iterate through heap
	friend DFT_Iterator;
	friend BFT_Iterator;

public:
	Heap();
	void insert(int key);
	bool contains(int key);
	std::string getHeapString();
	void remove(int key);
	void printHeap();
	Iterator* create_dft_iterator();
	Iterator* create_bft_iterator();
};

