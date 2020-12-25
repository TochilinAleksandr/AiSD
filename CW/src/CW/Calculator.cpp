#include "Calculator.h"

//define math constans
#define M_PI 3.14159265358979323846   // pi   
#define M_E 2.71828182845904523536 //e

Calculator::Calculator(std::string inputExpression) {
	this->sourceString = inputExpression;
}

//function make infix expression to prefix from 
std::string Calculator::toPrefixForm() {
	// split input expression to array of operands and operators
	this->tokenize();
	/*for (int i = 0; i < arrLength; i++)
	{
		std::cout << this->tokenizedArray[i] << " ";
	}
	std::cout << std::endl;*/
	//convert to reversed prefix form
	std::string* ReversedPrefix = this->toPrefixReserved();
	//reverse array
	prefixForm = this->reverseStringArray(ReversedPrefix, prefixLength);
	//output expression in prefix form
	std::string result = "";
	for (int i = 0; i < prefixLength; i++)
	{
		result += prefixForm[i] + " ";
	}
	result.pop_back();
	this->isInPrefix = true;
	return result;
}

//convert string to double
double Calculator::toDouble(std::string strVal) {
	//check constants if not constant use function stod
	if (strVal == "e") {
		return M_E;
	}
	else if (strVal == "pi") {
		return M_PI;
	}
	else {
		return std::stod(strVal);
	}
}
//function which calculate 
double Calculator::calculatePrefix() {
	if (!isInPrefix) {
		throw std::runtime_error("Equtation not converted!");
	}
	//using stack
	Stack* stack = new Stack();
	//go from and to start of prefix form equtation array
	for (int i = prefixLength - 1; i >= 0; i--) {
		//push to stack and use processStack function
		stack->push(prefixForm[i]);
		processStack(stack);
	}
	//print result
	return toDouble(stack->top());
}

//function to process stack while culculating
void Calculator::processStack(Stack* stack) {
	if (stack->isEmpty() || isNumber(stack->top())) {
		return;
	}
	//if meet unary operator and size of stack higher than 1 and after top elem stack has number do operatorand push to array
	else if (isUnarOperator(stack->top())) {
		if (stack->getSize() > 1) {
			if (isNumber(stack->top(2))) {
				std::string oper = stack->pop();
				double val = doUnarOperator(toDouble(stack->pop()), oper);
				stack->push(std::to_string(val));
			}
		}
	}
	//if met binary operator and size of stack higher than 2 and after top elem stack has two numbers do operator and push to array
	else {
		if (stack->getSize() > 2) {
			if (isNumber(stack->top(2)) && isNumber(stack->top(3))) {
				std::string oper = stack->pop();
				double val1 = toDouble(stack->pop());
				double val2 = toDouble(stack->pop());
				double val = doBinarOperator(val1, val2, oper);
				stack->push(std::to_string(val));
			}
		}
	}
}

//check isBinary operator symbol for tokenize function
bool Calculator::isBinary(char ch) {
	if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
		return true;
	}
	return false;
}

//check inputed operators
bool Calculator::checkCurrent(std::string str) {
	if (std::isalpha(str[0])) {
		if (str == "cos" || str == "sin" || str == "tg" || str == "ctg" ||
			str == "ln" || str == "log" || str == "sqrt" || str == "cbrt" || str == "pi" || str == "e") {
			return true;
		}
		else return false;
	}
	//number should have less than 2 dots and no dot at and
	else if (std::isdigit(str[0]) || str[0] == '-') {
		if (std::count(str.begin(), str.end(), '.') > 1 || str[str.length() - 1] == '.') {
			return false;
		}
		return true;
	}
	else {
		return false;
	}
}

//check if input string operator or operand, single operators make operand
bool Calculator::isOperand(std::string str) {
	if (str == "e" || str == "pi" || str == "cos" || str == "sin" || str == "tg" || str == "ctg" ||
		str == "ln" || str == "log" || str == "sqrt" || str == "cbrt" || str == "--") {
		return true;
	}
	try
	{
		double value = std::stod(str);
		return true;
	}
	catch (std::exception& e)
	{
		return false;
	}
}

