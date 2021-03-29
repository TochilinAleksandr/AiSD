#include "ShenonList.h"

void ShenonList::input()
{
	char s = 1;
	for (s = getchar(); s != '\n'; s = getchar())
	{
		word->push_back(s);
	}
	FindSymbols();
	ListSort();
	symbols->CreateCodes(symbols->getHead(), symbols->get_size());
	coding();
	decoding();
}
void ShenonList::FindSymbols()
{
	if (word->get_size() != 0) {
		int CountMass[256] = { 0 };
		word->iterator(word->getHead());
		while (word->HasNext())
		{
			CountMass[word->Next()->data]++;
		}
		for (int i = 0; i < 256; i++)
		{
			if (CountMass[i] > 0) {
				symbols->push_with_count(i, CountMass[i]);
			}
		}
	}
}
void ShenonList::ListSort()
{
	symbols->qsortRecursive(symbols->getHead(), symbols->get_size(), 0);
	symbols->reverse();
}


void ShenonList::coding()
{
	List<bool>* temp;
	this->word->iterator(this->word->getHead());
	this->symbols->iterator(this->symbols->getHead());
	while (this->word->HasNext())
	{
		while (this->symbols->getData() != this->word->getData())
		{
			this->symbols->Next();
		}
		temp = this->symbols->getCode();
		temp->iterator(temp->getHead());
		while (temp->HasNext())
		{
			this->encodedWord->push_back(temp->Next()->data);
		}
		this->symbols->iterator(this->symbols->getHead());
		this->word->Next();
	}
}

void ShenonList::decoding()
{
	List<bool>* temp;
	int index = 0;
	int match_index = 0;
	this->encodedWord->iterator(this->encodedWord->getHead());
	this->symbols->iterator(this->symbols->getHead());
	while (match_index != this->encodedWord->get_size())
	{
		temp = this->symbols->getCode();
		temp->iterator(temp->getHead());
		bool flag = false;
		while (temp->HasNext() && this->encodedWord->HasNext())
		{
			if (this->encodedWord->getData() == temp->getData())
				flag = true;
			else
			{
				flag = false;
				break;
			}
			temp->Next();
			this->encodedWord->Next();
			index++;
		}
		if (flag == true)
		{
			this->decodedWord->push_back(this->symbols->getData());
			match_index = index;
			this->symbols->iterator(this->symbols->getHead());
		}
		else {
			index = match_index;
			if (match_index != this->encodedWord->get_size()) {
				this->encodedWord->iterator(this->encodedWord->getHead());
				for (int i = 0; i < match_index; i++)
					this->encodedWord->Next();

			}
			this->symbols->Next();
			if (this->symbols->HasNext() == false)
			{
				this->symbols->iterator(this->symbols->getHead());
			}
		}
	}
}

void ShenonList::print()
{
	cout << "Entered word - ";
	this->word->print_to_console();
	cout << endl;
	cout << "Table of codes";
	this->symbols->print_to_console_with_code();
	cout << endl;
	cout << "Encoded word - ";
	this->encodedWord->print_to_console();
	cout << endl;
	cout << "Decoded word - ";
	this->decodedWord->print_to_console();
	cout << endl;
	float compression_ratio;
	compression_ratio = (this->decodedWord->get_size() * 8.) / (this->encodedWord->get_size() * 1.);
	cout << "compression ratio is equal " << compression_ratio;
}

void ShenonList::setWord(List<char>* word)
{
	this->word = word;
}

List<char>* ShenonList::getSymbols()
{
	return this->symbols;
}
void ShenonList::setSymbols(List<char>* symbols)
{
	this->symbols = symbols;
}

List<bool>* ShenonList::get_encodedWord()
{
	return this->encodedWord;
}

List<char>* ShenonList::get_decodedWord()
{
	return this->decodedWord;
}

