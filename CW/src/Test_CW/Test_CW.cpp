#include "pch.h"
#include "CppUnitTest.h"
#include "../CW/Calculator.h"
#include "../CW/Calculator.cpp"
#include "../CW/Stack.h"
#include <cmath>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestCW
{
	TEST_CLASS(TestCW)
	{
	public:
		
		TEST_METHOD(CheckWrongInput1)
		{
			Calculator calc = Calculator("-e1*sqrt(-12+20)+15*(64.5-21)^2");
			try {
				calc.toPrefixForm();
				Assert::Fail();
			}
			catch (std::exception& e) {}
		}
		TEST_METHOD(CheckWrongInput2)
		{
			Calculator calc = Calculator("*e*sqrt(-12+20)+15*(64.5-21)^2");
			try {
				calc.toPrefixForm();
				Assert::Fail();
			}
			catch (std::exception& e) {}
		}
		TEST_METHOD(CheckWrongInput3)
		{
			Calculator calc = Calculator("e*lm(-12+20)+15*(64.5-21)^2");
			try {
				calc.toPrefixForm();
				Assert::Fail();
			}
			catch (std::exception& e) {}
		}
		TEST_METHOD(CheckWrongInput4)
		{
			Calculator calc = Calculator("e*ln(-12+20)+15*(64.5-21)^2__");
			try {
				calc.toPrefixForm();
				Assert::Fail();
			}
			catch (std::exception& e) {}
		}
		TEST_METHOD(CheckWrongInput5)
		{
			Calculator calc = Calculator("e*ln(-12+20)+15*(6.4.5-21)^2");
			try {
				calc.toPrefixForm();
				Assert::Fail();
			}
			catch (std::exception& e) {}
		}
		TEST_METHOD(CheckWrongInput6)
		{
			Calculator calc = Calculator("ln)75.11*ln(22+ln(11)))");
			try {
				calc.toPrefixForm();
				Assert::Fail();
			}
			catch (std::exception& e) {}
		}
		TEST_METHOD(CheckWrongInput7)
		{
			Calculator calc = Calculator(".3+3");
			try {
				calc.toPrefixForm();
				Assert::Fail();
			}
			catch (std::exception& e) {}
		}
		TEST_METHOD(CheckPrefixForm1)
		{
			Calculator calc = Calculator("ln(75.11*ln(22+ln(11)))");
			std::string temp = calc.toPrefixForm();
			char tab[1024];
			strcpy_s(tab, temp.c_str());
			Assert::AreEqual("ln * 75.11 ln + 22 ln 11", tab);
		}
		TEST_METHOD(CheckPrefixForm2)
		{
			Calculator calc = Calculator("(((5+3)/4)*6)");
			std::string temp = calc.toPrefixForm();
			char tab[1024];
			strcpy_s(tab, temp.c_str());
			Assert::AreEqual("* / + 5 3 4 6", tab);
		}
		TEST_METHOD(CheckPrefixForm3)
		{
			Calculator calc = Calculator("-e*sqrt(-12+20)+15*(64.5-21)^2");
			std::string temp = calc.toPrefixForm();
			char tab[1024];
			strcpy_s(tab, temp.c_str());
			Assert::AreEqual("+ * -- e sqrt + -- 12 20 * 15 ^ - 64.5 21 2", tab);
		}
		TEST_METHOD(CheckPrefixForm4)
		{
			Calculator calc = Calculator("ln(sqrt(cbrt(log(5))))");
			std::string temp = calc.toPrefixForm();
			char tab[1024];
			strcpy_s(tab, temp.c_str());
			Assert::AreEqual("ln sqrt cbrt log 5", tab);
		}
		TEST_METHOD(CheckResult1)
		{
			Calculator calc = Calculator("ln(75.11*ln(22+ln(11)))");
			calc.toPrefixForm();
			Assert::AreEqual(ceil(5.48038), ceil(calc.calculatePrefix()));
		}
		TEST_METHOD(CheckResult2)
		{
			Calculator calc = Calculator("(((5+3)/4)*6)");
			calc.toPrefixForm();
			Assert::AreEqual(12.0, calc.calculatePrefix());
		}
		TEST_METHOD(CheckResult3)
		{
			Calculator calc = Calculator("-e*sqrt(-12+20)+15*(64.5-21)^2");
			calc.toPrefixForm();
			Assert::AreEqual(ceil(28376.1), ceil(calc.calculatePrefix()));
		}
		TEST_METHOD(CheckResult4)
		{
			Calculator calc = Calculator("ln(sqrt(cbrt(log(5))))");
			calc.toPrefixForm();
			Assert::AreEqual(-0.059692, calc.calculatePrefix());
		}
	};
}