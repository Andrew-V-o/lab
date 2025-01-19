#include <iostream>
#include "Stack.h"
#include "Calculator.h"
using namespace std;

int main() {
    Calculator calc;
    string expression;
    cout << "Enter expression: ";
    getline(cin, expression);

    try {
        double result = calc.evaluate(expression);
        cout << "Result: " << result << endl;
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}