// Roll NO :- 21118

#include <bits/stdc++.h>
using namespace std;

void insertion_sort(int a[], int size)
{
    int j = 0;
    for (int i = 1; i < size; i++)
    {
        j = i;
        while (j >= 0 && a[j] < a[j - 1])
        {
            swap(a[j], a[j - 1]);
            j--;
        }
    }
}
int main()
{
    int a[] = {1, 6, 4, 3, 2, 5};
    insertion_sort(a, 6);
    for (int i = 0; i < 6; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}
