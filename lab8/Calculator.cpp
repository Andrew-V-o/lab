#include <stack>
#include <cctype>
#include "Calculator.h"
#include "Stack.h"
using namespace std;

double Calculator::evaluate(const string& expression) {
    if (!isValidExpression(expression)) {
        throw invalid_argument("Invalid expression");
    }
    return evalRPN(infixToRPN(expression));
}

bool Calculator::isValidExpression(const string& expression) {
    int bracketBalance = 0;
    for (char c : expression) {
        if (c == '(') {
            bracketBalance++;
        } else if (c == ')') {
            bracketBalance--;
        }
        if (bracketBalance < 0) {
            return false;
        }
    }
    return bracketBalance == 0 && !expression.empty();
}

int Calculator::precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

string Calculator::infixToRPN(const string& infix) {
    string rpn;
    stack<char> operators;

    for (size_t i = 0; i < infix.length(); ++i) {
        if (isdigit(infix[i])) {
            while (i < infix.length() && (isdigit(infix[i]) || infix[i] == '.')) {
                rpn += infix[i++];
            }
            rpn += ' ';
            --i;
        } else if (infix[i] == '(') {
            operators.push(infix[i]);
        } else if (infix[i] == ')') {
            while (!operators.empty() && operators.top() != '(') {
                rpn += operators.top();
                rpn += ' ';
                operators.pop();
            }
            operators.pop();
        } else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/') {
            while (!operators.empty() && precedence(operators.top()) >= precedence(infix[i])) {
                rpn += operators.top();
                rpn += ' ';
                operators.pop();
            }
            operators.push(infix[i]);
        }
    }

    while (!operators.empty()) {
        rpn += operators.top();
        rpn += ' ';
        operators.pop();
    }

    return rpn;
}

double Calculator::evalRPN(const string& rpn) {
    Stack<double> stack;
    double operand1, operand2;
    for (size_t i = 0; i < rpn.length(); ++i) {
        if (isdigit(rpn[i])) {
            string num;
            while (i < rpn.length() && (isdigit(rpn[i]) || rpn[i] == '.')) {
                num += rpn[i++];
            }
            --i;
            stack << stod(num);
        } else if (rpn[i] == '+' || rpn[i] == '-' || rpn[i] == '*' || rpn[i] == '/') {
            stack >> operand2;
            stack >> operand1;
            switch (rpn[i]) {
                case '+':
                    stack << operand1 + operand2;
                    break;
                case '-':
                    stack << operand1 - operand2;
                    break;
                case '*':
                    stack << operand1 * operand2;
                    break;
                case '/':
                    if (operand2 == 0) {
                        throw runtime_error("Division by zero");
                    }
                    stack << operand1 / operand2;
                    break;
            }
        }
    }
    double result;
    stack >> result;
    return result;
}