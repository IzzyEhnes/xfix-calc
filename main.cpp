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


int evaluateInfix(std::string inExpression);
std::string infixToPostfix(std::string inExpression);
bool precedenceCheck(char inOperator);



/**************************************************
* evaluateInfix evaluates the incoming postfix    *
* string "inExpression" and calculates an answer, *
* which is then returned as an int value.         *
**************************************************/
int evaluateInfix(std::string inExpression)
{
	std::string postfixExp = infixToPostfix(inExpression);

	std::stack<int> calc_stack;

	int operand1, operand2;
	int length = inExpression.length();


	for (int count = 0; count < length; count++)
	{
		if (postfixExp[count] == '+' || postfixExp[count] == '-' ||
		    postfixExp[count] == '*' || postfixExp[count] == '/')
		{
			operand2 = calc_stack.top();
			calc_stack.pop();

			operand1 = calc_stack.top();
			calc_stack.pop();

			int result = 0;
			switch(postfixExp[count])
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
					result = operand1 / operand2;
					break;
			}

			calc_stack.push(result);
		}


		else if (isdigit(postfixExp[count]))
		{
			int temp = 0;
			int char_to_int;
			int length = postfixExp.length();

			while (count < length && isdigit(postfixExp[count]))
			{
				char_to_int = postfixExp[count] - '0';
				temp *= 10;
				temp += char_to_int;

				count++;
			}

			count--;

			calc_stack.push(temp);
		}
	}

	return calc_stack.top();
}






/******************************************************************
* precedenceCheck is a helper function for infixToPostfix.        *
* It returns '0' if inOperator is a '+' or '-' (lower precedence) *
* and '1' if inOperator is a '*', '^', or '/' (higher precedence).*
******************************************************************/
bool precedenceCheck(char inOperator)
{
	int precedence;

	if (inOperator == '+' || inOperator == '-')
	{
		precedence = 0;
	}

	else if (inOperator == '/' || inOperator == '*' || inOperator == '^')
	{
		precedence = 1;
	}

	return precedence;
}






/**********************************************************************
* infixToPostfix converts the incoming infix expression, infixString, *
* into postfix form and returns the result.                           *
**********************************************************************/
std::string infixToPostfix(std::string infixString)
{
	std::stack<char> operatorStack;
	std::string postfixString = "";

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
					postfixString += operatorStack.top();
					operatorStack.pop();
				}

				operatorStack.push(infixString[count]);
				break;



			case ')':

				while (operatorStack.top() != '(' && !operatorStack.empty())
				{
					postfixString += operatorStack.top();
					postfixString += ' ';
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

						postfixString += ' ';
						postfixString += temp;
						postfixString += ' ';
					}

					else
					{
						postfixString += ' ';
						postfixString += infixString[count];
						postfixString += ' ';
					}
				}

				break;
		}
	}


	while (!operatorStack.empty())
	{
		postfixString += operatorStack.top();
		postfixString += ' ';
		operatorStack.pop();
	}

	return postfixString;
}






int main()
{
	std::string string1;
	std::string string2;
	std::string string3;
	std::string string4;
	std::string string5;
	std::string string6;
	std::string string7;

	std::cout << std::endl;
	std::cout << "****************************************\n";
	std::cout << "* Testing of function \"infixToPostfix\" *\n";
	std::cout << "****************************************\n";

	std::cout << std::endl;
	string1 = "a - (b + c * d) / e";
	std::cout << "Infix expression: ";
	std::cout << string1 << std::endl;
	std::cout << "After conversion to postfix, the expression is now: ";
	std::cout << infixToPostfix(string1) << std::endl;

	std::cout << std::endl;
	string2 = "(a + b) * (c + d)";
	std::cout << "Infix expression: ";
	std::cout << string2 << std::endl;
	std::cout << "After conversion to postfix, the expression is now: ";
	std::cout << infixToPostfix(string2) << std::endl;

	std::cout << std::endl;
	string3 = "3 / (9 - 20)";
	std::cout << "Infix expression: ";
	std::cout << string3 << std::endl;
	std::cout << "After conversion to postfix, the expression is now: ";
	std::cout << infixToPostfix(string3) << std::endl;

	std::cout << std::endl;
	std::cout << "****************************************\n";
	std::cout << "* Testing of function \"evaluateInfix\" *\n";
	std::cout << "****************************************\n";

	std::cout << std::endl;
	string4 = "5 + 234";
	std::cout << "Infix expression: ";
	std::cout << string4 << std::endl;
	std::cout << "Calculated value: ";
	std::cout << evaluateInfix(string4) << std::endl;

	std::cout << std::endl;
	string5 = "(7 + 3) - 12 + (5 * 1)";
	std::cout << "Infix expression: ";
	std::cout << string5 << std::endl;
	std::cout << "Calculated value: ";
	std::cout << evaluateInfix(string5) << std::endl;

	std::cout << std::endl;
	string6 = "3 * 20 + (7 - 2)";
	std::cout << "Infix expression: ";
	std::cout << string6 << std::endl;
	std::cout << "Calculated value: ";
	std::cout << evaluateInfix(string6) << std::endl;

	std::cout << std::endl;
	string7 = "((9 + 11) / (5 - 3)) * 3 + 7";
	std::cout << "Infix expression: ";
	std::cout << string7 << std::endl;
	std::cout << "Calculated value: ";
	std::cout << evaluateInfix(string7) << std::endl;
}



/* OUTPUT:

****************************************
* Testing of function "infixToPostfix" *
****************************************

Infix expression: a - (b + c * d) / e
After conversion to postfix, the expression is now: a b c d * + e / -

Infix expression: (a + b) * (c + d)
After conversion to postfix, the expression is now: a b + c d + *

Infix expression: 3 / (9 - 20)
After conversion to postfix, the expression is now: 3 9 20 - /

****************************************
* Testing of function "evaluateInfix" *
****************************************

Infix expression: 5 + 234
Calculated value: 239

Infix expression: (7 + 3) - 12 + (5 * 1)
Calculated value: 3

Infix expression: 3 * 20 + (7 - 2)
Calculated value: 65

Infix expression: ((9 + 11) / (5 - 3)) * 3 + 7
Calculated value: 37

*/
