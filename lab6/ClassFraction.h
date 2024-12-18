#ifndef  CLASS_FRACTION
#define CLASS_FRACTION
using namespace std;


    class SimpleFraction
{
private:
    int numerator;//числитель
    int denominator;//знаменатель
    

public:
    int getNumerator();

    void setNumerator(int V_numerator);

    int getDenominator();

    void setDenominator(int V_denominator);

    SimpleFraction() = delete; //запрет вызова конструктора по умолчанию

    SimpleFraction(int num, int det, string c);

   SimpleFraction(const SimpleFraction &p);

void fraction(string c);



int reduction(int v, int u, int &n_, int &d_);


SimpleFraction fract(SimpleFraction& other);

};


#endif