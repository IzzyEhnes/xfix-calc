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
			Expression();
			Expression(std::string inString);

			Expression operator=(const std::string &inString);
			friend std::ostream& operator<<(std::ostream &out, const Expression &inExpression);

			// Main functions
			//double evaluateInfix(std::string inExpression);
			//double evaluatePostfix(std::string inExpression);
			//double evaluatePrefix(std::string inExpression);

			//Expression infixToPostfix(Expression inExpression);
			//std::string infixToPrefix(std::string inExpression);

			//std::string postfixToInfix(std::string inExpression);
			//std::string prefixToInfix(std::string inExpression);

			//std::string prefixToPostfix(std::string inExpression);
			//std::string postfixToPrefix(std::string inExpression);


			// Helper functions
			//int precedenceCheck(char inOperator);
			//bool isOperator(char inChar);
			//double calculate(double operand1, double operand2, char symbol);
			//std::string reverse(std::string &inExpression);

		private:
			std::string expression;
	};
}

#endif /* XFIX_CALC_H_ */
