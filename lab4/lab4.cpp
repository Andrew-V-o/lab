#include <iostream>
#include <cmath>
#include <windows.h>
#include <cstring>
#include <stdlib.h>
using namespace std;

char symbols[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

char *func(int value, char *string, int radix)
{

    int i = 0;
    do
    {
        int a = value % radix;
        value = value / radix;
        string[i] = symbols[a];
        i++;

    } while (value > 0);
    string[i] = 0;
    int j = 0;
    i--;
    while (j < i)
    {
        int x = string[i];
        string[i] = string[j];
        string[j] = x;
        j++;
        i--;
    }
    return string;
}

int char_count(char *s)
{
    int chars[256];

    for (int i = 0; i < 256; i++)
    {
        chars[i] = 0;
    }
    while (*s != 0)
    {
        chars[*s] = 1;
        s++;
    }
    int result = 0;

    for (int i = 0; i < 256; i++)
    {
        result += chars[i];
    }
    return result;
}
void the_longest_word(char *s)
{
    bool space = true;
    int max = 0;
    int first = 0; // первый символ
    int last = 0;
    int j = 0; // индекс первой буквы текущего слова
    for (int i = 0;; i++)
    {

        if (s[i] == ' ' || s[i] == 0)
        {
            if (!space)
            {
                char old = s[i];
                s[i] = 0;
                int x = char_count(&s[j]);
                if (x >= max)
                {
                    max = x;
                    first = j;
                    last = i;
                }

                s[i] = old;
                space = true;
            }
            j = i + 1;
        }
        else
        {
            space = false;
        }
        if (s[i] == 0)
        {
            break;
        }
    }
    cout << "наибольшее количество различных символов: " << max << endl;
    s[last] = 0;
    cout << "слово с наибольшим количеством различных символов: " << &s[first] << endl;
}

int main()
{
    // A

    char string[4096];
    int value;
    int radix;
    cout << "введите систему счисления(от 2 до 36): ";
    cin >> radix;
    if (radix < 2 || radix > 36)
    {
        cout << "система счисления должна быть от 2 до 36";
        return 0;
    }
    cout << "введите исходное число: ";
    cin >> value;

    SetConsoleOutputCP(65001);
    char *b = func(value, string, radix);
    cout << "преобразованное число " << value << " в строку в " << radix << "-ричной системе счисления: " << b;

    // B

    char s[300];
    cout << "введите строку, состоящую из слов и пробелов между ними: ";
    gets_s(s);
    the_longest_word(s);
}
