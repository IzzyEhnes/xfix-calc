/*
 * AUTHOR:        Izzy Ehnes
 * FILE:          xfix-calc.h
 * CREATED:       March 5, 2019
 * LAST MODIFIED: June 19, 2020
 *
 * DESCRIPTION:   xfix-calc.h is the header file for the Expression class. An Expression object
 *                consists of a string data member, 'expression,' which represents a mathematical
 *                expression (e.g. "A + B - C").
 *
 *                Provided the expression is valid (see description of isValid function for what
 *                is and is not considered a valid expression form), the class member functions allow
 *                for the conversion of an:
 *
 * 		          - infix expression into a postfix expression
 *                - infix expression into a prefix expression
 *                - postfix expression into an infix expression
 *                - prefix expression into an infix expression
 *                - postfix expression into a prefix expression
 *                - prefix expression into a postfix expression
 *
 *                In addition, if the operands are numeric, the evaluateInfix, evaluatePostfix, and
 *                evaluatePrefix functions allow for the evaluation of an expression.
 *
 * EXAMPLES:
 *                Expression expr1;
 *                expr1 = "A + B"; // infix expression
 *                expr1 = expr1.infixToPostfix();
 *				  // expr1 is now "A B +"
 *
 *				  Expression expr2;
 *				  expr2 = "+ 10 5"; // prefix expression
 *				  expr2 = expr2.evaluatePrefix();
 *				  // expr2 is now 15
 */




#ifndef XFIX_CALC_H_
#define XFIX_CALC_H_

namespace xfix_calc
{
	class Expression
	{
		public:
			// CONSTRUCTORS

			Expression();
			// DESCRIPTION: The default constructor for the Expression class.
			// PRE: None.
			// POST: An empty Expression object has been created.

			Expression(std::string inString);
			// DESCRIPTION: The parameterized constructor for the Expression class.
			// PRE: None.
			// POST: An Expression object has been created from inString.



			// OVERLOADED OPERATORS

			Expression operator=(const std::string &inString);
			// DESCRIPTION: A function that overloads the '=' operator, allowing for the
			//				assignment of Expression objects to other Expression objects
			//              and strings.
			// PRE: None.
			// POST: The calling object is now equal to inString.

			friend std::ostream& operator<<(std::ostream &out, const Expression &inExpression);
			// DESCRIPTION: A function that overloads the stream insertion operator, allowing
			//              for the printing of Expression objects.
			// PRE: None.
			// POST: inExpression has been printed to the screen.

			friend Expression operator+(const Expression &inExpression, const std::string &inString);
			// DESCRIPTION: A function that overloads the addition operator, allowing
			//              for the concatenation of an Expression object and a string.
			// PRE: None.
			// POST: inString has been added to the end of inExpression.

			friend Expression operator+(const Expression &inExpression, const char &inChar);
			// DESCRIPTION: A function that overloads the addition operator, allowing
			//              for the concatenation of an Expression object and a character.
			// PRE: None.
			// POST: inChar has been added to the end of inExpression.

			Expression operator+=(const std::string &inString);
			// DESCRIPTION: A function that overloads the plus equals operator, allowing
			//              for the the concatenation of the calling Expression object
			//              and a string to be assigned to the calling object.
			// PRE: None.
			// POST: inString has been added to the end of inExpression, and the value
			//       has been assigned to inExpression.

			Expression operator+=(const char &inChar);
			// DESCRIPTION: A function that overloads the plus equals operator, allowing
			//              for the the concatenation of the calling Expression object
			//              and a character to be assigned to the calling object.
			// PRE: None.
			// POST: inChar has been added to the end of inExpression, and the value
			//       has been assigned to inExpression.



			// MAIN FUNCTIONS

			double evaluateInfix();
			// DESCRIPTION: The evaluateInfix() function calculates the value of the
			//              calling infix mathematical Expression.
			// PRE: The calling Expression is valid and may only consist of numbers,
			//      operators, parentheses, and spaces. There should be spaces
			//      between the operands and operators so no calculation errors
			//      arise when interpreting multi-digit operands.
			// POST: The answer to the expression has been calculated and returned.

			double evaluatePostfix();
			// DESCRIPTION: The evaluatePostfix() function calculates the value of the
			//              calling postfix mathematical Expression.
			// PRE: The calling Expression is valid and may only consist of numbers,
			//      operators, parentheses, and spaces. There should be spaces
			//      between the operands and operators so no calculation errors
			//      arise when interpreting multi-digit operands.
			// POST: The answer to the expression has been calculated and returned.

			double evaluatePrefix();
			// DESCRIPTION: The evaluatePrefix() function calculates the value of the
			//              calling prefix mathematical Expression.
			// PRE: The calling Expression is valid and may only consist of numbers,
			//      operators, parentheses, and spaces. There should be spaces
			//      between numeric operands and operators so no errors arise when
			//      interpreting multi-digit operands.
			// POST: The answer to the expression has been calculated and returned.

