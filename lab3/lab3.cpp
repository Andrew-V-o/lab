#include <iostream>
#include <cmath>
#include <vector>
#include <windows.h>
using namespace std;

bool correct_size(int a)
{
    if (a < 0 || a > 10)
    {
        cout << "значения не корректны";
        return false;
    }
    else
    {
        cout << "значения корректны";
        return true;
    }
}

void mat(vector<vector<int>> &matrix, int a)
{
    for (int i = 0; i < a; ++i)
    {
        for (int j = i; j < a; ++j)
        {
            cout << "введите элементы матрицы [" << i << "] [" << j << "] ";
            cin >> matrix[i][j];
            matrix[j][i] = matrix[i][j];
        }
    }
}

void print_mat(vector<vector<int>> &matrix, int a)
{
    for (int i = 0; i < a; ++i)
    {
        for (int j = 0; j < a; ++j)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}
bool loc_max(vector<vector<int>> &matrix, int i, int j, int a)
{
    int b = matrix[i][j];
    for (int c = max(0, i - 1); c <= min(a - 1, i + 1); ++c)
    {
        for (int d = max(0, j - 1); d <= min(a - 1, j + 1); ++d)
        {
            if ((c != i || d != j) && matrix[c][d] >= b)
            {
                return false;
            }
        }
    }
    return true;
}

pair<int, pair<int, int>> max_loc_max(vector<vector<int>> &matrix, int a)
{
    int max_value = INT_MIN;
    pair<int, int> max_coords = {-1, -1};

    for (int i = 0; i < a; ++i)
    {
        for (int j = 0; j < a; ++j)
        {
            if (loc_max(matrix, i, j, a))
            {
                if (matrix[i][j] > max_value)
                {
                    max_value = matrix[i][j];
                    max_coords = {i, j};
                }
            }
        }
    }
    return {max_value, max_coords};
}
int below_second_diag(const vector<vector<int>> &matrix, int a)
{
    int product = 1;
    for (int i = 0; i < a; ++i)
    {
        for (int j = a - i; j < a; ++j)
        {
            product *= matrix[i][j];
        }
    }
    return product;
}

int main()
{
    SetConsoleOutputCP(65001);
    int a; // количество строк и столбцов
    cout << "введите количество строк и столбцов: ";
    cin >> a;

    if (!correct_size(a))
    {
        return 0;
    }
    vector<vector<int>> matrix(a, vector<int>(a));

    mat(matrix, a);

    print_mat(matrix, a);

    auto M = max_loc_max(matrix, a);

    cout << "максимальный локальный максимум: " << M.first << " на позиции (" << M.second.first << ", " << M.second.second << ")" << endl;

    int Diag = below_second_diag(matrix, a);
    cout << "произведение элементов ниже побочной диагонали, не включая диагональ: " << Diag << endl;

}