//get priority of operands

int Calculator::getPriority(std::string str) {
	if (str == "-" || str == "+") {
		return 1;
	}
	else if (str == "*" || str == "/") {
		return 2;
	}
	else if (str == "^") {
		return 3;
	}
	return 0;
}

//reverse string if also change "(" to ")" and ")" to "("
std::string* Calculator::reverseStringArray(std::string* arr, int size) {
	std::string* result = new std::string[1000]();
	for (int i = size - 1; i >= 0; i--)
	{
		if (arr[i] == ")") {
			result[size - 1 - i] = "(";
		}
		else if (arr[i] == "(") {
			result[size - 1 - i] = ")";
		}
		else {
			result[size - 1 - i] = arr[i];
		}
	}
	return result;
}

//function convert expression to prefix reversed form
std::string* Calculator::toPrefixReserved() {
	Stack operators = Stack();						//stack for operand
	std::string* res = new std::string[1000];       
	int resLength = 0;
	for (int i = arrLength - 1; i >= 0; i--)    //iterate from and to start of tokeanized array
	{
		if (tokenizedArray[i] == ")") {     //if met close bracket push to operators stack 
			operators.push(")");
		}
		else if (isOperand(tokenizedArray[i])) {   //if met elem is operand add to result array
			res[resLength] = tokenizedArray[i];
			resLength++;
		}
		else if (tokenizedArray[i] == "(") {    //if met close bracket pop stack ad add to result while not met open bracket
			while (operators.top() != ")") {
				try {
					res[resLength] = operators.pop();
				}
				catch (const std::runtime_error& error) {
					throw std::runtime_error("No close bracket to open bracket at index: " + std::to_string(i));
				}
				resLength++;
			}
			operators.pop();
			
		}
		else if (!(isOperand(tokenizedArray[i]))) {   //if met operator pop and add operators with higher priority to result array
			while (!operators.isEmpty() && this->getPriority(tokenizedArray[i]) <= this->getPriority(operators.top())) {
				res[resLength] = operators.pop();
				resLength++;
			}
			operators.push(tokenizedArray[i]);   //add met operator to stack
		}
	}

	while (!(operators.isEmpty())) {  //pop all elems from stack and add to result
		res[resLength] = operators.pop();
		resLength++;
		if (res[resLength] == "(") {
			throw std::runtime_error("No open bracket");
		}
	};

	this->prefixLength = resLength;   //change prefix array length
	return res;
}
//split input expression into array operators and operands
void Calculator::tokenize() {
	std::string result = "";
	std::string current = ""; //for current double or operator
	for (int i = 0; i < this->sourceString.length(); i++)
	{	
		//before open bracket can only be operator
		if (this->sourceString[i] == '(') {
			if (isNumber(current)) {
				throw std::runtime_error("No numbers before open bracket: pos" + std::to_string(i - 1));
			}
			if (current.length() > 0) {
				if (checkCurrent(current)) {
					tokenizedArray[arrLength] = current;
					arrLength++;
				}
				else {
					throw std::runtime_error("No such operator or error with number, pos: " + std::to_string(i - current.length()));
				}
			}
			current = "";
			tokenizedArray[arrLength] = "(";
			arrLength++;

		}
		//before close bracket can only be number
		else if (this->sourceString[i] == ')') {
			if (!isNumber(current) && this->sourceString[i - 1] != ')') {
				throw std::runtime_error("Before close bracket can only be number pos: " + std::to_string(i));
			} 
			if (current.length() > 0) {
				tokenizedArray[arrLength] = current;
				arrLength++;
			}
			current = "";
			tokenizedArray[arrLength] = ")";
			arrLength++;
		}
		// before binary operator can only be close bracket or number
		else if (isBinary(this->sourceString[i])) {
			if (!isNumber(current)) {
				if (i != 0) {
					if (this->sourceString[i - 1] == '(' && this->sourceString[i] == '-') {
						tokenizedArray[arrLength] = "--";
						arrLength++;
					}
					else if (this->sourceString[i - 1] == ')') {
						std::string symbStr = "";
						symbStr += this->sourceString[i];
						tokenizedArray[arrLength] = symbStr;
						arrLength++;
					}
					else {
						throw std::runtime_error("Before binary must be number or bracket pos: " + std::to_string(i));
					}
				}
				else {
					if (this->sourceString[i] == '-') {
						tokenizedArray[arrLength] = "--";
						arrLength++;
					}
					else {
						throw std::runtime_error("Before binary must be number or bracket 22pos: " + std::to_string(i));
					}
				}
			}
			else {
				tokenizedArray[arrLength] = current;
				arrLength++;
				current = "";
				std::string symbStr = "";
				symbStr += this->sourceString[i];
				tokenizedArray[arrLength] = symbStr;
				arrLength++;
			}
		}
		else if (this->sourceString[i] == '.')
		{	
			//if met dot prev symbol must be digit
			if (current.length() > 0 && std::isdigit(current[current.length() - 1])) {
				current += '.';
			}
			else {
				throw std::runtime_error("Dot not expexted, pos: " + std::to_string(i));
			}
		}
		//if meet digit current must be zero length or prev elem shoul be digit or dot
		else if (std::isdigit(this->sourceString[i])) {
			if (current.length() == 0 || std::isdigit(current[current.length() - 1]) || current[current.length() - 1] == '.') {
				current += this->sourceString[i];
			}
			else {
				throw std::runtime_error("Digit not expexted, pos: " + std::to_string(i));
			}
		}
		//if meet alpha current must be zero length of prev elem should be alpha 
		else if (std::isalpha(this->sourceString[i]))
		{
			if (current.length() == 0 || std::isalpha(current[current.length() - 1])) {
				current += this->sourceString[i];
			}
			else {
				throw std::runtime_error("Error with symbol: " + std::to_string(i));
			}
		}
		else {
			throw std::runtime_error("Error with symbol: " + std::to_string(i));
		}

	}
	//check last elem
	if (current.length() > 0) {
		if (checkCurrent(current)) {
			tokenizedArray[arrLength] = current;
			arrLength++;
		}
		else {
			throw std::runtime_error("Wrong last elem");
		}
	}
	if (!isNumber(tokenizedArray[arrLength - 1])) {
		if (tokenizedArray[arrLength - 1] != ")") {
			throw std::runtime_error("Last elem must be close bracket or number");
		}
	}
}

