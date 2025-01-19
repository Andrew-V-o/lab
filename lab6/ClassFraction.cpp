#include <iostream>
#include <string>
#include "ClassFraction.h"
using namespace std;

int SimpleFraction::getNumerator()
{
    return numerator;
}
void SimpleFraction::setNumerator(int V_numerator)
{
    numerator = V_numerator;
}
int SimpleFraction::getDenominator()
{
    return denominator;
}
void SimpleFraction::setDenominator(int V_denominator)
{
    denominator = V_denominator;
}

int SimpleFraction::reduction(int v, int u, int &n_, int &d_)
{
    while (v != 0 && u != 0)
    {
        if (v > u)
        {
            v = v % u;
        }
        else
        {
            u = u % v;
        }
    }
    if (v > u)
    {
        if (v > 0)
        {
            n_ = n_ / v;
            d_ = d_ / v;
        }
    }
    else
    {
        if (u > 0)
        {
            n_ = n_ / u;
            d_ = d_ / u;
        }
    }
    return n_ && d_;
}

SimpleFraction::SimpleFraction(int num, int det, string c)
{

    int num_ = num;
    int det_ = det;

    SimpleFraction::reduction(num_, det_, num, det);

    numerator = num;
    denominator = det;
}

SimpleFraction::SimpleFraction(const SimpleFraction &p)
{

    numerator = p.numerator;
    denominator = p.denominator;
}

void SimpleFraction::fraction(string c)
{

    if (denominator == 0)
    {
        cout << "error";
        exit(-1);
    }
    else

    {

        if (c == "-")
        {

            if (numerator >= denominator)
            {
                int value = numerator / denominator;
                int ost = numerator % denominator;

                cout << "-" << value << " " << ost << "|" << denominator << endl;
                numerator = -numerator;
            }
            else
            {
                cout << "-" << numerator << "/" << denominator << endl;
                numerator = -numerator;
            }
        }
        else
        {

            if (numerator >= denominator)
            {
                int value = numerator / denominator;
                int ost = numerator % denominator;

                cout << value << " " << ost << "|" << denominator << endl;
            }
            else
            {
                cout << numerator << "/" << denominator << endl;
            }
        }
    }
}

SimpleFraction SimpleFraction::fract(SimpleFraction &second)
{
    int g;
    int n;
    string m;

    cout << "perform an operation with fractions? (yes - 1, no - 2): ";
    cin >> g;

    if (g == 1)
    {
        string c3;
        int a3;
        int b3;
        cout << "select operation( + , / , * ) ";
        cin >> m;
        char plus = '+';
        char division = '/';
        char multiply = '*';
        if (m[0] == plus)
        {

            a3 = (numerator * second.denominator) + (second.numerator * denominator);
            b3 = denominator * second.denominator;
        }
        else
        {
            if (m[0] == division)
            {
                if (second.numerator == 0)
                {
                    return SimpleFraction(0, 1, "");
                }
                else
                {
                    a3 = numerator * second.denominator;
                    b3 = second.numerator * denominator;
                }
            }
            else
            {
                if (m[0] == multiply)
                {
                    a3 = numerator * second.numerator;
                    b3 = denominator * second.denominator;
                }
                else
                {
                    return SimpleFraction(0, 1, "");
                }
            }

            if (b3 == 0)
            {
                return SimpleFraction(0, 1, "");
            }
        }
        if (b3 < 0 && a3 < 0)
        {
            b3 = -b3;
            a3 = -a3;
        }
        if (b3 > 0 && a3 < 0)
        {
            a3 = -a3;
            c3 = "-";
        }
        if (b3 < 0 && a3 > 0)
        {
            b3 = -b3;
            c3 = "-";
        }

        SimpleFraction third(a3, b3, c3);
        third.fraction(c3);
        return third;
    }
    else
    {
        return SimpleFraction(0, 1, "");
    }
}
