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

template<typename T> void List<T>::push_back(T obj) { // добавление в конец списка bc
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
template<typename T> void List<T>::push_front(T obj) { // добавление в начало списка bc
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
template<typename T> void List<T>::pop_back() { // удаление последнего элемента bc
	if (head != NULL) {
		Node* current = head;
		while (current->Next != tail)//то есть ищем предпоследний
			current = current->Next;
		delete tail;
		tail = current;
		tail->Next = NULL;
		Size--;
	}
	else throw std::out_of_range("out_of_range");
}
template<typename T> void List<T>::pop_front() { // удаление первого элемента bc-+
	if (head != NULL) {
		Node* current = head;
		head = head->Next;
		delete current;
		Size--;
	}
	else throw std::out_of_range("out_of_range");
}
template<typename T> void List<T>::insert(T obj, size_t k) {// добавление элемента по индексу (вставка перед элементом, который был ранее доступен по этому индексу) bc
	if (k >= 0 && this->Size > k) {
		if (this->head != NULL) {
			if (k == 0)
				this->push_front(obj);
			else
				if (k == this->Size - 1)
					this->push_back(obj);
				else
				{
					Node* current = new Node;//для добавления элемента
					Node* current1 = head;//для поиска итого элемента
					for (int i = 0; i < k - 1; i++) {
						current1 = current1->Next;
					}
					current->data = obj;
					current->Next = current1->Next;//переуказывает на след элемент
					current1->Next = current;
					Size++;
				}
		}
	}
	else {
		throw std::out_of_range("out_of_range");
	}
}
template<typename T> T List<T>::at(size_t k) {// получение элемента по индексу bc
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

template<typename T> int List<T>::atCount(size_t k) {// получение элемента по индексу bc
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
template<typename T> void List<T>::remove(int k) { // удаление элемента по индексу bc
	if (head != NULL && k >= 0 && k <= Size - 1) {
		if (k == 0) this->pop_front();
		else
			if (k == this->Size - 1) this->pop_back();
			else
				if (k != 0) {
					Node* current = head;
					for (int i = 0; i < k - 1; i++) {//переходим на предэлемент
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
template<typename T> size_t List<T>::get_size() { // получение размера списка bc
	return Size;
}
template<typename T> void List<T>::print_to_console() { // вывод элементов списка в консоль через разделитель, не использовать at bc
	if (this->head != NULL) {
		Node* current = head;
		for (int i = 0; i < Size; i++) {
			cout << current->data;
			current = current->Next;
		}
	}
}

template<typename T> void List<T>::print_to_console_with_code() { // вывод элементов списка в консоль через разделитель, не использовать at bc
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
template<typename T> void List<T>::clear() { // удаление всех элементов списка
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
template<typename T> void List<T>::set(size_t k, T obj)  // замена элемента по индексу на передаваемый элемент 
{
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

template<typename T> void List<T>::set_with_count(size_t k, T obj, int count)  // замена элемента по индексу на передаваемый элемент 
{
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

template<typename T> bool List<T>::isEmpty() { // проверка на пустоту списка bc
	return (bool)(head);
}
template<typename T> void List<T>::reverse() { // меняет порядок элементов в списке
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

template<typename T> T List<T>::getData()
{
	if (cur != nullptr) return this->cur->data;
	else return NULL;
}

template<typename T> void List<T>::qsortRecursive(Node* arr, int size,int left_border) {
	if (arr == nullptr)
	{
		return;
	}
	this->iterator(arr);
	//Указатели в начало и в конец массива
	int i =  left_border;
	int j = size - 1;

	//Центральный элемент массива

	int mid = this->atCount(size/2);
	//Делим массив
	do {
		//Пробегаем элементы, ищем те, которые нужно перекинуть в другую часть
		//В левой части массива пропускаем(оставляем на месте) элементы, которые меньше центрального
		while (this->atCount(i) < mid) {
			i++;
		}
		//В правой части пропускаем элементы, которые больше центрального
		while (this->atCount(j) > mid) {
			j--;
		}

		//Меняем элементы местами
		if (i <= j) {
			swap(i, j);
			i++;
			j--;
		}
	} while (i <= j);


	//Рекурсивные вызовы, если осталось, что сортировать
	if (j > 0) {
		//"Левый кусок"
		qsortRecursive(arr, j + 1,left_border);
	}
	if (i < size) {
		//"Првый кусок"
		qsortRecursive(arr, size - i,left_border);
	}
}