//apply binary operator
double Calculator::doBinarOperator(double value1, double value2, std::string oper) {
	if (oper == "+") {
		return value1 + value2;
	}
	else if (oper == "-") {
		return value1 - value2;
	}
	else if (oper == "*") {
		return value2 * value1;
	}
	else if (oper == "/") {
		return value1 * 1.0 / value2;
	}
	else if (oper == "^") {
		return pow(value1, value2);
	}
}

//apply unary operator
double Calculator::doUnarOperator(double value, std::string oper) {
	if (oper == "--") {
		return -value;
	}
	else if (oper == "cos") {
		return cos(value);
	}
	else if (oper == "sin") {
		return sin(value);
	}
	else if (oper == "tg") {
		return tan(value);
	}
	else if (oper == "ctg") {
		return 1.0 / tan(value);
	}
	else if (oper == "ln") {
		return log(value);
	}
	else if (oper == "log") {
		return log10(value);
	}
	else if (oper == "sqrt") {
		return sqrt(value);
	}
	else {
		return cbrt(value);
	}
}


//check is number for culculating
bool Calculator::isNumber(std::string str) {
	
	if (str == "pi" || str == "e") {
		return true;
	}
	try
	{
		double value = std::stod(str);
		return true && checkCurrent(str);
	}
	catch (std::exception& e)
	{
		return false;
	}
}

//check type of operator
bool Calculator::isUnarOperator(std::string str) {
	if (str == "*" || str == "-" || str == "+" || str == "/" || str == "^") {
		return false;
	}
	else return true;
}
