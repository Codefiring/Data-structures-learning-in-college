#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

template <class T>
void permutations(T list[], int k, int m)
{
    //generate all the permutations of the list.
    if (k == m)
    {
        copy(list, list + m + 1, ostream_iterator<T>(cout, " "));
        cout << endl;
    }
    else
        for (int i = k; i <= m; i++)
        {
            swap(list[k], list[i]);
            permutations(list, k + 1, m);
            swap(list[k], list[i]);
        }
}

int main()
{
    char ch[] = {'a', 'b', 'c', 'd'};
    permutations<char>(ch, 0, 3);
    return 0;
}