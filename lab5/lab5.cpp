#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
using namespace std;
int i;
string str;

bool ravny(string str)
{
    for (int i = 0; i < (str.length() - 1); i++)
    {

        if (str[i] != str[i + 1])
        {
            return false;
        }
    }
    return true;
}

bool palindromes(string str)
{

    for (int i = 0; i < ((str.length() - 1) / 2); i++)
    {

        if (str[i] != str[(str.length() - 1) - i])
        {
            return false;
        }
    }

    return true;
}

int main()
{
    SetConsoleOutputCP(65001);
    ofstream fout;

    fout.open("ghf.txt");
    int n;
    cout << "введите количество строк: ";
    cin >> n;
    cin.ignore();

    if (!fout.is_open())
    {
        cout << "Ошибка открытия файла" << endl;
    }

    else
    {
        for (int i = 1; i <= n; i++)
        {
            string str;
            cout << "введите строку: ";
            getline(cin, str);
            fout << str << endl;
        }
    }
    fout.close();
    ifstream fin("ghf.txt");
    ofstream palindromesFile("palindromes.txt");
    ofstream ravnyFile("ravny.txt");

    while (getline(fin, str))
    {
        if (palindromes(str))
        {
            palindromesFile << str << endl;
        }
        if (ravny(str))
        {
            ravnyFile << str << endl;
        }
    }
   palindromesFile.close();
   ravnyFile.close();

}
