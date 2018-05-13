#include <iostream>
using namespace std;

template <class T>
T rsum(T *a, int n)
{
    if (n > 0)
        return rsum(a, n - 1) + a[n - 1];
}

int main()
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << rsum<int>(a, 10) << endl;
    return 0;
}