#ifndef  CLASS_FRACTION
#define CLASS_FRACTION
#include <string>
using namespace std;


    class SimpleFraction
{
private:
    int numerator;//числитель
    int denominator;//знаменатель

public:
    int GetNumerator();

    void SetNumerator(int V_numerator);

    int GetDenominator();

    void SetDenominator(int V_denominator);

    SimpleFraction() = delete; //запрет вызова конструктора по умолчанию

    SimpleFraction(int num, int det);

void fraction();

void operations();

int reduction(int v, int u, int &n_, int &d_);


SimpleFraction fract(SimpleFraction& other);

};


#endif