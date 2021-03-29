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
	void push_back(T obj); // add elem to back
	void push_front(T obj); // add elem to front
	void pop_back(); // del elem from back
	void pop_front(); // del elem from head
	void insert(T obj, size_t k); // add elem by index, insert before elem with this index
	T at(size_t k); // get elem by index
	int atCount(size_t k); // geting count of element
	void swap(size_t index_one, size_t index_two);//swap of 2 elements
	void remove(int k); // delete elem by index
	size_t get_size(); // get size
	void print_to_console(); // output list
	void print_to_console_with_code();
	void clear();  // clear list
	void set(size_t k, T obj);  // замена элемента по индексу на передаваемый элемент //change elem at index
	void set_with_count(size_t k, T obj, int count);
	bool isEmpty(); // has list any elements
	void reverse();  // reverse list
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