/*******************************
 * AUTHOR: Izzy Ehnes          *
 * FILE: xfix-calc.cpp         *
 * CREATED: March 5, 2019      *
 * LAST MODIFIED: June 8, 2020 *
 ******************************/

#include <iostream>
#include <stack>
#include <cctype>
#include <string>
#include <cmath>
#include <stdexcept>

#include "xfix-calc.h"



namespace xfix_calc
{






	Expression::Expression()
	{
		expression = "";
	}






	Expression::Expression(std::string inString)
	{
		expression = inString;
	}






	std::ostream& operator<<(std::ostream &out, const Expression &inExpression)
  	{
    	out << inExpression.expression;

    	return out;
  	}






	Expression operator+(const Expression &inExpression, const std::string &inString)
	{
		Expression temp;

		temp.expression = inExpression.expression + inString;

		return temp;
	}






	Expression Expression::operator+=(const char &inChar)
	{
    	*this = *this + inChar;

    	return *this;
	}






	Expression operator+(const Expression &inExpression, const char &inChar)
	{
		Expression temp;

		temp.expression = inExpression.expression + inChar;

		return temp;
	}






	Expression Expression::operator+=(const std::string &inString)
	{
    	*this = *this + inString;

    	return *this;
	}






	int Expression::getLength() const
	{
		int length = 0;
		length = expression.length();

		return length;
	}






	Expression Expression::reverse(Expression &inExpression)
	{

		int length = inExpression.getLength();


		// Changes open parentheses to closed parentheses and vice versa
		for (int i = 0; i < length; i++)
		{
			if (inExpression.expression[i] == '(')
			{
				inExpression.expression[i] = ')';
			}

			else if (inExpression.expression[i] == ')')
			{
				inExpression.expression[i] = '(';
			}
		}

		// Reverses the string
		for (int count = 0; count < length/2; count++)
		{
			char temp = inExpression.expression[count];
			inExpression.expression[count] = inExpression.expression[length - 1 - count];
			inExpression.expression[length - 1 - count] = temp;
		}


		return inExpression;
	}






	bool Expression::isOperator(char inChar)
	{
		switch(inChar)
		{
			case '+':
			case '-':
			case '*':
			case '/':
			case '%':
			case '^':
				return true;

			default:
				return false;
		}
	}






	double Expression::calculate(double operand1, double operand2, char symbol)
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

			case '%':
				result = fmod(operand1, operand2);
				break;

			case '/':
				if (operand2 == 0)
				{
					throw std::runtime_error("Math error: Cannot divide by zero.\n");
					break;
				}
				result = operand1 / operand2;
				break;

			case '^':
				result = pow(operand1, operand2);
				break;

