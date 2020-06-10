/*******************************
 * AUTHOR: Izzy Ehnes          *
 * FILE: xfix-calc.h           *
 * CREATED: March 5, 2019      *
 * LAST MODIFIED: June 8, 2020 *
 ******************************/

#ifndef XFIX_CALC_H_
#define XFIX_CALC_H_

namespace xfix_calc
{
	class Expression
	{
		public:
			// Constructors
			Expression();
			Expression(std::string inString);

			// Overloaded operators
			Expression operator=(const std::string &inString);
			friend std::ostream& operator<<(std::ostream &out, const Expression &inExpression);
			friend Expression operator+(const Expression &inExpression, const std::string &inString);
			Expression operator+=(const std::string &inString);
			friend Expression operator+(const Expression &inExpression, const char &inChar);
			Expression operator+=(const char &inChar);

			// Main functions
			double evaluateInfix();
			double evaluatePostfix();
			//double evaluatePrefix(std::string inExpression);

			Expression infixToPostfix();
			Expression infixToPrefix();

			Expression postfixToInfix();
			Expression prefixToInfix();

			//std::string prefixToPostfix(std::string inExpression);
			//std::string postfixToPrefix(std::string inExpression);


			// Helper functions
			int precedenceCheck(char inOperator);
			bool isOperator(char inChar);
			double calculate(double operand1, double operand2, char symbol);
			Expression reverse(Expression &inExpression);
			std::string reverse(std::string &inString);
			int getLength() const;

		private:
			std::string expression;
	};
}

#endif /* XFIX_CALC_H_ */
