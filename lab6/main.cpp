#include <iostream>
#include "ClassFraction.h"
#include <string>
using namespace std;

int main(){

    int n;
    cout << "enter the number of fractions (1 or 2) ";
    cin >> n;

    if (n == 1)
    {
        int a1;
        int b1;
        cout << "enter numerator ";
        cin >> a1;
        cout << "enter denominator ";
        cin >> b1;

        SimpleFraction first{a1, b1};
        first.fraction();
    }
    else
    {
        int a1;
        int b1;
        cout << "enter numerator for first fraction ";
        cin >> a1;
        cout << "enter denominator for first fraction ";
        cin >> b1;

        SimpleFraction first{a1, b1};
        first.fraction();

        int a2;
        int b2;
        cout << "enter numerator for second fraction ";
        cin >> a2;
        cout << "enter denominator for second fraction ";
        cin >> b2;

        SimpleFraction second{a2, b2};
        second.fraction();


        SimpleFraction third = first.fract(second);
        third.fraction();
    }
   
}