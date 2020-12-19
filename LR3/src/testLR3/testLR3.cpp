#include <string>
#include "pch.h"
#include "CppUnitTest.h"
#include "../LR3/Heap.h"
#include "../LR3/Stack.h"
#include "../LR3/Iterator.h"
#include "../LR3/Heap.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace testLR3
{
	TEST_CLASS(testLR3)
	{
	private:
		Heap heap = Heap();
	public:
		TEST_METHOD_INITIALIZE(init)
		{
			heap.insert(5);
			heap.insert(15);
			heap.insert(34);
			heap.insert(77);
			heap.insert(100);
			heap.insert(50);
			heap.insert(1);
			heap.insert(75);
			heap.insert(350);
		}
		TEST_METHOD(TestMethod1)
		{
            std::string temp = heap.getHeapString();
            char tab2[1024];
            strcpy_s(tab2, temp.c_str());
            Assert::AreEqual("350 100 50 77 34 15 1 5 75", tab2);
		}
		TEST_METHOD(TestMethod2)
		{
			heap.remove(350);
			heap.remove(1);
			std::string temp = heap.getHeapString();
			char tab2[1024];
			strcpy_s(tab2, temp.c_str());
			Assert::AreEqual("100 77 50 75 34 15 5", tab2);
		}
		TEST_METHOD(TestMethod3)
		{
			Assert::AreEqual(true, heap.contains(350));
			Assert::AreEqual(true, heap.contains(77));
			Assert::AreEqual(true, heap.contains(50));
			Assert::AreEqual(false, heap.contains(-10));
		}
		TEST_METHOD(TestMethod4)
		{
			Iterator* dft_iterator = heap.create_dft_iterator();
			dft_iterator->next();
			Assert::AreEqual(350, dft_iterator->getCur());
			dft_iterator->next();
			dft_iterator->next();
			dft_iterator->next();
			dft_iterator->next();
			dft_iterator->next();
			Assert::AreEqual(34, dft_iterator->getCur());
			dft_iterator->next();
			dft_iterator->next();
			dft_iterator->next();
			Assert::AreEqual(false, dft_iterator->hasNext());
		}
		TEST_METHOD(TestMethod5)
		{
			Iterator* bft_iterator = heap.create_bft_iterator();
			bft_iterator->next();
			Assert::AreEqual(350, bft_iterator->getCur());
			bft_iterator->next();
			bft_iterator->next();
			bft_iterator->next();
			bft_iterator->next();
			bft_iterator->next();
			Assert::AreEqual(15, bft_iterator->getCur());
			bft_iterator->next();
			bft_iterator->next();
			bft_iterator->next();
			Assert::AreEqual(false, bft_iterator->hasNext());
		}
	};
}
