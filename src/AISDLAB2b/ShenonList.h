#include "List.cpp"


class ShenonList {
private:
	List<char>* word;
	List<char>* symbols;
	List<bool>* encodedWord;
	List<char>* decodedWord;
public:
	void input(); //input string,that need to encode
	void FindSymbols();//finding all symbols in out string
	void ListSort();//sort symbols in descending order
	void coding();//encoding our string
	void decoding();//decoding our string
	void print(); //print all info 
	void setWord(List<char>* word);
	List<char>* getSymbols();
	void setSymbols(List<char>* symbols);
	List<bool>* get_encodedWord();
	List<char>* get_decodedWord();
	ShenonList()
	{
		this->word = new List<char>();
		this->symbols = new List<char>();
		this->encodedWord = new List<bool>();
		this->decodedWord = new List<char>();
	}
	~ShenonList()
	{
		this->word->clear();
		this->symbols->clear();
		this->encodedWord->clear();
		this->decodedWord->clear();
	}
};

