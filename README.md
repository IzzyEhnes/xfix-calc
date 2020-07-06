# Xfix - An Expression Notation Converter and Calculator
A C++ console program to convert infix, postfix, and prefix notation mathematical expressions into other notations, as well as calculate answers for infix, postfix, and prefix expressions.

## Table of Contents
- [Project Description](#project-description)
- [Technologies](#technologies)
- [Valid Expressions](#valid-expressions)

## Project Description
Provided the expressions are valid (see Valid Expressions section), this program is able to convert an:
- infix expression into a postfix expression
- infix expression into a prefix expression
- postfix expression into an infix expression
- prefix expression into an infix expression
- postfix expression into a prefix expression
- prefix expression into a postfix expression
 
In addition, if the operands are numeric, the evaluateInfix, evaluatePostfix, and
evaluatePrefix functions allow for the evaluation of an expression.

## Technologies
- C++14
- GCC version 7.5.0

## Valid Expressions
A valid Expression has at least one operator and two operands, the number of operator(s) is one less than the number of operands, and must contain only alphanumeric characters, parentheses, spaces, and operators.

This calculator supports the following operators:
- addition (+)
- subtraction (-)
- division (/)
- multiplication (*)
- modulo (%)
- exponential (^)

Spaces may or may not be used to separate operands and operators, but are recommended for readability.
