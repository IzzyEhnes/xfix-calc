// Izzy Ehnes
// main.cpp
// 5 March 2019

/*
	DESCRIPTION:

	This program converts infix expressions into postfix form and can then compute
	an answer. It requires there to spaces between the operands and operators to work
	correctly to prevent any issues with multiple-digit operands.

	The main() function tests the functions by providing various infix problems,
	which are converted to postfix in the function infixToPostfix and calculated in the
	function evaluateInfix.

*/



#include <iostream>
#include <stack>
#include <cctype>
#include <string>
#include <cmath>



// Main functions
double evaluatePostfix(std::string inExpression);
std::string infixToPostfix(std::string inExpression);

// Helper functions
int precedenceCheck(char inOperator);
bool isOperator(char inChar);
double calculate(double operand1, double operand2, char symbol);



bool isOperator(char inChar)
{
	switch(inChar)
	{
		case '+':
		case '-':
		case '*':
		case '/':
		case '^':
			return true;

		default:
			return false;
	}
}






double calculate(double operand1, double operand2, char symbol)
{
	double result = 0;

	switch (symbol)
	{
		case '+':
			result = operand1 + operand2;
			break;

		case '-':
			result = operand1 - operand2;
			break;

		case '*':
			result = operand1 * operand2;
			break;

		case '/':
			// add throw div by 0 error
			result = operand1 / operand2;
			break;

		case '^':
			result = pow(operand1, operand2);
			break;

		default:
			//add throw error
			return -1;
	}

	return result;
}






/**************************************************
* evaluatePostfix evaluates the incoming infix    *
* string "inExpression" and calculates an answer, *
* which is then returned as an double value.      *
**************************************************/
double evaluatePostfix(std::string inExpression)
{
	std::string postfixString = infixToPostfix(inExpression);

	std::stack<int> stack;

	int length = postfixString.length();
	std::string tempString = "";
	double tempNum = 0;

	double result = 0;

	for (int count = 0; count < length; count++)
	{
		// if current char is an operand
		if (isdigit(postfixString[count]))
		{
			int i = count + 1;
			if (i <= length - 1)
			{
				tempString += postfixString[count];
				while (postfixString[i] != ' ' && i <= length - 1)
				{
					tempString += postfixString[i];
					i++;
				}
			}


			tempNum = stod(tempString);
			stack.push(tempNum);
			tempNum = 0;
			tempString = "";

			if (i < length - 1)
			{
				count = i;
			}
		}

		// if current char is an operator
		else if (isOperator(postfixString[count]))
		{
			char symbol = postfixString[count];
			int operand1, operand2;
			operand2 = stack.top();
			stack.pop();
			operand1 = stack.top();
			stack.pop();

			stack.push(calculate(operand1, operand2, symbol));
		}

		else
		{
			//add error if not space char
			continue;
		}

	}

	result = stack.top();;
	return result;
}






/******************************************************************
* precedenceCheck is a helper function for infixToPostfix.        *
* It returns '0' if inOperator is a '+' or '-' (lower precedence) *
* and '1' if inOperator is a '*', '^', or '/' (higher precedence).*
******************************************************************/
int precedenceCheck(char inOperator)
{
	if (inOperator == '^')
	{
		return 3;
	}

	else if (inOperator == '*' || inOperator == '/')
	{
		return 2;
	}

	else if (inOperator == '+' || inOperator == '-')
	{
		return 1;
	}

	else
	{
		return 0;
	}
}






/**********************************************************************
* infixToPostfix converts the incoming infix expression, infixString, *
* into postfix form and returns the result.                           *
**********************************************************************/

