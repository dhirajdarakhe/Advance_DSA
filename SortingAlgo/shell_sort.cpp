#include <bits/stdc++.h>
using namespace std;
void shell_sort(int a[], int size)
{
    for (int gap = size / 2; gap >= 1; gap /= 2)
    {
        for (int j = gap; j < size; j++)
        {
            for (int i = j - gap; i >= 0; i -= gap)
            {
                if (a[i] < a[i + gap])
                {
                    break;
                }
                else
                {
                    swap(a[i], a[i + gap]);
                }
            }
        }
    }
}
int main()
{
    int a[] = {5, 6, 1, 3, 8, 7};
    shell_sort(a, 6);
    for (int i = 0; i < 6; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}