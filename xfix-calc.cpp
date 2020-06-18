/********************************
 * AUTHOR: Izzy Ehnes           *
 * FILE: xfix-calc.cpp          *
 * CREATED: March 5, 2019       *
 * LAST MODIFIED: June 18, 2020 *
 *******************************/

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






	void Expression::isValid() const
	{
		int numOperators = 0;
		int numOperands = 0;
		int length = this->getLength();

		for (int count = 0; count < length; count++)
		{
			if (isalnum(expression[count]))
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

					numOperands++;

				}

				else
				{
					numOperands++;
				}
			}

			else if (isOperator(expression[count]))
			{
				numOperators++;
			}

			else
			{
				if (expression[count] == '(' || expression[count] == ')' || expression[count] == ' ')
				{
					continue;
				}

				else
				{
					throw std::runtime_error(std::string("Error: Invalid character \'") +
						  expression[count] + std::string("\' in expression \'") +
						  expression + std::string("\'\n"));
				}
			}
		}



		if (numOperators == 0)
		{
			throw std::runtime_error("Error: Expression cannot have zero operators.");
		}

		else if (numOperands == 0)
		{
			throw std::runtime_error("Error: Expression cannot have zero operands.");
		}

		else if (numOperators != numOperands - 1)
		{
			throw std::runtime_error("Error: Invalid number of operands and/or operators.");
		}
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






	std::string Expression::reverse(std::string &inExpression)
	{
		int length = inExpression.length();

		// Changes open parentheses to closed parentheses and vice versa
		for (int i = 0; i < length; i++)
		{
			if (inExpression[i] == '(')
			{
				inExpression[i] = ')';
			}

			else if (inExpression[i] == ')')
			{
				inExpression[i] = '(';
			}
		}

		// Reverses the string
		for (int count = 0; count < length/2; count++)
		{
			char temp = inExpression[count];
			inExpression[count] = inExpression[length - 1 - count];
			inExpression[length - 1 - count] = temp;
		}

		return inExpression;
	}






	bool Expression::isOperator(const char inChar) const
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






	double Expression::calculate(const double operand1, const double operand2, const char symbol)
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






	int Expression::precedenceCheck(const char inOperator)
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






	double Expression::evaluateInfix()
	{
		double result = 0;
		Expression postfixExpression;

		postfixExpression = this->infixToPostfix();

		postfixExpression.isValid();

		result = postfixExpression.evaluatePostfix();


		return result;
	}






	double Expression::evaluatePostfix()
	{
		std::stack<int> stack;

		this->isValid();

		int length = this->getLength();
		std::string tempString = "";
		double tempNum = 0;

		double result = 0;

		for (int count = 0; count < length; count++)
		{

			// if current char is an operand
			if (isdigit(expression[count]))
			{
				std::string tempString;

				while (count < length && isdigit(expression[count]))
				{
						tempString += expression[count];
						count++;
				}

				count--;

				tempNum = stod(tempString);
				tempString = "";
				stack.push(tempNum);

			}


			// if current char is an operator
			else if (isOperator(expression[count]))
			{
				char symbol = expression[count];
				int operand1, operand2;
				operand2 = stack.top();
				stack.pop();
				operand1 = stack.top();
				stack.pop();

				stack.push(calculate(operand1, operand2, symbol));
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

		result = stack.top();;
		return result;
	}






	double Expression::evaluatePrefix()
	{
		double result = 0;
		Expression postfixExpression;

		postfixExpression = this->prefixToPostfix();

		postfixExpression.isValid();

		result = postfixExpression.evaluatePostfix();

		return result;
	}






	Expression Expression::infixToPostfix()
	{
		std::stack<char> operatorStack;
		Expression postfixString;

		this->isValid();

		int length = this->getLength();

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






	Expression Expression::infixToPrefix()
	{
		Expression postfixExpression;
		Expression prefixExpression;
		Expression reversedInfixExpression;

		this->isValid();

		reversedInfixExpression = reverse(*this);

		postfixExpression = reversedInfixExpression.infixToPostfix();
		prefixExpression = reverse(postfixExpression);

		return prefixExpression;
	}






	Expression Expression::postfixToInfix()
	{
		std::stack<std::string> stack;

		this->isValid();

		int length = this->getLength();
		Expression infixExpression;

		for (int count = 0; count < length; count++)
		{
			if (isOperator(expression[count]))
			{
				std::string operand1 = stack.top();
				stack.pop();

				std::string operand2 = stack.top();
				stack.pop();

				std::string temp = "(" + operand2 + ' ' + expression[count] + ' ' + operand1 + ")";

				stack.push(temp);
			}

			else if (isalnum(expression[count]))
			{
				if (isdigit(expression[count]))
				{
					std::string tempString;

					while (count < length && isdigit(expression[count]))
					{
						tempString += expression[count];
						count++;
					}

					count--;

					stack.push(tempString);
					tempString = "";
				}

				else
				{
					stack.push(std::string(1, expression[count]));
				}
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

		infixExpression = stack.top();
		return infixExpression;
	}






	Expression Expression::prefixToInfix()
	{
		std::stack<std::string> stack;
		Expression infixExpression;
		Expression reversedPrefixExpression;

		this->isValid();

		int length = this->getLength();
		reversedPrefixExpression = reverse(*this);


		for (int count = 0; count < length; count++)
		{
			if (isOperator(reversedPrefixExpression.expression[count]))
			{
				std::string operand1 = stack.top();
				stack.pop();

				std::string operand2 = stack.top();
				stack.pop();

				std::string temp = "(" + operand1 + ' ' + reversedPrefixExpression.expression[count] + ' ' + operand2 + ")";

				stack.push(temp);
			}

			else if (isalnum(reversedPrefixExpression.expression[count]))
			{
				if (isdigit(reversedPrefixExpression.expression[count]))
				{
					std::string tempString;

					while (count < length && isdigit(reversedPrefixExpression.expression[count]))
					{
						tempString += reversedPrefixExpression.expression[count];
						count++;
					}

					count--;

					stack.push(reverse(tempString));
					tempString = "";
				}

				else
				{
					stack.push(std::string(1, reversedPrefixExpression.expression[count]));
				}
			}

			else
			{
				if (reversedPrefixExpression.expression[count] != ' ')
				{
					throw std::runtime_error(std::string("Error: Invalid character \'") +
							reversedPrefixExpression.expression[count] + std::string("\' in expression \'") +
							reversedPrefixExpression.expression + std::string("\'\n"));
				}

				else
				{
					continue;
				}
			}
		  }

		infixExpression = stack.top();
		return infixExpression;
	}






	Expression Expression::prefixToPostfix()
	{
		Expression infixExpression;
		Expression postfixExpression;

		infixExpression = this->prefixToInfix();

		infixExpression.isValid();

		postfixExpression = infixExpression.infixToPostfix();

		return postfixExpression;
	}






	Expression Expression::postfixToPrefix()
	{
		Expression infixExpression;
		Expression prefixExpression;

		infixExpression = this->postfixToInfix();

		infixExpression.isValid();

		prefixExpression = infixExpression.infixToPrefix();

		return prefixExpression;
	}
}
