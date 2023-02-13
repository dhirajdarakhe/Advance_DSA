// Roll NO :- 21118

#include <bits/stdc++.h>
using namespace std;

void selection_sort(int a[], int size)
{
    int j = 0;
    for (int i = 0; i < size - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < size; ++j)
        {
            if (a[min_index] > a[j])
            {
                min_index = j;
            }
        }
        if (min_index != i)
        {
            swap(a[min_index], a[i]);
        }
    }
}
int main()
{
    int a[] = {1, 6, 4, 3, 2, 5};
    selection_sort(a, 6);
    for (int i = 0; i < 6; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}
