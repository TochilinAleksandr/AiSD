#include "List.h"

template<typename T> bool List<T>::HasNext()
{
	if (this->Size != 0 && cur != nullptr)
		return true;
	else
		return false;
}

template<typename T> void List<T>::iterator(Node* curent)
{
	cur = curent;
}

template<typename T> void List<T>::push_with_count(T obj, int count)
{
	if (head != NULL) {
		this->tail->Next = new Node(obj, count);
		tail = tail->Next;
	}
	else {
		this->head = new Node(obj, count);
		this->tail = this->head;
	}
	Size++;
}

template<typename T> void List<T>::push_back(T obj) { // add to back of list
	if (head != NULL) {
		this->tail->Next = new Node(obj);
		tail = tail->Next;
	}
	else {
		this->head = new Node(obj);
		this->tail = this->head;
	}
	Size++;
}
template<typename T> void List<T>::push_front(T obj) { // add to head of list
	if (head != NULL) {
		Node* current = new Node;
		current->data = obj;
		current->Next = this->head;
		this->head = current;
	}
	else {
		this->head = new Node(obj);
	}
	this->Size++;
}
template<typename T> void List<T>::pop_back() { // delete last elem  
	if (head != NULL) {
		Node* current = head;
		while (current->Next != tail)//search last
			current = current->Next;
		delete tail;
		tail = current;
		tail->Next = NULL;
		Size--;
	}
	else throw std::out_of_range("out_of_range");
}
template<typename T> void List<T>::pop_front() { // delete first elem 
	if (head != NULL) {
		Node* current = head;
		head = head->Next;
		delete current;
		Size--;
	}
	else throw std::out_of_range("out_of_range");
}
template<typename T> void List<T>::insert(T obj, size_t k) {
	// add elem by index, insert before elem with this index
	if (k >= 0 && this->Size > k) {
		if (this->head != NULL) {
			if (k == 0)
				this->push_front(obj);
			else
				if (k == this->Size - 1)
					this->push_back(obj);
				else
				{
					Node* current = new Node;//for add elem
					Node* current1 = head;//for search result elem
					for (int i = 0; i < k - 1; i++) {
						current1 = current1->Next;
					}
					current->data = obj;    
					current->Next = current1->Next;//change next elem 
					current1->Next = current;
					Size++;
				}
		}
	}
	else {
		throw std::out_of_range("out_of_range");
	}
}
template<typename T> T List<T>::at(size_t k) {//get elem by index
	if (this->head != NULL && k >= 0 && k <= this->Size - 1) {
		if (k == 0)
			return this->head->data;
		else
			if (k == this->Size - 1)
				return this->tail->data;
			else
			{
				Node* current = head;
				for (int i = 0; i < k; i++) {
					current = current->Next;
				}
				return current->data;
			}
	}
	else {
		throw std::out_of_range("out_of_range");
	}
}

template<typename T> int List<T>::atCount(size_t k) {//get elem by index
	if (this->head != NULL && k >= 0 && k <= this->Size - 1) {
		if (k == 0)
			return this->head->count;
		else
			if (k == this->Size - 1)
				return this->tail->count;
			else
			{
				Node* current = head;
				for (int i = 0; i < k; i++) {
					current = current->Next;
				}
				return current->count;
			}
	}
	else {
		throw std::out_of_range("out_of_range");
	}
}

template<typename T> void List<T>::swap(size_t index_one, size_t index_two)
{
	T temp_info = this->at(index_one);
	int temp_count = this->atCount(index_one);
	this->set_with_count(index_one, this->at(index_two), this->atCount(index_two));
	this->set_with_count(index_two, temp_info, temp_count);
}
template<typename T> void List<T>::remove(int k) { // delete by index
	if (head != NULL && k >= 0 && k <= Size - 1) {
		if (k == 0) this->pop_front();
		else
			if (k == this->Size - 1) this->pop_back();
			else
				if (k != 0) {
					Node* current = head;
					for (int i = 0; i < k - 1; i++) {//go to before elem
						current = current->Next;
					}

					Node* current1 = current->Next;
					current->Next = current->Next->Next;
					delete current1;
					Size--;
				}
	}
	else {
		throw std::out_of_range("out_of_range");
	}
}
template<typename T> size_t List<T>::get_size() { // get list size
	return Size;
}
template<typename T> void List<T>::print_to_console() { //print elems to console without delimetr
	if (this->head != NULL) {
		Node* current = head;
		for (int i = 0; i < Size; i++) {
			cout << current->data;
			current = current->Next;
		}
	}
}

