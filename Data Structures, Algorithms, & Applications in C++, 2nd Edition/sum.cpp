#include <iostream>
using namespace std;

template <class T>
T sum(T a[], int n)
{
    T theSum = 0;
    for (int i = 0; i < n; i++)
        theSum = a[i] + theSum;
    return theSum;
}

int main()
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << sum<int>(a, 10) << endl;
    return 0;
}