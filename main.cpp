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



// Main functions
int evaluateInfix(std::string inExpression);
std::string infixToPostfix(std::string inExpression);

// Helper functions
int precedenceCheck(char inOperator);
bool isOperator(char inChar);



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






/**************************************************
* evaluateInfix evaluates the incoming postfix    *
* string "inExpression" and calculates an answer, *
* which is then returned as an int value.         *
**************************************************/
int evaluateInfix(std::string inExpression)
{
	std::string postfixString = infixToPostfix(inExpression);

	std::stack<int> calc_stack;

	int operand1, operand2;
	int length = inExpression.length();


	for (int count = 0; count < length; count++)
	{
		if (postfixString[count] == '+' || postfixString[count] == '-' ||
		    postfixString[count] == '*' || postfixString[count] == '/' ||
			postfixString[count] == '^')
		{
			operand2 = calc_stack.top();
			calc_stack.pop();

			operand1 = calc_stack.top();
			calc_stack.pop();

			int result = 0;
			switch(postfixString[count])
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

				case '^':
					result = operand1 ^ operand2;
			}

			calc_stack.push(result);
		}


		else if (isdigit(postfixString[count]))
		{
			int temp = 0;
			int char_to_int;
			int length = postfixString.length();

			while (count < length && isdigit(postfixString[count]))
			{
				char_to_int = postfixString[count] - '0';
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
	std::string string6;
	std::string string7;



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






	std::cout << std::endl;
	std::cout << "\n\n\n****************************************\n";
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
