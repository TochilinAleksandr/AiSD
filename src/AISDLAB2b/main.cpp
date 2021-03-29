#include "ShenonList.h"


int main()
{
	List<char>* word;
	word = new List<char>();
	word->push_back('x');
	word->push_back('x');
	word->push_back('z');
	word->push_back('x');
	word->push_back('5');
	word->push_back('5');
	word->push_back('5');
	word->push_back('5');
	ShenonList string;
	string.setWord(word);
	string.FindSymbols();
	string.ListSort();
	List<char>* symbols;
	symbols = new List<char>();
	symbols = string.getSymbols();
	symbols->CreateCodes(symbols->getHead(), symbols->get_size());
	string.setSymbols(symbols);
	string.coding();
	List<bool>* encoded_word;
	encoded_word = new List<bool>();
	encoded_word = string.get_encodedWord();
	
	
	
	ShenonList list;
	list.input();
	List<char> cfhar;
	cfhar.push_back('a');
	list.print();
}