template<typename T> void List<T>::print_to_console_with_code() {//print elems to console with delimetr
	if (this->head != NULL) {
		Node* current = head;
		cout << endl;
		for (int i = 0; i < Size; i++) {
			cout <<"|"<< current->data << " - ";
			current->code->print_to_console();
			cout << endl;
			current = current->Next;
		}
	}
}
template<typename T> void List<T>::clear() { // clear list
	if (head != NULL) {
		Node* current = head;
		while (head != NULL) {
			current = current->Next;
			delete head;
			head = current;
		}
		Size = 0;
	}
}
template<typename T> void List<T>::set(size_t k, T obj) { // change elem at index
	if (this->head != NULL && this->get_size() >= k && k >= 0) {
		Node* current = head;
		for (int i = 0; i < k; i++) {
			current = current->Next;
		}
		current->data = obj;
	}
	else {
		throw std::out_of_range("out_of_range");
	}
}

template<typename T> void List<T>::set_with_count(size_t k, T obj, int count) {// change elem at index
	if (this->head != NULL && this->get_size() >= k && k >= 0) {
		Node* current = head;
		for (int i = 0; i < k; i++) {
			current = current->Next;
		}
		current->data = obj;
		current->count = count;
	}
	else {
		throw std::out_of_range("out_of_range");
	}
}

template<typename T> bool List<T>::isEmpty() { // check empty
	return (bool)(head);
}
template<typename T> void List<T>::reverse() { // reverse list
	int Counter = Size;
	Node* HeadCur = NULL;
	Node* TailCur = NULL;
	for (int j = 0; j < Size; j++) {
		if (HeadCur != NULL) {
			if (head != NULL && head->Next == NULL) {
				TailCur->Next = head;
				TailCur = head;
				head = NULL;
			}
			else {
				Node* cur = head;
				for (int i = 0; i < Counter - 2; i++)
					cur = cur->Next;
				TailCur->Next = cur->Next;
				TailCur = cur->Next;
				cur->Next = NULL;
				tail = cur;
				Counter--;
			}
		}
		else {
			HeadCur = tail;
			TailCur = tail;
			Node* cur = head;
			for (int i = 0; i < Size - 2; i++)
				cur = cur->Next;
			tail = cur;
			tail->Next = NULL;
			Counter--;
		}
	}
	head = HeadCur;
	tail = TailCur;
}

template<typename T> void List<T>::CreateCodes(Node* top, int count) {
	this->iterator(top);
	int sum = 0;
	int temp_count = 0;
	while (this->HasNext() && temp_count < count)
	{
		sum += this->cur->count;
		this->Next();
		temp_count++;
	}
	this->iterator(top);
	if (temp_count > 1) {
		int half = sum / 2;
		int halfSum = 0;
		int halfcount = 0;
		while (halfSum < half)
		{
			this->cur->code->push_back(0);
			halfSum += this->cur->count;
			this->Next();
			halfcount++;
		}
		if (halfcount > 1) {
			this->iterator(top);
			CreateCodes(cur, halfcount);
		}
		temp_count = halfcount;
		while (halfcount < count)
		{
			this->cur->code->push_back(1);
			halfSum += this->cur->count;
			this->Next();
			halfcount++;
		}
		if (halfcount - temp_count > 1) {
			this->iterator(top);
			for (int i = 0; i < temp_count; i++)
			{
				this->Next();
			}
			CreateCodes(cur, halfcount - temp_count);
		}
	}
	else if (temp_count == 1) {
		if (this->cur != NULL) {
				this->cur->code = new List<bool>();
			this->cur->code->push_back(0);
		}
	}

}


List<bool>* List<bool>::getCode()
{
	return cur->code;
}

template<typename T> T List<T>::getData() //get data of list
{
	if (cur != nullptr) return this->cur->data;
	else return NULL;
}

template<typename T> void List<T>::qsortRecursive(Node* arr, int size,int left_border) { //sort list
	if (arr == nullptr)
	{
		return;
	}
	this->iterator(arr);
	//indexes of head and back of array
	int i =  left_border;
	int j = size - 1;

	//central elem

	int mid = this->atCount(size/2);
	//divide array
	do {
		//go through elems, found elems which should be remove to another part
		//in left part skip elems which less than middle
		while (this->atCount(i) < mid) {
			i++;
		}
		//in right part skip elems which higher than middle
		while (this->atCount(j) > mid) {
			j--;
		}
		//swap elems 
		if (i <= j) {
			swap(i, j);
			i++;
			j--;
		}
	} while (i <= j);


	//reqursive
	if (j > 0) {
		qsortRecursive(arr, j + 1,left_border);
	}
	if (i < size) {
		qsortRecursive(arr, size - i,left_border);
	}
}
