#include "Heap.h"

Heap::Heap()  //at create heap has 0 size
{
	h = new int[MAX_SIZE];
	heapSize = 0;
}

void Heap::insert(int key) 
{
	int i, parent;
	i = this->heapSize;
	h[i] = key;            //insert new element to the end of heap array
	parent = (i - 1) / 2;  //start parent of new element 
	while (parent >= 0 && i > 0) {  //raise from bottom of heap to the top
		if (h[i] > h[parent]) {   //raise element if parent lower
			std::swap(h[parent], h[i]);
		}
		i = parent;
		parent = (i - 1) / 2;
	}
	(this -> heapSize)++; 

}

bool Heap::contains(int key)  
{
	if (key > h[0]) {   //if key higher than head no reason to search 
		return false;
	}
	Iterator* dftIterator = create_dft_iterator();   //use dft iterartor for searching key
	while (dftIterator->hasNext()) {
		dftIterator->next();
		if (dftIterator->getCur() == key) {
			return true;
		}
	}
	return false;
}

std::string Heap::getHeapString()      //function used for getting head as a string 
{
	std::string result = "";
	for (int i = 0; i < this -> heapSize; i++) {
		result += std::to_string(h[i]);
		result += " ";
	}
	result.erase(result.length() - 1, 1);
	return result;
}

void Heap::remove(int key)
{
	int index = getIndex(key);    //get index for removing elemet
	if (index == -1) {
		throw std::runtime_error("No such element in the heap");
	}
	h[index] = h[(this->heapSize)- 1];  //change deleting element to the last o heap array  
	(this->heapSize) --;  
	heapify(index);   //after deleting should make tree heap again 
}

void Heap::printHeap()
{
	int i = 0;
	int k = 1;
	while (i < this->heapSize) {
		while ((i < k) && (i < this->heapSize)) {
			std::cout << h[i] << " ";
			i++;
		}
		std::cout << std::endl;
		k = k * 2 + 1;
	}
}

Iterator* Heap::create_dft_iterator()
{
	return new DFT_Iterator(this);
}

Iterator* Heap::create_bft_iterator()
{
	return new BFT_Iterator(this);
}

void Heap::heapify(int index)  // function make tree heap again 
{   //start cheching heap array from index send to function
	int indexLeft, indexRight;
	int temp;
	indexLeft = 2 * index + 1;  //indexes of left and right roots of the current
	indexRight = 2 * index + 2;
	if (indexLeft < (this->heapSize)) { //if current elem has left root 
		if (h[index] < h[indexLeft]) {
			std::swap(h[index], h[indexLeft]);
			heapify(indexLeft);    //swap elems and check heap for left root
		}
	}
	if (indexRight < (this->heapSize)) { //if current elem has right root 
		if (h[index] < h[indexRight]) {
			std::swap(h[index], h[indexRight]);
			heapify(indexRight);
		}
	}
}

int Heap::getIndex(int key)   //check is elem in array and return int index in heap array 
{
	for (int i = 0; i < this->heapSize; i++) {
		if (h[i] == key) {
			return i;
		}
	}
	return -1;
}

Heap::DFT_Iterator::DFT_Iterator(Heap* heap)
{
	this->curIndex = -1;
	this->heap = heap;
	this->stack = new Stack();
}

void Heap::DFT_Iterator::next()    //move Iterator to the next elem
{
	if (curIndex == -1) {
		curIndex = 0;
		return;
	}
	int indexLeft = curIndex * 2 + 1;
	int indexRight = curIndex * 2 + 2;
	if (indexRight <= (this->heap -> heapSize - 1)) { //if cur elem has left root push to stack
		stack -> push(indexRight);
		curIndex = indexLeft;
	}
	else if (indexLeft <= (this->heap-> heapSize - 1)) { //if cur elem has only left elem
		curIndex = indexLeft;
	}
	else if (stack -> isEmpty()) {   //if stack is empty and no children 
		std::cout << "No next" << std::endl;
	}
	else {   //if no children pop root from stack and move to it
		curIndex = stack -> pop();
	}
}

bool Heap::DFT_Iterator::hasNext()
{
	int indexLeft = curIndex * 2 + 1;
	int indexRight = curIndex * 2 + 2; //if root has childrens or stack isn't empty can move iterator 
	if ((indexLeft <= (this->heap->heapSize - 1)) || (indexRight <= (this->heap->heapSize - 1)) || !stack->isEmpty()) { 
		return true;
	}
	else {
		return false;
	}
}

int Heap::DFT_Iterator::getCur()
{
	if (curIndex < 0) {
		throw std::runtime_error("No such index in heap");
	}
	return this->heap->h[curIndex];
}

Heap::BFT_Iterator::BFT_Iterator(Heap* heap)
{
	curIndex = 0;
	this->heap = heap;
	this->queue = new Queue();
	queue -> push(curIndex);
}

void Heap::BFT_Iterator::next()  //get current element from queue and push it's childrens to queue
{
	curIndex = queue -> pop();
	int indexLeft = curIndex * 2 + 1;
	int indexRight = curIndex * 2 + 2;
	if (indexLeft <= (this -> heap -> heapSize - 1)) {
		queue -> push(indexLeft);
	}
	if (indexRight <= (this->heap -> heapSize - 1)) {
		queue -> push(indexRight);
	}
}

bool Heap::BFT_Iterator::hasNext()  //if wueue is't empty can move to the next 
{
	if (queue -> isEmpty()) {
		return false;
	}
	else {
		return true;
	}
}

int Heap::BFT_Iterator::getCur()
{
	if (curIndex < 0) {
		throw std::runtime_error("No such index in heap");
	}
	return this->heap->h[curIndex];
}