			default:
				return -1;
		}

		return result;
	}






	int Expression::precedenceCheck(char inOperator)
	{
		if (inOperator == '^')
		{
			return 3;
		}

		else if (inOperator == '*' || inOperator == '/' || inOperator == '%')
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







	Expression Expression::operator=(const std::string &inString)
  	{
      	expression = inString;

      	return expression;
  	}


/*


	double evaluateInfix(std::string infixString)
	{
		double result = 0;
		std::string postfixString = "";

		postfixString = infixToPostfix(infixString);

		result = evaluatePostfix(postfixString);


		return result;
	}






	double evaluatePostfix(std::string postfixString)
	{
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
				std::string tempString;

				while (count < length && isdigit(postfixString[count]))
				{
						tempString += postfixString[count];
						count++;
				}

				count--;

				tempNum = stod(tempString);
				tempString = "";
				stack.push(tempNum);

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
				if (postfixString[count] != ' ')
				{
					throw std::runtime_error(std::string("Error: Invalid character \'") +
											 postfixString[count] + std::string("\' in expression \'") +
											 postfixString + std::string("\'\n"));
				}

				else
				{
					continue;
				}
			}

		}

		result = stack.top();;
		return result;
	}






	double evaluatePrefix(std::string prefixString)
	{
		double result = 0;

		std::string postfixString = prefixToPostfix(prefixString);
		result = evaluatePostfix(postfixString);

		return result;
	}

*/


	Expression Expression::infixToPostfix()
	{
		std::stack<char> operatorStack;
		Expression postfixString;

		int length = expression.length();

		for (int count = 0; count < length; count++)
		{
			if (expression[count] == '(')
			{
				operatorStack.push('(');
			}

			else if (isalnum(expression[count]))
			{
				if (isdigit(expression[count]))
				{
					std::string temp;

					while (count < length && isdigit(expression[count]))
					{
						temp += expression[count];
						count++;
					}

					count--;

					postfixString += temp;
					postfixString += ' ';

				}

				else
				{
					postfixString += expression[count];
					postfixString += ' ';
				}
			}

			else if (expression[count] == ')')
			{
				while (operatorStack.top() != '(' && !operatorStack.empty())
				{
					postfixString += operatorStack.top();
					postfixString += ' ';

					operatorStack.pop();
				}
					operatorStack.pop();
			}

			else if (isOperator(expression[count]))
			{
				while (!operatorStack.empty() &&
						(precedenceCheck(operatorStack.top()) >= precedenceCheck(expression[count]))
						&& operatorStack.top() != '(' && operatorStack.top() != ')')
				{
					postfixString += operatorStack.top();
					operatorStack.pop();
					postfixString += ' ';
				}
					operatorStack.push(expression[count]);
			}

			else
			{
				if (expression[count] != ' ')
				{
					throw std::runtime_error(std::string("Error: Invalid character \'") +
							expression[count] + std::string("\' in expression \'") +
							expression + std::string("\'\n"));
				}

				else
				{
					continue;
				}
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

/*
	Expression Expression::infixToPostfix(const Expression infixString)
	{
		std::stack<char> operatorStack;
		Expression postfixString;

		int length = infixString.getLength();

		for (int count = 0; count < length; count++)
		{
			if (infixString.expression[count] == '(')
			{
				operatorStack.push('(');
			}

			else if (isalnum(infixString.expression[count]))
			{
				if (isdigit(infixString.expression[count]))
				{
					std::string temp;

					while (count < length && isdigit(infixString.expression[count]))
					{
						temp += infixString.expression[count];
						count++;
					}

					count--;

					postfixString += temp;
					postfixString += ' ';

				}

				else
				{
					postfixString += infixString.expression[count];
					postfixString += ' ';
				}
			}

			else if (infixString.expression[count] == ')')
			{
				while (operatorStack.top() != '(' && !operatorStack.empty())
				{
					postfixString += operatorStack.top();
					postfixString += ' ';

					operatorStack.pop();
				}
					operatorStack.pop();
			}

			else if (isOperator(infixString.expression[count]))
			{
				while (!operatorStack.empty() &&
						(precedenceCheck(operatorStack.top()) >= precedenceCheck(infixString.expression[count]))
						&& operatorStack.top() != '(' && operatorStack.top() != ')')
				{
					postfixString += operatorStack.top();
					operatorStack.pop();
					postfixString += ' ';
				}
					operatorStack.push(infixString.expression[count]);
			}

			else
			{
				if (infixString.expression[count] != ' ')
				{
					throw std::runtime_error(std::string("Error: Invalid character \'") +
											 infixString.expression[count] + std::string("\' in expression \'") +
											 infixString.expression + std::string("\'\n"));
				}

				else
				{
					continue;
				}
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

*/
/*



	std::string infixToPrefix(std::string infixString)
	{
		std::stack<char> operatorStack;
		std::stack<char> operandStack;
		std::string postfixExp = "";
		std::string prefixExp = "";
		std::string reversedExp = reverse(infixString);

		postfixExp = infixToPostfix(reversedExp);
		prefixExp = reverse(postfixExp);

		return prefixExp;
	}






	std::string postfixToInfix(std::string postfixString)
	{
		std::stack<std::string> stack;
		int length = postfixString.size();
		std::string infixString = "";

		for (int count = 0; count < length; count++)
		{
			if (isOperator(postfixString[count]))
			{
				std::string operand1 = stack.top();
				stack.pop();

				std::string operand2 = stack.top();
				stack.pop();

				std::string temp = "(" + operand2 + ' ' + postfixString[count] + ' ' + operand1 + ")";

				stack.push(temp);
			}

			else if (isalnum(postfixString[count]))
			{
				if (isdigit(postfixString[count]))
				{
					std::string tempString;

					while (count < length && isdigit(postfixString[count]))
					{
						tempString += postfixString[count];
						count++;
					}

					count--;

					stack.push(tempString);
					tempString = "";
				}

				else
				{
					stack.push(std::string(1, postfixString[count]));
				}
			}

			else
			{
				if (postfixString[count] != ' ')
				{
					throw std::runtime_error(std::string("Error: Invalid character \'") +
											 postfixString[count] + std::string("\' in expression \'") +
											 postfixString + std::string("\'\n"));
				}

				else
				{
					continue;
				}
			}
		}

		infixString = stack.top();
		return infixString;
	}






	std::string prefixToInfix(std::string prefixString)
	{
		std::stack<std::string> stack;
		std::string infixString = "";

		int length = prefixString.size();
		std::string reversedString = reverse(prefixString);


		for (int count = 0; count < length; count++)
		{
			if (isOperator(reversedString[count]))
			{
				std::string operand1 = stack.top();
				stack.pop();

				std::string operand2 = stack.top();
				stack.pop();

				std::string temp = "(" + operand1 + ' ' + reversedString[count] + ' ' + operand2 + ")";

				stack.push(temp);
			}

			else if (isalnum(reversedString[count]))
			{
				if (isdigit(reversedString[count]))
				{
					std::string tempString;

					while (count < length && isdigit(reversedString[count]))
					{
						tempString += reversedString[count];
						count++;
					}

					count--;

					stack.push(reverse(tempString));
					tempString = "";
				}

				else
				{
					stack.push(std::string(1, reversedString[count]));
				}
			}

			else
			{
				if (reversedString[count] != ' ')
				{
					throw std::runtime_error(std::string("Error: Invalid character \'") +
											 reversedString[count] + std::string("\' in expression \'") +
											 reversedString + std::string("\'\n"));
				}

				else
				{
					continue;
				}
			}
		  }

		infixString = stack.top();
		return infixString;
	}






	std::string prefixToPostfix(std::string prefixString)
	{
		std::string infixString = prefixToInfix(prefixString);
		std::string postfixString = infixToPostfix(infixString);

		return postfixString;
	}






	std::string postfixToPrefix(std::string postfixString)
	{
		std::string infixString = postfixToInfix(postfixString);
		std::string prefixString = infixToPrefix(infixString);

		return prefixString;
	}

	*/
}
