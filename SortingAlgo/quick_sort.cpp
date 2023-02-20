#include <bits/stdc++.h>
using namespace std;
int partiation(int a[], int l, int h)
{
    int pivot = a[l];
    int i = l, j = h;
    do
    {
        do
        {
            i++;
        } while (pivot >= a[i]);
        do
        {
            j--;
        } while (pivot < a[j]);
        if (i < j)
        {
            swap(a[i], a[j]);
        }
    } while (j > i);
    swap(a[l], a[j]);
    return j;
}
void quick_sort(int a[], int l, int h)
{
    int j;
    if (l < h)
    {
        j = partiation(a, l, h);
        quick_sort(a, l, j);
        quick_sort(a, j + 1, h);
    }
}
int main()
{
    int a[] = {4, 4, 5, 97, 7, 8, 9};
    quick_sort(a, 0, 7);
    for (int i = 0; i < 7; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}



Case	       Time Complexity

Best Case	      O(n*logn)    }
Average Case	  O(n*logn)    } >>> depend upon which element are selected for PIVOT
Worst Case        O(n2)        } 
    
    
    
