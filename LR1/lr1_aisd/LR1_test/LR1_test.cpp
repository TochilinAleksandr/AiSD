#include "pch.h"
#include "CppUnitTest.h"
#include "../lr1_aisd/list.h"
#include "../lr1_aisd/list.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LR1test
{
	TEST_CLASS(LR1test)
	{
	private:
		List list = List();
	public:
		TEST_METHOD_INITIALIZE(init)
		{
			list.push_back(5);
			list.push_back(4);
			list.push_back(3);
			list.push_back(2);
			list.push_back(1);
		}
		TEST_METHOD(testAt)
		{
			Assert::AreEqual(list.at(0), 5);
			Assert::AreEqual(list.at(1), 4);
			Assert::AreEqual(list.at(2), 3);
			Assert::AreEqual(list.at(3), 2);
			Assert::AreEqual(list.at(4), 1);
		}
		TEST_METHOD(testPushBack)
		{
			list.push_back(0);
			Assert::AreEqual(list.at(5), 0);
		}
		TEST_METHOD(testPushFront)
		{
			list.push_front(6);
			Assert::AreEqual(list.at(0), 6);
		}
		TEST_METHOD(testGetSize)
		{
			Assert::AreEqual(list.get_size(), (size_t)5);
			list.pop_back();
			Assert::AreEqual(list.get_size(), (size_t)4);
			List list2 = List();
			Assert::AreEqual(list2.get_size(), (size_t)0);
		}
		TEST_METHOD(testPopBack)
		{
			list.pop_back();
			Assert::AreEqual(list.get_size(), (size_t)4);
			Assert::AreEqual(list.at(3), 2);
		}
		TEST_METHOD(testPopFront)
		{
			list.pop_front();
			Assert::AreEqual(list.get_size(), (size_t)4);
			Assert::AreEqual(list.at(0), 4);
		}
		TEST_METHOD(testInsert)
		{
			list.insert(222, 3);
			Assert::AreEqual(list.at(3), 222);
			Assert::AreEqual(list.at(4), 2);
			Assert::AreEqual(list.get_size(), (size_t)6);
		}
		TEST_METHOD(testRemove)
		{
			list.remove(3);
			Assert::AreEqual(list.at(3), 1);
			Assert::AreEqual(list.get_size(), (size_t)4);
		}
		TEST_METHOD(testClear)
		{
			list.clear();
			Assert::IsTrue(list.isEmpty());
			Assert::AreEqual(list.get_size(), (size_t)0);
		}
		TEST_METHOD(testIsEmpty)
		{
			Assert::IsFalse(list.isEmpty());
			list.clear();
			Assert::IsTrue(list.isEmpty());
		}
		TEST_METHOD(testPushFrontList)
		{
			List list2;
			list2.push_front(10);
			list2.push_back(20);
			list.push_front(list2);
			Assert::AreEqual(list.at(0), 10);
			Assert::AreEqual(list.at(2), 5);
		}
	};
}
