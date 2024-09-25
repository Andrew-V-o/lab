#include <iostream>
#include <cmath>
#include <iomanip>
    
    double logarifm(double x) {
    return log(x + 1);
}

double teylorSeries(double x, int k)
{
    double epsilon = pow(10, -k);
    std::cout << "epsilon = " << epsilon << std::endl;

    bool r = false;

    int v = 1;
    double result = 0;
    double y = 0; // слагаемое
    do
    {
        y = pow(x, v) / v;
        if (r)
        {
            result = result - y;
        }
        else
        {
            result = result + y;
        }

        v = v + 1;
        r = !r;
    } while (abs(y) > epsilon);

    return result;
}

int main()
{
    int k;// "натуральное k"
    double x;// переменная x
    std::cout << "enter x (x>-1 and x<=1)";
std::cin >> x;
if (x <= -1)
    {
        std::cout << "error: x <= -1" << std::endl;
        exit(-1);
    }

    if (x > 1)
{
    std::cout << "error: x > -1" << std::endl;
    exit(-1);
}
std::cout << "enter k (k>1)";
std::cin >> k;
if (k<1)
    {
        std::cout << "error: k <1" << std::endl;
        exit(-1);
    }


double log_result = logarifm(x);
std::cout <<"logarifm:" << std::fixed << std::setprecision(3) << log_result << std::endl;

double teylorResult = teylorSeries(x, k);
std::cout << "teylorSeries:" << std::fixed << std::setprecision(3) << teylorResult << std::endl;
}