			Expression infixToPostfix();
			// DESCRIPTION: The infixToPostfix() function converts the calling
			//              infix expression into postfix form.
			// PRE: The calling Expression is valid and may only consist of alphanumeric
			//      characters, operators, parentheses, and spaces. There should be spaces
			//      between the operands and operators so no calculation errors arise when
			//      interpreting multi-digit operands.
			// POST: The infix expression has been converted to postfix form and returned.

			Expression infixToPrefix();
			// DESCRIPTION: The infixToPrefix() function converts the calling
			//              infix expression into prefix form.
			// PRE: The calling Expression is valid and may only consist of alphanumeric
			//      characters, operators, parentheses, and spaces. There should be spaces
			//      between the operands and operators so no calculation errors arise when
			//      interpreting multi-digit operands.
			// POST: The infix expression has been converted to prefix form and returned.

			Expression postfixToInfix();
			// DESCRIPTION: The postfixToInfix() function converts the calling
			//              postfix expression into infix form.
			// PRE: The calling Expression is valid and may only consist of alphanumeric
			//      characters, operators, parentheses, and spaces. There should be spaces
			//      between the operands and operators so no calculation errors arise when
			//      interpreting multi-digit operands.
			// POST: The postfix expression has been converted to infix form and returned.

			Expression prefixToInfix();
			// DESCRIPTION: The prefixToInfix() function converts the calling
			//              postfix expression into infix form.
			// PRE: The calling Expression is valid and may only consist of alphanumeric
			//      characters, operators, parentheses, and spaces. There should be spaces
			//      between the operands and operators so no calculation errors arise when
			//      interpreting multi-digit operands.
			// POST: The prefix expression has been converted to infix form and returned.

			Expression prefixToPostfix();
			// DESCRIPTION: The prefixToPostfix() function converts the calling
			//              prefix expression into postfix form.
			// PRE: The calling Expression is valid and may only consist of alphanumeric
			//      characters, operators, parentheses, and spaces. There should be spaces
			//      between the operands and operators so no calculation errors arise when
			//      interpreting multi-digit operands.
			// POST: The prefix expression has been converted to postfix form and returned.

			Expression postfixToPrefix();
			// DESCRIPTION: The postfixToPrefix() function converts the calling
			//              prefix expression into postfix form.
			// PRE: The calling Expression is valid and may only consist of alphanumeric
			//      characters, operators, parentheses, and spaces. There should be spaces
			//      between the operands and operators so no calculation errors arise when
			//      interpreting multi-digit operands.
			// POST: The postfix expression has been converted to prefix form and returned.



			// HELPER FUNCTIONS

			void isValid() const;
			// DESCRIPTION: The isValid() function checks whether the calling Expression
			//              is of valid form or not; a valid Expression has at least one
			//              operator and two operands, the number of operator(s) is one
			//              less than the number of operands, and must contain only alphanumeric
			//              characters, parentheses, spaces, and operators.
			// PRE: None.
			// POST: If the Expression is not valid, a runtime error explaining the cause is thrown.
			//       Otherwise, nothing else happens.

			int precedenceCheck(const char inOperator);
			// DESCRIPTION: The precedenceCheck() function returns the mathematical precedence
			//              of the incoming operator char, inOperator.
			// PRE: None.
			// POST: If inOperator is an '^' (highest precedence), '3' is returned. If inOperator is
			//       an '*', '/', or '%' (lower precedence) then '2' is returned. If inOperator is an
			//       '+', or '-' (lowest precedence), then '1' is returned. Otherwise, '0' is returned.

			bool isOperator(const char inChar) const;
			// DESCRIPTION: The isOperator() function determines if the incoming char, inChar,
			//              is a mathematical operator.
			// PRE: None.
			// POST: If inChar is a '^', '*', '/', '%', '+', or '-', the function returns 'true'.
			//       Otherwise, 'false' is returned.

			double calculate(const double operand1, const double operand2, const char symbol);
			// DESCRIPTION: calculate() is a function that performs a mathematical calculation
			//              using the incoming operands, 'operand1' and 'operand2', and operator,
			//              'symbol'.
			// PRE: The operand 'operand2' cannot be 0 when the operator, 'symbol', is a '/'.
			//      Otherwise, a division by zero error occurs.
			// POST: The answer has been calculated and returned.

			Expression reverse(Expression &inExpression);
			// DESCRIPTION: reverse(Expression &inExpression) is a function that reverses
			//              the incoming Expression inExpression.
			// PRE: None.
			// POST: inExpression has been reversed and returned.

			std::string reverse(std::string &inString);
			// DESCRIPTION: reverse(std::string &inString) is a function that reverses the
			//              incoming string inString.
			// PRE: None.
			// POST: inString has been reversed and returned.

			int getLength() const;
			// DESCRIPTION: getLength() finds the length of the calling Expression.
			// PRE: None.
			// POST: The length of the calling Expression has been calculated and returned.

		private:
			std::string expression;
	};
}

#endif /* XFIX_CALC_H_ */
