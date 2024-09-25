#include <iostream>
#include <cmath>

const int max_n = 1000;
int main()
{
    int n; // число элементов массива
    int arr[max_n];

    std::cout << "enter array size: ";
    std::cin >> n;
    std::cout << std::endl;
    if (n > max_n)
    {
        std::cout << "max size must be < " << max_n;
        exit(-1);
    }

    int k;
    std::cout << "method of filling an array: 1 - manually, 2 - randomly: ";
    std::cin >> k;
    if (k == 1)
    {

        for (int i = 0; i < n; i++)
        {
            std::cout << "enter arr[i]:";
            std::cin >> arr[i];
        }
    }
    if (k == 2)
    {

        int a; // нижняя граница
        int b; // верхняя граница

        std::cout << "lower limit: ";
        std::cin >> a;

        std::cout << "upper limit: ";
        std::cin >> b;

        for (int i = 0; i < n; i++)
        {
            arr[i] = a + rand() % (b - a + 1);
        }

        for (int i = 0; i < n; i++)
        {
            std::cout << arr[i] << " ";
        }
    }
    if (k < 1 || k > 2)
    {
        std::cout << "error: k=1 or k=2";
        exit(-1);
    }
    int first_0 = -1;  // первый ноль еще не найден
    int second_0 = -1; // второй ноль еще не найден
    bool two_0 = false;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            if (first_0 == -1)
            {
                first_0 = i;
            }
            else
            {
                second_0 = i;
                two_0 = true;
                break;
            }
        }
    }
    if (two_0 == true)
    {
        int result = 1;
        for (int i = first_0 + 1; i < second_0; i++)
        {
            result = result * arr[i];
        }
        std::cout << std::endl;
        std::cout << "product: " << result;
    }
    else
    {
        std::cout << "there are no 0 in the array or there are only one 0 in the array";
    }
    int v = 0; // количество пермен знака
    int l = (arr[0] >= 0) ? 1 : -1;
    for (int i = 1; i < n; i++)
    {
        int y = (arr[i] >= 0) ? 1 : -1;
        if (y != l)
        {
            v = v + 1;
            y = l;
        }
    }
    std::cout << std::endl;
    std::cout << "number of sign chanches: " << v;
    std::cout << std::endl;
    int j = 0;
    int p;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0)
        {

            p = arr[j];
            arr[j] = arr[i];
            arr[i] = p;

            j++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
}
