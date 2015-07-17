#include <iostream>
using namespace std;

int *get(int * x, int i)
{
    return &x[i];
}
int main()
{
    int arr[10];
    for(int i = 0; i < 10; i++)
        arr[i] = i + 1;

    *get(arr, 0) = 20;
    for(int i = 0; i < 10; ++i)
        cout << *get(arr, i) << endl;
    return 0;
}
