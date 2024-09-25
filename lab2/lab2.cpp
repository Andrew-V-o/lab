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
if (k == 1){
    
    for (int i = 0; i < n; i++)
    {
        std::cout << "enter arr[i]:";
        std::cin >> arr[i] ;
    }
}
if (k == 2){

int a; // нижняя граница
int b; // верхняя граница

std::cout << "lower limit: ";
std::cin >> a;

std::cout << "upper limit";
std::cin >> b;
  
    for (int i = 0; i < n; i++)
    {
        arr[i] = a + rand()%(b-a+1);
    }
     
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] ;
    }
}
if (k < 1 || k > 2){
    std::cout << "error: k=1 or k=2";
    exit(-1);
}

}