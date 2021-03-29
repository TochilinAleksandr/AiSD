#include<iostream>

using namespace std;
template<class T>
class List
{
private:
	class Node {
	public:
		Node(T data = T(), Node* Next = NULL) {
			this->data = data;
			this->Next = Next;
			this->code = NULL;
			this->count = 0;
		}
		Node(T data, int count) :data(data), Next(NULL), code(new List<bool>()), count(count) {};
		Node* Next;
		T data;
		unsigned short int count;
		List<bool>* code;
	};

	Node* head;
	Node* tail;
	Node* cur;
	int Size;
public:



	void iterator(Node* curent);//create iterator
	bool HasNext();//we check have next element
	void push_with_count(T obj, int count);//adding in the end with count
	void push_back(T obj); // добавление в конец списка bc
	void push_front(T obj); // добавление в начало списка bc
	void pop_back(); // удаление последнего элемента bc
	void pop_front(); // удаление первого элемента bc-+
	void insert(T obj, size_t k); // добавление элемента по индексу (вставка перед элементом, который был ранее доступен по этому индексу) bc
	T at(size_t k); // получение элемента по индексу bc
	int atCount(size_t k);//geting count of element
	void swap(size_t index_one, size_t index_two);//swap of 2 elements
	void remove(int k); // удаление элемента по индексу bc
	size_t get_size(); // получение размера списка bc
	void print_to_console(); // вывод элементов списка в консоль через разделитель, не использовать at bc
	void print_to_console_with_code();
	void clear();  // удаление всех элементов списка
	void set(size_t k, T obj);  // замена элемента по индексу на передаваемый элемент 
	void set_with_count(size_t k, T obj, int count);
	bool isEmpty(); // проверка на пустоту списка bc
	void reverse();  // меняет порядок элементов в списке
	List(Node* head = NULL, Node* tail = NULL, int Size = 0) :head(head), tail(tail), Size(Size) {}
	~List() {
		if (head != NULL) {
			this->clear();
		}
	};
	Node* getHead()//geting head
	{
		return this->head;
	}

	Node* Next()//geting current element from iterator, move to next element
	{
		Node* temp;
		temp = cur;
		cur = cur->Next;
		return temp;
	}
	List<bool>* getCode()//geting binary code of elements
	{
		return cur->code;
	}
	void CreateCodes(Node* top, int count);//creating binary codes of symbols
	T getData();//geting data of elements
	void qsortRecursive(Node* arr, int size, int left_border); //quick sort
};