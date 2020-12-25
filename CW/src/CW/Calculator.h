#pragma once
#include <stdexcept>
#include <string>
#include <iostream>
#include <cmath>
#include "Stack.h"

class Calculator
{
private:
	std::string sourceString;
	std::string* prefixForm;
	std::string* tokenizedArray = new std::string[1000]();
	int arrLength = 0;
	int prefixLength = 0;
	bool isInPrefix = false;

	bool isBinary(char ch);

	bool checkCurrent(std::string str);

	bool isOperand(std::string str);

	int getPriority(std::string str);

	std::string* reverseStringArray(std::string* arr, int size);

	std::string* toPrefixReserved();

	void tokenize();

	void processStack(Stack* stack);

	double doBinarOperator(double value1, double value2, std::string oper);

	double doUnarOperator(double value, std::string oper);

	bool isNumber(std::string str);

	bool isUnarOperator(std::string str);

	double toDouble(std::string strVal);

public:
	Calculator(std::string inputExpression);

	std::string toPrefixForm();

	double calculatePrefix();
};

