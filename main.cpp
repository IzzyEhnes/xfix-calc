/********************************
 * AUTHOR: Izzy Ehnes           *
 * FILE: main.cpp               *
 * CREATED: March 5, 2019       *
 * LAST MODIFIED: June 18, 2020 *
 *******************************/

#include <iostream>
#include "xfix-calc.h"

using namespace xfix_calc;

int main()
{

	/*
	Expression expr1;
	std::string str1 = "(A + B) - C * (D / E)";
	Expression expr2("C - D");

	std::cout << str1 << std::endl;
	std::cout << expr2 << std::endl;

	expr1 = str1;

	std::cout << expr1 << std::endl;

	std::cout << expr1.getLength() << std::endl;

	std::cout << expr1.reverse(expr1) << std::endl;

	expr2 = expr2 + " * E";

	std::cout << expr2 << std::endl;

	expr2 += " / F";

	std::cout << expr2 << std::endl;
	*/

	Expression expr1;
	Expression expr2;
	Expression expr3;
	Expression expr4;
	Expression expr5;

	try
		{
			std::cout << "****************************************\n";
			std::cout << "* Testing of function \"infixToPostfix\" *\n";
			std::cout << "****************************************\n";

			std::cout << std::endl;
			expr1 = "A + B";
			std::cout << "Infix expression: ";
			std::cout << expr1 << std::endl;
			std::cout << "After conversion to postfix, the expression is now: ";
			std::cout << expr1.infixToPostfix() << std::endl;

			std::cout << std::endl;
			expr2 = "(A + B) * (C - D)";
			std::cout << "Infix expression: ";
			std::cout << expr2 << std::endl;
			std::cout << "After conversion to postfix, the expression is now: ";
			std::cout << expr2.infixToPostfix() << std::endl;

			std::cout << std::endl;
			expr3 = "A - (B + C * D) / E";
			std::cout << "Infix expression: ";
			std::cout << expr3 << std::endl;
			std::cout << "After conversion to postfix, the expression is now: ";
			std::cout << expr3.infixToPostfix() << std::endl;

			std::cout << std::endl;
			expr4 = "A ^ B / C * D + E";
			std::cout << "Infix expression: ";
			std::cout << expr4 << std::endl;
			std::cout << "After conversion to postfix, the expression is now: ";
			std::cout << expr4.infixToPostfix() << std::endl;

			std::cout << std::endl;
			expr5 = "A + B * (C - D) / E + (F ^ G - H)";
			std::cout << "Infix expression: ";
			std::cout << expr5 << std::endl;
			std::cout << "After conversion to postfix, the expression is now: ";
			std::cout << expr5.infixToPostfix() << std::endl;






			std::cout << "\n\n\n***************************************\n";
			std::cout << "* Testing of function \"infixToPrefix\" *\n";
			std::cout << "***************************************\n";

			std::cout << std::endl;
			expr1 = "A + B";
			std::cout << "Infix expression: ";
			std::cout << expr1 << std::endl;
			std::cout << "After conversion to prefix, the expression is now: ";
			std::cout << expr1.infixToPrefix() << std::endl;

			std::cout << std::endl;
			expr2 = "(A + B) * (C - D)";
			std::cout << "Infix expression: ";
			std::cout << expr2 << std::endl;
			std::cout << "After conversion to prefix, the expression is now: ";
			std::cout << expr2.infixToPrefix() << std::endl;

			std::cout << std::endl;
			expr3 = "A - (B + C * D) / E";
			std::cout << "Infix expression: ";
			std::cout << expr3 << std::endl;
			std::cout << "After conversion to prefix, the expression is now: ";
			std::cout << expr3.infixToPrefix() << std::endl;

			std::cout << std::endl;
			expr4 = "A ^ B / C * (D + E)";
			std::cout << "Infix expression: ";
			std::cout << expr4 << std::endl;
			std::cout << "After conversion to prefix, the expression is now: ";
			std::cout << expr4.infixToPrefix() << std::endl;

			std::cout << std::endl;
			expr5 = "A + B * (C - D ^ E) / F ^ G";
			std::cout << "Infix expression: ";
			std::cout << expr5 << std::endl;
			std::cout << "After conversion to prefix, the expression is now: ";
			std::cout << expr5.infixToPrefix() << std::endl;






			std::cout << "\n\n\n***************************************\n";
			std::cout << "* Testing of function \"prefixToInfix\" *\n";
			std::cout << "***************************************\n";

			std::cout << std::endl;
			expr1 = "A + B";
			std::cout << "Infix expression: ";
			std::cout << expr1 << std::endl;
			std::cout << "After conversion to prefix, the expression is now: ";
			expr1 = expr1.infixToPrefix();
			std::cout << expr1 << std::endl;
			std::cout << "After conversion back to infix, the expression is now: ";
			expr1 = expr1.prefixToInfix();
			std::cout << expr1 << std::endl;

			std::cout << std::endl;
			expr2 = "(A + B) * (C - D)";
			std::cout << "Infix expression: ";
			std::cout << expr2 << std::endl;
			std::cout << "After conversion to prefix, the expression is now: ";
			expr2 = expr2.infixToPrefix();
			std::cout << expr2 << std::endl;
			std::cout << "After conversion back to infix, the expression is now: ";
			expr2 = expr2.prefixToInfix();
			std::cout << expr2 << std::endl;

			std::cout << std::endl;
			expr3 = "A - (B + C * D) / E";
			std::cout << "Infix expression: ";
			std::cout << expr3 << std::endl;
			std::cout << "After conversion to prefix, the expression is now: ";
			expr3 = expr3.infixToPrefix();
			std::cout << expr3 << std::endl;
			std::cout << "After conversion back to infix, the expression is now: ";
			expr3 = expr3.prefixToInfix();
			std::cout << expr3 << std::endl;

			std::cout << std::endl;
			expr4 = "A ^ B / C * (D + E)";
			std::cout << "Infix expression: ";
			std::cout << expr4 << std::endl;
			std::cout << "After conversion to prefix, the expression is now: ";
			expr4 = expr4.infixToPrefix();
			std::cout << expr4 << std::endl;
			std::cout << "After conversion back to infix, the expression is now: ";
			expr4 = expr4.prefixToInfix();
			std::cout << expr4 << std::endl;

			std::cout << std::endl;
			expr5 = "A + B * (C - D ^ E) / F ^ G";
			std::cout << "Infix expression: ";
			std::cout << expr5 << std::endl;
			std::cout << "After conversion to prefix, the expression is now: ";
			expr5 = expr5.infixToPrefix();
			std::cout << expr5 << std::endl;
			std::cout << "After conversion back to infix, the expression is now: ";
			expr5 = expr5.prefixToInfix();
			std::cout << expr5 << std::endl;






			std::cout << "\n\n\n****************************************\n";
			std::cout << "* Testing of function \"postfixToInfix\" *\n";
			std::cout << "****************************************\n";

			std::cout << std::endl;
			expr1 = "A + B";
			std::cout << "Infix expression: ";
			std::cout << expr1 << std::endl;
			std::cout << "After conversion to postfix, the expression is now: ";
			expr1 = expr1.infixToPostfix();
			std::cout << expr1 << std::endl;
			std::cout << "After conversion back to infix, the expression is now: ";
			expr1 = expr1.postfixToInfix();
			std::cout << expr1 << std::endl;

			std::cout << std::endl;
			expr2 = "(A + B) * (C - D)";
			std::cout << "Infix expression: ";
			std::cout << expr2 << std::endl;
			std::cout << "After conversion to postfix, the expression is now: ";
			expr2 = expr2.infixToPostfix();
			std::cout << expr2 << std::endl;
			std::cout << "After conversion back to infix, the expression is now: ";
			expr2 = expr2.postfixToInfix();
			std::cout << expr2 << std::endl;

			std::cout << std::endl;
			expr3 = "A - (B + C * D) / E";
			std::cout << "Infix expression: ";
			std::cout << expr3 << std::endl;
			std::cout << "After conversion to postfix, the expression is now: ";
			expr3 = expr3.infixToPostfix();
			std::cout << expr3 << std::endl;
			std::cout << "After conversion back to infix, the expression is now: ";
			expr3 = expr3.postfixToInfix();
			std::cout << expr3 << std::endl;

			std::cout << std::endl;
			expr4 = "A ^ B / C * (D + E)";
			std::cout << "Infix expression: ";
			std::cout << expr4 << std::endl;
			std::cout << "After conversion to postfix, the expression is now: ";
			expr4 = expr4.infixToPostfix();
			std::cout << expr4 << std::endl;
			std::cout << "After conversion back to infix, the expression is now: ";
			expr4 = expr4.postfixToInfix();
			std::cout << expr4 << std::endl;

			std::cout << std::endl;
			expr5 = "A + B * (C - D ^ E) / F ^ G";
			std::cout << "Infix expression: ";
			std::cout << expr5 << std::endl;
			std::cout << "After conversion to postfix, the expression is now: ";
			expr5 = expr5.infixToPostfix();
			std::cout << expr5 << std::endl;
			std::cout << "After conversion back to infix, the expression is now: ";
			expr5 = expr5.postfixToInfix();
			std::cout << expr5 << std::endl;






			std::cout << "\n\n\n*****************************************\n";
			std::cout << "* Testing of function \"prefixToPostfix\" *\n";
			std::cout << "*****************************************\n";

			std::cout << std::endl;
			expr1 = "+ A B";
			std::cout << "Prefix expression: ";
			std::cout << expr1 << std::endl;
			std::cout << "After conversion to postfix, the expression is now: ";
			expr1 = expr1.prefixToPostfix();
			std::cout << expr1 << std::endl;

			std::cout << std::endl;
			expr2 = "* + A B - C D";
			std::cout << "Prefix expression: ";
			std::cout << expr2 << std::endl;
			std::cout << "After conversion to postfix, the expression is now: ";
			expr2 = expr2.prefixToPostfix();
			std::cout << expr2 << std::endl;

			std::cout << std::endl;
			expr3 = "- A / + B * C D E";
			std::cout << "Prefix expression: ";
			std::cout << expr3 << std::endl;
			std::cout << "After conversion to postfix, the expression is now: ";
			expr3 = expr3.prefixToPostfix();
			std::cout << expr3 << std::endl;

			std::cout << std::endl;
			expr4 = "/ ^ A B * C + D E";
			std::cout << "Prefix expression: ";
			std::cout << expr4 << std::endl;
			std::cout << "After conversion to postfix, the expression is now: ";
			expr4 = expr4.prefixToPostfix();
			std::cout << expr4 << std::endl;

			std::cout << std::endl;
			expr5 = "+ A * B / - C ^ D E ^ F G";
			std::cout << "Prefix expression: ";
			std::cout << expr5 << std::endl;
			std::cout << "After conversion to postfix, the expression is now: ";
			expr5 = expr5.prefixToPostfix();
			std::cout << expr5 << std::endl;






			std::cout << "\n\n\n*****************************************\n";
			std::cout << "* Testing of function \"postfixToPrefix\" *\n";
			std::cout << "*****************************************\n";

			std::cout << std::endl;
			expr1 = "A B +";
			std::cout << "Postfix expression: ";
			std::cout << expr1 << std::endl;
			std::cout << "After conversion to prefix, the expression is now: ";
			expr1 = expr1.postfixToPrefix();
			std::cout << expr1 << std::endl;

			std::cout << std::endl;
			expr2 = "A B + C D - *";
			std::cout << "Postfix expression: ";
			std::cout << expr2 << std::endl;
			std::cout << "After conversion to prefix, the expression is now: ";
			expr2 = expr2.postfixToPrefix();
			std::cout << expr2 << std::endl;

			std::cout << std::endl;
			expr3 = "A B C D * + E / -";
			std::cout << "Postfix expression: ";
			std::cout << expr3 << std::endl;
			std::cout << "After conversion to prefix, the expression is now: ";
			expr3 = expr3.postfixToPrefix();
			std::cout << expr3 << std::endl;

			std::cout << std::endl;
			expr4 = "A B ^ C D E + * /";
			std::cout << "Postfix expression: ";
			std::cout << expr4 << std::endl;
			std::cout << "After conversion to prefix, the expression is now: ";
			expr4 = expr4.postfixToPrefix();
			std::cout << expr4 << std::endl;

			std::cout << std::endl;
			expr5 = "A B C D E ^ - F G ^ / * +";
			std::cout << "Postfix expression: ";
			std::cout << expr5 << std::endl;
			std::cout << "After conversion to prefix, the expression is now: ";
			expr5 = expr5.postfixToPrefix();
			std::cout << expr5 << std::endl;






			std::cout << "\n\n\n*****************************************\n";
			std::cout << "* Testing of function \"evaluateInfix\"   *\n";
			std::cout << "*****************************************\n";

			std::cout << std::endl;
			expr1 = "10 % 5";
			std::cout << "Infix expression: ";
			std::cout << expr1 << std::endl;
			std::cout << "Calculated value: ";
			std::cout << expr1.evaluateInfix() << std::endl;

			std::cout << std::endl;
			expr2 = "(7 + 3) - 12 + 3";
			std::cout << "Infix expression: ";
			std::cout << expr2 << std::endl;
			std::cout << "Calculated value: ";
			std::cout << expr2.evaluateInfix() << std::endl;

			std::cout << std::endl;
			expr3 = "3 * 20 + (7 - 2)";
			std::cout << "Infix expression: ";
			std::cout << expr3 << std::endl;
			std::cout << "Calculated value: ";
			std::cout << expr3.evaluateInfix() << std::endl;

			std::cout << std::endl;
			expr4 = "((9 + 11) / (5 - 3)) * 3 + 7";
			std::cout << "Infix expression: ";
			std::cout << expr4 << std::endl;
			std::cout << "Calculated value: ";
			std::cout << expr4.evaluateInfix() << std::endl;

			std::cout << std::endl;
			expr5 = "(2 ^ 3 + (50 * 4)) / 4 ^ 2 - 20";
			std::cout << "Infix expression: ";
			std::cout << expr5 << std::endl;
			std::cout << "Calculated value: ";
			std::cout << expr5.evaluateInfix() << std::endl;






			std::cout << "\n\n\n*****************************************\n";
			std::cout << "* Testing of function \"evaluatePrefix\"  *\n";
			std::cout << "*****************************************\n";

			std::cout << std::endl;
			expr1 = "10 / 5";
			expr1 = expr1.infixToPrefix();
			std::cout << "Prefix expression: ";
			std::cout << expr1 << std::endl;
			std::cout << "Calculated value: ";
			std::cout << expr1.evaluatePrefix() << std::endl;

			std::cout << std::endl;
			expr2 = "(7 + 3) - 12 + 3";
			expr2 = expr2.infixToPrefix();
			std::cout << "Prefix expression: ";
			std::cout << expr2 << std::endl;
			std::cout << "Calculated value: ";
			std::cout << expr2.evaluatePrefix() << std::endl;

			std::cout << std::endl;
			expr3 = "3 * 20 + (7 - 2)";
			expr3 = expr3.infixToPrefix();
			std::cout << "Prefix expression: ";
			std::cout << expr3 << std::endl;
			std::cout << "Calculated value: ";
			std::cout << expr3.evaluatePrefix() << std::endl;

			std::cout << std::endl;
			expr4 = "((9 + 11) / (5 - 3)) * 3 + 7";
			expr4 = expr4.infixToPrefix();
			std::cout << "Prefix expression: ";
			std::cout << expr4 << std::endl;
			std::cout << "Calculated value: ";
			std::cout << expr4.evaluatePrefix() << std::endl;

			std::cout << std::endl;
			expr5 = "(2 ^ 3 + (50 * 4)) / 4 ^ 2 - 20";
			expr5 = expr5.infixToPrefix();
			std::cout << "Prefix expression: ";
			std::cout << expr5 << std::endl;
			std::cout << "Calculated value: ";
			std::cout << expr5.evaluatePrefix() << std::endl;






			std::cout << "\n\n\n*****************************************\n";
			std::cout << "* Testing of function \"evaluatePostfix\" *\n";
			std::cout << "*****************************************\n";

			std::cout << std::endl;
			expr1 = "10 + 243";
			expr1 = expr1.infixToPostfix();
			std::cout << "Postfix expression: ";
			std::cout << expr1 << std::endl;
			std::cout << "Calculated value: ";
			std::cout << expr1.evaluatePostfix() << std::endl;

			std::cout << std::endl;
			expr2 = "(7 + 3) - 12 + 3";
			expr2 = expr2.infixToPostfix();
			std::cout << "Postfix expression: ";
			std::cout << expr2 << std::endl;
			std::cout << "Calculated value: ";
			std::cout << expr2.evaluatePostfix() << std::endl;

			std::cout << std::endl;
			expr3 = "3 * 20 + (7 - 2)";
			expr3 = expr3.infixToPostfix();
			std::cout << "Postfix expression: ";
			std::cout << expr3 << std::endl;
			std::cout << "Calculated value: ";
			std::cout << expr3.evaluatePostfix() << std::endl;

			std::cout << std::endl;
			expr4 = "((9 + 11) % (5 - 3)) * 3 + 7";
			expr4 = expr4.infixToPostfix();
			std::cout << "Postfix expression: ";
			std::cout << expr4 << std::endl;
			std::cout << "Calculated value: ";
			std::cout << expr4.evaluatePostfix() << std::endl;

			std::cout << std::endl;
			expr5 = "(2 ^ 3 + (50 * 4)) / 4 ^ 2 - 20";
			expr5 = expr5.infixToPostfix();
			std::cout << "Postfix expression: ";
			std::cout << expr5 << std::endl;
			std::cout << "Calculated value: ";
			std::cout << expr5.evaluatePostfix() << std::endl;
		}

	catch(std::string& e)
	{
		std::cout << e;
	}
}
