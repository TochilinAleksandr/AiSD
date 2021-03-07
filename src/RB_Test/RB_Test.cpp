#pragma once

#include "pch.h"
#include "CppUnitTest.h"
#include <string>
#include "..//RB/RB.cpp"
#include "..//RB/NormalList.h"



using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RBTest
{
	TEST_CLASS(RBTest)
	{
	private:
		Map<int, string> tree;
		List<int>* myList = new List<int>;
		List<string>* myList1 = new List<string>;
	public:

		TEST_METHOD_INITIALIZE(init)
		{
			tree.insert(30, "a");
			tree.insert(40, "a");
			tree.insert(15, "daada");
			tree.insert(10, "daada");
			tree.insert(20, "daada");
			tree.insert(5, "daada");
			tree.insert(3, "daada");

		}
		TEST_METHOD(test_insert)
		{
			tree.insert(2, "oleg");
			tree.insert(21, "ne sdast labu");
			Assert::AreEqual(tree.getRoot()->left->left->left->key, 2);
			Assert::AreEqual(tree.getRoot()->right->left->right->key, 21);
		}
		TEST_METHOD(test_remove1)
		{
			tree.remove(15);
			Assert::AreEqual(tree.getRoot()->left->key, 5);
		}
		TEST_METHOD(test_remove2)
		{
			tree.remove(20);
			Assert::AreEqual(tree.getRoot()->left->key, 5);
		}
		TEST_METHOD(find)
		{
			Assert::AreEqual(tree.find(40)->data, (string)"a");

		}
		TEST_METHOD(test_print_to_console)
		{
			tree.print(tree.getRoot(), 0);
		}
		TEST_METHOD(test_get_keys)
		{
			
			myList = tree.getListKey(tree.getRoot(), myList);
			Assert::AreEqual(myList->at(0), 3);
			Assert::AreEqual(myList->at(1), 10);
		}
		TEST_METHOD(test_get_values)
		{
			List<string>* myList1 = new List<string>;
			myList1 = tree.getListData(tree.getRoot(), myList1);
			Assert::AreEqual(myList1->at(0), (string)"daada");
			Assert::AreEqual(myList1->at(1), (string)"daada");
		}
	};
}
