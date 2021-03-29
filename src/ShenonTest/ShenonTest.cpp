#include "pch.h"
#include "CppUnitTest.h"
#include "../AISDLAB2b/ShenonList.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ShenonTest
{
	TEST_CLASS(ShenonTest)
	{
	public:

		TEST_METHOD(CodingTest)
		{
			List<char>* word;
			word = new List<char>();
			word->push_back('z');
			word->push_back('x');
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
			Assert::AreEqual(encoded_word->at(1), false);
			Assert::AreEqual(encoded_word->at(0), true);
		}


		TEST_METHOD(CodingTest2)
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
			Assert::AreEqual(encoded_word->at(0), true);
			Assert::AreEqual(encoded_word->at(1), false);
			Assert::AreEqual(encoded_word->at(2), true);
			Assert::AreEqual(encoded_word->at(3), false);
			Assert::AreEqual(encoded_word->at(4), true);
			Assert::AreEqual(encoded_word->at(5), true);
			Assert::AreEqual(encoded_word->at(6), true);
			Assert::AreEqual(encoded_word->at(7), false);
			Assert::AreEqual(encoded_word->at(8), false);
			Assert::AreEqual(encoded_word->at(9), false);
			Assert::AreEqual(encoded_word->at(10), false);
			Assert::AreEqual(encoded_word->at(11), false);
		}

		TEST_METHOD(CodingTest3)
		{
			List<char>* word;
			word = new List<char>();
			word->push_back('x');
			word->push_back('x');
			word->push_back('x');
			word->push_back('x');
			word->push_back('x');
			word->push_back('x');
			word->push_back('x');
			word->push_back('x');
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
			Assert::AreEqual(encoded_word->at(0), false);
			Assert::AreEqual(encoded_word->at(1), false);
			Assert::AreEqual(encoded_word->at(2), false);
			Assert::AreEqual(encoded_word->at(3), false);
			Assert::AreEqual(encoded_word->at(4), false);
			Assert::AreEqual(encoded_word->at(5), false);
			Assert::AreEqual(encoded_word->at(6), false);
			Assert::AreEqual(encoded_word->at(7), false);
		}

		TEST_METHOD(CodingTest4)
		{
			List<char>* word;
			word = new List<char>();
			word->push_back('x');
			word->push_back('z');
			word->push_back('x');
			word->push_back('z');
			word->push_back('x');
			word->push_back('z');
			word->push_back('x');
			word->push_back('z');
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
			Assert::AreEqual(encoded_word->at(0), false);
			Assert::AreEqual(encoded_word->at(1), true);
			Assert::AreEqual(encoded_word->at(2), false);
			Assert::AreEqual(encoded_word->at(3), true);
			Assert::AreEqual(encoded_word->at(4), false);
			Assert::AreEqual(encoded_word->at(5), true);
			Assert::AreEqual(encoded_word->at(6), false);
			Assert::AreEqual(encoded_word->at(7), true);
		}


		TEST_METHOD(DecodingTest)
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
			string.decoding();
			List<char>* decoded_word;
			decoded_word = new List<char>();
			decoded_word = string.get_decodedWord();
			Assert::AreEqual(decoded_word->at(0), 'x');
			Assert::AreEqual(decoded_word->at(1), 'x');
			Assert::AreEqual(decoded_word->at(2), 'z');
			Assert::AreEqual(decoded_word->at(3), 'x');
			Assert::AreEqual(decoded_word->at(4), '5');
			Assert::AreEqual(decoded_word->at(5), '5');
			Assert::AreEqual(decoded_word->at(6), '5');
			Assert::AreEqual(decoded_word->at(7), '5');
		}

		TEST_METHOD(DecodingTest2)
		{
			List<char>* word;
			word = new List<char>();
			word->push_back('z');
			word->push_back('x');
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
			string.decoding();
			List<char>* decoded_word;
			decoded_word = new List<char>();
			decoded_word = string.get_decodedWord();
			Assert::AreEqual(decoded_word->at(0), 'z');
			Assert::AreEqual(decoded_word->at(1), 'x');
		}

		TEST_METHOD(FindingTest)
		{
			List<char>* word;
			word = new List<char>();
			word->push_back('z');
			word->push_back('x');
			ShenonList string;
			string.setWord(word);
			string.FindSymbols();
			string.ListSort();
			List<char>* symbols;
			symbols = new List<char>();
			symbols = string.getSymbols();
			Assert::AreEqual(symbols->at(0), 'x');
			Assert::AreEqual(symbols->at(1), 'z');
		}

		TEST_METHOD(FindingTest2)
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
			Assert::AreEqual(symbols->at(0), '5');
			Assert::AreEqual(symbols->at(1), 'x');
			Assert::AreEqual(symbols->at(2), 'z');
		}
	};
}
