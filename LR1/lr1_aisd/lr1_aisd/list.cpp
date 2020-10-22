#include "list.h"
#include <iostream>

//check if end is empty
bool List::isEmptyEnd() 
{
	return this->end == nullptr;
}

//constructor
List::List() 
{
	this->head = nullptr;
	this->end = nullptr;
	this->size = 0;
}

//destructor del all elems from list
List::~List()
{
	clear();
}

//check if head is empty
bool List::isEmpty()
{
	return this->head == nullptr;
}

//add new list befind current list
//set head to new list head
//connect two lists
//and sum sizes
void List::push_front(List prevList)
{
	prevList.end->next = this->head;
	this->head->prev = prevList.end;
	this->head = prevList.head;
	size += prevList.size;
}

//retrun list size
size_t List::get_size()
{
	return this->size;
}

//add new elem to list head
//if list empty, set elem to head
//if end empty, set elem to end
//else set new end, connect to previous elem
void List::push_back(int elem)
{
	this->size++;
	Node* newEnd= new Node(elem);
	if (isEmpty()) {
		head = newEnd;
	}
	else if (isEmptyEnd()) {
		this->end = newEnd;
		this->head->next = this->end;
		this->end->prev = this->head;
	}
	else {
		this->end->next = newEnd;
		newEnd->prev = this->end;
		this->end = newEnd;
	}
}

//add new elem to list end
//if list empty, set elem to head
//if end empty, set elem to end
//else add set new, end connect to previous elem
void List::push_front(int elem)
{
	this->size++;
	Node* newHead = new Node(elem);
	if (isEmpty()) {
		head = newHead;
	}
	else if (isEmptyEnd()){
		this->end = this->head;
		this->head = newHead;
		this->head->next = this->end;
		this->end->prev = this->head;
	}
	else {
		newHead->next = this->head;
		this->head->prev = newHead;
		this->head = newHead;
	}
}

//pop elem from back of list
//if list emptu return
//if end is empty pop head
//else set new end and del previous
void List::pop_back()
{
	if (isEmpty()) {
		return;
	}
	else if (isEmptyEnd()) {
		size--;
		this->head = nullptr;
	}
	else {
		size--;
		this->end = this->end->prev;
		delete this->end->next;
		this->end->next = nullptr;
	}
}

//pop elem from head of list
//if list empty return
//if size = 1, delete head
//else set new head, and del previous
//if after pop head = end delete end
void List::pop_front()
{
	if (isEmpty()) {
		return;
	}
	else if (size == 1) {
		size--;
		delete this->head;
		this->head = nullptr;
	}
	else {
		this->size--;
		this->head = this->head->next;
		this->head->prev = nullptr;
		if (this->head == this->end) {
			this->head = new Node(this->head->data);
			this->end = nullptr;
			this->head->next = nullptr;
		}
	}
}


//insert elem into list by index
//if index go over list return
//else find node with required index and insert new node before
void List::insert(int elem, size_t index)
{
	if (index > ((this->size) - 1)) {
		return;
	}
	else if (index == 0) {
		push_front(elem);
	}
	else
	{
		this->size++;
		Node* newNode = new Node(elem);
		Node* curNode = this->head;
		for (size_t i = 0; i < index; i++) {
			curNode = curNode->next;
		}
		newNode->next = curNode;
		newNode->prev = curNode->prev;
		curNode->prev->next = newNode;
		curNode->prev = newNode;
	}
}

int List::at(size_t index)
{
	if (index == 0) {
		return head->data;
	}
	else if (index == size - 1) {
		return end->data;
	}
	else {
		Node* curNode = this->head;
		for (size_t i = 0; i < index; i++) {
			curNode = curNode->next;
		}
		return curNode->data;
	}
}

void List::remove(size_t index)
{
	if (index > (this->size - 1)) {
		std::cout << "Индекс больше размера списка" << std::endl;
	}
	else if (index == this->size - 1) {
		pop_back();
	}
	else if (index == 0) {
		pop_front();
	} {
		size--;
		Node* curNode = this->head;
		for (size_t i = 0; i < index; i++) {
			curNode = curNode->next;
		}
		curNode->prev->next = curNode->next;
		curNode->next->prev = curNode->prev;
		delete curNode;
	}

}

//print all nodes to consloe one by one
//iterate in list and print each data in it and separate nodes by " -> "
void List::print_to_console()
{
	if (isEmpty()) {
		std::cout << "Список пустой" << std::endl;
	}
	else {
		Node* curNode = this->head;
		do {
			std::cout << curNode->data << " -> ";
			curNode = curNode->next;
		} while (curNode != nullptr);
		std::cout << "nullptr" << std::endl;
	}
}

//clear the list by pop first node while list is not empty
void List::clear(){
	while (!isEmpty()) {
		pop_front();
	}
}

//set new data into node by index
//if index higher last node index return
//if index = index of the end, set data to end
//else iterete in list and find required node  and set data to it
void List::set(size_t index, int data)
{
	if (index > (this->size - 1)) {
		return;
	}
	else if (index == this->size - 1) {
		this->end->data = data;
	}
	else {
		Node* curNode = this->head;
		for (size_t i = 0; i < index; i++) {
			curNode = curNode->next;
		}
		curNode->data = data;
	}
}