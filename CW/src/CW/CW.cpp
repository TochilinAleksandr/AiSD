#include <iostream>
#include "Calculator.h"
#include <string>
#include <cmath>

int main()
{
	std::cout << "Input expression:" << std::endl;
	std::string expression;
	std::cin >> expression;
	Calculator calc = Calculator(expression);
	try {
		std::cout << "Expression in prefix form:" << std::endl;
		std::cout << calc.toPrefixForm() << std::endl;
		std::cout << "Result of exression:" << std::endl;
		std::cout << calc.calculatePrefix() << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}