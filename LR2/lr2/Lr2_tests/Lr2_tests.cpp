#include "pch.h"
#include "CppUnitTest.h"
#include "../lr2/sortings.h"
#include "../lr2/sortings.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lr2tests
{
	TEST_CLASS(Lr2tests)
	{
	public:		
		TEST_METHOD(TestBinarySearch)
		{
			int numbers[6]{-1, 5, 12, 33, 64, 77};
			Assert::AreEqual(BinarySearch(numbers, 6, -1), 0);
			Assert::AreEqual(BinarySearch(numbers, 6, 5), 1);
			Assert::AreEqual(BinarySearch(numbers, 6, 12), 2);
			Assert::AreEqual(BinarySearch(numbers, 6, 33), 3);
			Assert::AreEqual(BinarySearch(numbers, 6, 64), 4);
			Assert::AreEqual(BinarySearch(numbers, 6, 77), 5);
		}
		TEST_METHOD(TestQuickSort)
		{
			int numbers[6]{ 77, -1, 64, 33, 12, 5 };
			QuickSort(numbers, 0, 5);
			Assert::AreEqual(numbers[0], -1);
			Assert::AreEqual(numbers[1], 5);
			Assert::AreEqual(numbers[2], 12);
			Assert::AreEqual(numbers[3], 33);
			Assert::AreEqual(numbers[4], 64);
			Assert::AreEqual(numbers[5], 77);
		}
		TEST_METHOD(TestBubbleSort)
		{
			int numbers[6]{ 77, -1, 64, 33, 12, 5 };
			BubbleSort(numbers, 6);
			Assert::AreEqual(numbers[0], -1);
			Assert::AreEqual(numbers[1], 5);
			Assert::AreEqual(numbers[2], 12);
			Assert::AreEqual(numbers[3], 33);
			Assert::AreEqual(numbers[4], 64);
			Assert::AreEqual(numbers[5], 77);
		}
		TEST_METHOD(TestBogoSort)
		{
			int numbers[6]{ 77, -1, 64, 33, 12, 5 };
			BogoSort(numbers, 6);
			Assert::AreEqual(numbers[0], -1);
			Assert::AreEqual(numbers[1], 5);
			Assert::AreEqual(numbers[2], 12);
			Assert::AreEqual(numbers[3], 33);
			Assert::AreEqual(numbers[4], 64);
			Assert::AreEqual(numbers[5], 77);
		}
		TEST_METHOD(TestCountingSort)
		{
			char chars[6]{ 'm', 'c', 'a', 'f', 'b', 'd' };
			CountingSort(chars, 6);
			Assert::AreEqual(chars[0], 'a');
			Assert::AreEqual(chars[1], 'b');
			Assert::AreEqual(chars[2], 'c');
			Assert::AreEqual(chars[3], 'd');
			Assert::AreEqual(chars[4], 'f');
			Assert::AreEqual(chars[5], 'm');
		}
	};
}
