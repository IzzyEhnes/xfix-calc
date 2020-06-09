/*******************************
 * AUTHOR: Izzy Ehnes          *
 * FILE: main.cpp              *
 * CREATED: March 5, 2019      *
 * LAST MODIFIED: June 8, 2020 *
 ******************************/

#include <iostream>
#include "xfix-calc.h"

using namespace xfix_calc;

int main()
{
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


	/*
	std::string string1;
	std::string string2;
	std::string string3;
	std::string string4;
	std::string string5;

	try
	{
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
		string4 = "A ^ B / C * D + E";
		std::cout << "Infix expression: ";
		std::cout << string4 << std::endl;
		std::cout << "After conversion to postfix, the expression is now: ";
		std::cout << infixToPostfix(string4) << std::endl;

		std::cout << std::endl;
		string5 = "A + B * (C - D) / E + (F ^ G - H)";
		std::cout << "Infix expression: ";
		std::cout << string5 << std::endl;
		std::cout << "After conversion to postfix, the expression is now: ";
		std::cout << infixToPostfix(string5) << std::endl;






		std::cout << "\n\n\n***************************************\n";
		std::cout << "* Testing of function \"infixToPrefix\" *\n";
		std::cout << "***************************************\n";

		std::cout << std::endl;
		string1 = "A + B";
		std::cout << "Infix expression: ";
		std::cout << string1 << std::endl;
		std::cout << "After conversion to prefix, the expression is now: ";
		std::cout << infixToPrefix(string1) << std::endl;

		std::cout << std::endl;
		string2 = "(A + B) * (C - D)";
		std::cout << "Infix expression: ";
		std::cout << string2 << std::endl;
		std::cout << "After conversion to prefix, the expression is now: ";
		std::cout << infixToPrefix(string2) << std::endl;

		std::cout << std::endl;
		string3 = "A - (B + C * D) / E";
		std::cout << "Infix expression: ";
		std::cout << string3 << std::endl;
		std::cout << "After conversion to prefix, the expression is now: ";
		std::cout << infixToPrefix(string3) << std::endl;

		std::cout << std::endl;
		string4 = "A ^ B / C * D + E)";
		std::cout << "Infix expression: ";
		std::cout << string4 << std::endl;
		std::cout << "After conversion to prefix, the expression is now: ";
		std::cout << infixToPrefix(string4) << std::endl;

		std::cout << std::endl;
		string5 = "A + B * (C - D ^ E) / F ^ G";
		std::cout << "Infix expression: ";
		std::cout << string5 << std::endl;
		std::cout << "After conversion to prefix, the expression is now: ";
		std::cout << infixToPrefix(string5) << std::endl;






		std::cout << "\n\n\n****************************************\n";
		std::cout << "* Testing of function \"postfixToInfix\" *\n";
		std::cout << "****************************************\n";

		std::cout << std::endl;
		string1 = "A + B";
		std::cout << "Infix expression: ";
		std::cout << string1 << std::endl;
		std::cout << "After conversion to postfix, the expression is now: ";
		string1 = infixToPostfix(string1);
		std::cout << string1 << std::endl;
		std::cout << "After conversion back to infix, the expression is now: ";
		string1 = postfixToInfix(string1);
		std::cout << string1 << std::endl;

		std::cout << std::endl;
		string2 = "(A + B) * (C - D)";
		std::cout << "Infix expression: ";
		std::cout << string2 << std::endl;
		std::cout << "After conversion to postfix, the expression is now: ";
		string2 = infixToPostfix(string2);
		std::cout << string2 << std::endl;
		std::cout << "After conversion back to infix, the expression is now: ";
		string2 = postfixToInfix(string2);
		std::cout << string2 << std::endl;

		std::cout << std::endl;
		string3 = "A - (B + C * D) / E";
		std::cout << "Infix expression: ";
		std::cout << string3 << std::endl;
		std::cout << "After conversion to postfix, the expression is now: ";
		string3 = infixToPostfix(string3);
		std::cout << string3 << std::endl;
		std::cout << "After conversion back to infix, the expression is now: ";
		string3 = postfixToInfix(string3);
		std::cout << string3 << std::endl;

		std::cout << std::endl;
		string4 = "A ^ B / C * (D + E)";
		std::cout << "Infix expression: ";
		std::cout << string4 << std::endl;
		std::cout << "After conversion to postfix, the expression is now: ";
		string4 = infixToPostfix(string4);
		std::cout << string4 << std::endl;
		std::cout << "After conversion back to infix, the expression is now: ";
		string4 = postfixToInfix(string4);
		std::cout << string4 << std::endl;

		std::cout << std::endl;
		string5 = "A + B * (C - D ^ E) / F ^ G";
		std::cout << "Infix expression: ";
		std::cout << string5 << std::endl;
		std::cout << "After conversion to postfix, the expression is now: ";
		string5 = infixToPostfix(string5);
		std::cout << string5 << std::endl;
		std::cout << "After conversion back to infix, the expression is now: ";
		string5 = postfixToInfix(string5);
		std::cout << string5 << std::endl;






		std::cout << "\n\n\n***************************************\n";
		std::cout << "* Testing of function \"prefixToInfix\" *\n";
		std::cout << "***************************************\n";

		std::cout << std::endl;
		string1 = "A + B";
		std::cout << "Infix expression: ";
		std::cout << string1 << std::endl;
		std::cout << "After conversion to prefix, the expression is now: ";
		string1 = infixToPrefix(string1);
		std::cout << string1 << std::endl;
		std::cout << "After conversion back to infix, the expression is now: ";
		string1 = prefixToInfix(string1);
		std::cout << string1 << std::endl;

		std::cout << std::endl;
		string2 = "(A + B) * (C - D)";
		std::cout << "Infix expression: ";
		std::cout << string2 << std::endl;
		std::cout << "After conversion to prefix, the expression is now: ";
		string2 = infixToPrefix(string2);
		std::cout << string2 << std::endl;
		std::cout << "After conversion back to infix, the expression is now: ";
		string2 = prefixToInfix(string2);
		std::cout << string2 << std::endl;

		std::cout << std::endl;
		string3 = "A - (B + C * D) / E";
		std::cout << "Infix expression: ";
		std::cout << string3 << std::endl;
		std::cout << "After conversion to prefix, the expression is now: ";
		string3 = infixToPrefix(string3);
		std::cout << string3 << std::endl;
		std::cout << "After conversion back to infix, the expression is now: ";
		string3 = prefixToInfix(string3);
		std::cout << string3 << std::endl;

		std::cout << std::endl;
		string4 = "A ^ B / C * (D + E)";
		std::cout << "Infix expression: ";
		std::cout << string4 << std::endl;
		std::cout << "After conversion to prefix, the expression is now: ";
		string4 = infixToPrefix(string4);
		std::cout << string4 << std::endl;
		std::cout << "After conversion back to infix, the expression is now: ";
		string4 = prefixToInfix(string4);
		std::cout << string4 << std::endl;

		std::cout << std::endl;
		string5 = "A + B * (C - D ^ E) / F ^ G";
		std::cout << "Infix expression: ";
		std::cout << string5 << std::endl;
		std::cout << "After conversion to prefix, the expression is now: ";
		string5 = infixToPrefix(string5);
		std::cout << string5 << std::endl;
		std::cout << "After conversion back to infix, the expression is now: ";
		string5 = prefixToInfix(string5);
		std::cout << string5 << std::endl;






		std::cout << "\n\n\n*****************************************\n";
		std::cout << "* Testing of function \"prefixToPostfix\" *\n";
		std::cout << "*****************************************\n";

		std::cout << std::endl;
		string1 = "+ A B";
		std::cout << "Prefix expression: ";
		std::cout << string1 << std::endl;
		std::cout << "After conversion to postfix, the expression is now: ";
		string1 = prefixToPostfix(string1);
		std::cout << string1 << std::endl;

		std::cout << std::endl;
		string2 = "* + A B - C D";
		std::cout << "Prefix expression: ";
		std::cout << string2 << std::endl;
		std::cout << "After conversion to postfix, the expression is now: ";
		string2 = prefixToPostfix(string2);
		std::cout << string2 << std::endl;

		std::cout << std::endl;
		string3 = "- A / + B * C D E";
		std::cout << "Prefix expression: ";
		std::cout << string3 << std::endl;
		std::cout << "After conversion to postfix, the expression is now: ";
		string3 = prefixToPostfix(string3);
		std::cout << string3 << std::endl;

		std::cout << std::endl;
		string4 = "/ ^ A B * C + D E";
		std::cout << "Prefix expression: ";
		std::cout << string4 << std::endl;
		std::cout << "After conversion to postfix, the expression is now: ";
		string4 = prefixToPostfix(string4);
		std::cout << string4 << std::endl;

		std::cout << std::endl;
		string5 = "+ A * B / - C ^ D E ^ F G";
		std::cout << "Prefix expression: ";
		std::cout << string5 << std::endl;
		std::cout << "After conversion to postfix, the expression is now: ";
		string5 = prefixToPostfix(string5);
		std::cout << string5 << std::endl;






		std::cout << "\n\n\n*****************************************\n";
		std::cout << "* Testing of function \"postfixToPrefix\" *\n";
		std::cout << "*****************************************\n";

		std::cout << std::endl;
		string1 = "A B +";
		std::cout << "Postfix expression: ";
		std::cout << string1 << std::endl;
		std::cout << "After conversion to prefix, the expression is now: ";
		string1 = postfixToPrefix(string1);
		std::cout << string1 << std::endl;

		std::cout << std::endl;
		string2 = "A B + C D - *";
		std::cout << "Postfix expression: ";
		std::cout << string2 << std::endl;
		std::cout << "After conversion to prefix, the expression is now: ";
		string2 = postfixToPrefix(string2);
		std::cout << string2 << std::endl;

		std::cout << std::endl;
		string3 = "A B C D * + E / -";
		std::cout << "Postfix expression: ";
		std::cout << string3 << std::endl;
		std::cout << "After conversion to prefix, the expression is now: ";
		string3 = postfixToPrefix(string3);
		std::cout << string3 << std::endl;

		std::cout << std::endl;
		string4 = "A B ^ C D E + * /";
		std::cout << "Postfix expression: ";
		std::cout << string4 << std::endl;
		std::cout << "After conversion to prefix, the expression is now: ";
		string4 = postfixToPrefix(string4);
		std::cout << string4 << std::endl;

		std::cout << std::endl;
		string5 = "A B C D E ^ - F G ^ / * +";
		std::cout << "Postfix expression: ";
		std::cout << string5 << std::endl;
		std::cout << "After conversion to prefix, the expression is now: ";
		string5 = postfixToPrefix(string5);
		std::cout << string5 << std::endl;






		std::cout << "\n\n\n*****************************************\n";
		std::cout << "* Testing of function \"evaluateInfix\" *\n";
		std::cout << "*****************************************\n";

		std::cout << std::endl;
		string1 = "10 % 5";
		std::cout << "Infix expression: ";
		std::cout << string1 << std::endl;
		std::cout << "Calculated value: ";
		std::cout << evaluateInfix(string1) << std::endl;

		std::cout << std::endl;
		string2 = "(7 + 3) - 12 + 3";
		std::cout << "Infix expression: ";
		std::cout << string2 << std::endl;
		std::cout << "Calculated value: ";
		std::cout << evaluateInfix(string2) << std::endl;

		std::cout << std::endl;
		string3 = "3 * 20 + (7 - 2)";
		std::cout << "Infix expression: ";
		std::cout << string3 << std::endl;
		std::cout << "Calculated value: ";
		std::cout << evaluateInfix(string3) << std::endl;

		std::cout << std::endl;
		string4 = "((9 + 11) / (5 - 3)) * 3 + 7";
		std::cout << "Infix expression: ";
		std::cout << string4 << std::endl;
		std::cout << "Calculated value: ";
		std::cout << evaluateInfix(string4) << std::endl;

		std::cout << std::endl;
		string5 = "(2 ^ 3 + (50 * 4)) / 4 ^ 2 - 20";
		std::cout << "Infix expression: ";
		std::cout << string5 << std::endl;
		std::cout << "Calculated value: ";
		std::cout << evaluateInfix(string5) << std::endl;






		std::cout << "\n\n\n*****************************************\n";
		std::cout << "* Testing of function \"evaluatePostfix\" *\n";
		std::cout << "*****************************************\n";

		std::cout << std::endl;
		string1 = "10 + 243";
		string1 = infixToPostfix(string1);
		std::cout << "Postfix expression: ";
		std::cout << string1 << std::endl;
		std::cout << "Calculated value: ";
		std::cout << evaluatePostfix(string1) << std::endl;

		std::cout << std::endl;
		string2 = "(7 + 3) - 12 + 3";
		string2 = infixToPostfix(string2);
		std::cout << "Postfix expression: ";
		std::cout << string2 << std::endl;
		std::cout << "Calculated value: ";
		std::cout << evaluatePostfix(string2) << std::endl;

		std::cout << std::endl;
		string3 = "3 * 20 + (7 - 2)";
		string3 = infixToPostfix(string3);
		std::cout << "Postfix expression: ";
		std::cout << string3 << std::endl;
		std::cout << "Calculated value: ";
		std::cout << evaluatePostfix(string3) << std::endl;

		std::cout << std::endl;
		string4 = "((9 + 11) % (5 - 3)) * 3 + 7";
		string4 = infixToPostfix(string4);
		std::cout << "Postfix expression: ";
		std::cout << string4 << std::endl;
		std::cout << "Calculated value: ";
		std::cout << evaluatePostfix(string4) << std::endl;

		std::cout << std::endl;
		string5 = "(2 ^ 3 + (50 * 4)) / 4 ^ 2 - 20";
		string5 = infixToPostfix(string5);
		std::cout << "Postfix expression: ";
		std::cout << string5 << std::endl;
		std::cout << "Calculated value: ";
		std::cout << evaluatePostfix(string5) << std::endl;






		std::cout << "\n\n\n*****************************************\n";
		std::cout << "* Testing of function \"evaluatePrefix\" *\n";
		std::cout << "*****************************************\n";

		std::cout << std::endl;
		string1 = "10 / 5";
		string1 = infixToPrefix(string1);
		std::cout << "Prefix expression: ";
		std::cout << string1 << std::endl;
		std::cout << "Calculated value: ";
		std::cout << evaluatePrefix(string1) << std::endl;

		std::cout << std::endl;
		string2 = "(7 + 3) - 12 + 3";
		string2 = infixToPrefix(string2);
		std::cout << "Prefix expression: ";
		std::cout << string2 << std::endl;
		std::cout << "\nPrefix to infix: " << prefixToInfix(string2) << std::endl;
		std::cout << "Calculated value: ";
		std::cout << evaluatePrefix(string2) << std::endl;

		std::cout << std::endl;
		string3 = "3 * 20 + (7 - 2)";
		string3 = infixToPrefix(string3);
		std::cout << "Prefix expression: ";
		std::cout << string3 << std::endl;
		std::cout << "Calculated value: ";
		std::cout << evaluatePrefix(string3) << std::endl;

		std::cout << std::endl;
		string4 = "((9 + 11) / (5 - 3)) * 3 + 7";
		string4 = infixToPrefix(string4);
		std::cout << "Prefix expression: ";
		std::cout << string4 << std::endl;
		std::cout << "Calculated value: ";
		std::cout << evaluatePrefix(string4) << std::endl;

		std::cout << std::endl;
		string5 = "(2 ^ 3 + (50 * 4)) / 4 ^ 2 - 20";
		string5 = infixToPrefix(string5);
		std::cout << "Prefix expression: ";
		std::cout << string5 << std::endl;
		std::cout << "Calculated value: ";
		std::cout << evaluatePrefix(string5) << std::endl;
	}

	catch(std::string& e)
	{
		std::cout << e;
	}

	*/
}
