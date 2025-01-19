#ifndef CALCULATOR
#define CALCULATOR
#include <string>
using namespace std;

class Calculator
{
public:
    double evaluate(const string &expression);

private:
    bool isValidExpression(const string &expression);

    int precedence(char op);

    string infixToRPN(const string &infix);

    double evalRPN(const string &rpn);
};

#endif