std::string infixToPostfix(std::string infixString)
{
	std::stack<char> operatorStack;
		std::string postfixExp = "";

		int length = infixString.length();

		for (int count = 0; count < length; count++)
		{
			switch (infixString[count])
			{

				case '(':
					operatorStack.push(infixString[count]);
					break;



				case '+':
				case '-':
				case '*':
				case '/':
				case '^':
					while (!operatorStack.empty() &&
							operatorStack.top() != '(' &&
						    precedenceCheck(infixString[count]) <= precedenceCheck(operatorStack.top()))
					{
						postfixExp += operatorStack.top();
						postfixExp += ' ';
						operatorStack.pop();
					}

					operatorStack.push(infixString[count]);
					break;



				case ')':

					while (operatorStack.top() != '(' && !operatorStack.empty())
					{
						postfixExp += operatorStack.top();
						postfixExp += ' ';
						operatorStack.pop();
					}

					operatorStack.pop();
					break;



				default:
				 	if (isalnum(infixString[count]))
					{
						if (isdigit(infixString[count]))
						{
							std::string temp;

							while (count < length && isdigit(infixString[count]))
							{
								temp += infixString[count];
								count++;
							}

							count--;

							postfixExp += ' ';
							postfixExp += temp;
							postfixExp += ' ';
						}

						else
						{
							postfixExp += infixString[count];
							postfixExp += ' ';
						}
					}

					break;
			}
		}


		while (!operatorStack.empty())
		{
			postfixExp += operatorStack.top();
			postfixExp += ' ';
			operatorStack.pop();
		}

		return postfixExp;
}







int main()
{
	std::string string1;
	std::string string2;
	std::string string3;
	std::string string4;
	std::string string5;



	std::cout << std::endl;
	std::cout << "****************************************\n";
	std::cout << "* Testing of function \"infixToPostfix\" *\n";
	std::cout << "****************************************\n";

	std::cout << std::endl;
	string1 = "A + B";
	std::cout << "Infix expression: ";
	std::cout << string1 << std::endl;
	std::cout << "After conversion to postfix, the expression is now: ";
	std::cout << infixToPostfix(string1) << std::endl;

	std::cout << std::endl;
	string2 = "(A + B) * (C - D)";
	std::cout << "Infix expression: ";
	std::cout << string2 << std::endl;
	std::cout << "After conversion to postfix, the expression is now: ";
	std::cout << infixToPostfix(string2) << std::endl;

	std::cout << std::endl;
	string3 = "A - (B + C * D) / E";
	std::cout << "Infix expression: ";
	std::cout << string3 << std::endl;
	std::cout << "After conversion to postfix, the expression is now: ";
	std::cout << infixToPostfix(string3) << std::endl;

	std::cout << std::endl;
	string4 = "A ^ B / C * (D + E)";
	std::cout << "Infix expression: ";
	std::cout << string4 << std::endl;
	std::cout << "After conversion to postfix, the expression is now: ";
	std::cout << infixToPostfix(string4) << std::endl;

	std::cout << std::endl;
	string5 = "A + B * (C - D ^ E) / F ^ G";
	std::cout << "Infix expression: ";
	std::cout << string5 << std::endl;
	std::cout << "After conversion to postfix, the expression is now: ";
	std::cout << infixToPostfix(string5) << std::endl;






	std::cout << "\n\n\n****************************************\n";
	std::cout << "* Testing of function \"evaluatePostfix\"  *\n";
	std::cout << "****************************************\n";

	std::cout << std::endl;
	string1 = "10 + 243";
	std::cout << "Infix expression: ";
	std::cout << string1 << std::endl;
	std::cout << "Calculated value: ";
	std::cout << evaluatePostfix(string1) << std::endl;

	std::cout << std::endl;
	string2 = "(7 + 3) - 12 + (5 * 1)";
	std::cout << "Infix expression: ";
	std::cout << string2 << std::endl;
	std::cout << "Calculated value: ";
	std::cout << evaluatePostfix(string2) << std::endl;

	std::cout << std::endl;
	string3 = "3 * 20 + (7 - 2)";
	std::cout << "Infix expression: ";
	std::cout << string3 << std::endl;
	std::cout << "Calculated value: ";
	std::cout << evaluatePostfix(string3) << std::endl;

	std::cout << std::endl;
	string4 = "((9 + 11) / (5 - 3)) * 3 + 7";
	std::cout << "Infix expression: ";
	std::cout << string4 << std::endl;
	std::cout << "Calculated value: ";
	std::cout << evaluatePostfix(string4) << std::endl;

	std::cout << std::endl;
	string5 = "(2 ^ 3 + (50 * 4)) / 4 ^ 2 - 20";
	std::cout << "Infix expression: ";
	std::cout << string5 << std::endl;
	std::cout << "Calculated value: ";
	std::cout << evaluatePostfix(string5) << std::endl;
}
