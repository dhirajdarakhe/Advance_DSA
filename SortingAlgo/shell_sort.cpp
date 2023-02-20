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

1. Time Complexity

 Case	     Time Complexity
Best Case	    O(n*logn)            It occurs when there is no sorting required,
Average Case	O(n*log(n)2)         It occurs when the array elements are in jumbled order
Worst Case   	O(n2)                It occurs when the array elements are in acending and need to be sorted in decending


2. Space Complexity

Space Complexity	O(1)
Stable	NO
Space Complexity	O(1)
Stable	NO
    
 >extended version of insertion sort.
 >it is a comparison-based and in-place sorting algorithm.
 >Shell sort is efficient for medium-sized data sets.
 >In insertion sort, at a time, elements can be moved ahead by one position only. To move an element to a far-away position,
  many movements are required that increase the algorithm's 
  execution time. But shell sort overcomes this drawback of insertion sort. It allows the movement and swapping of far-away elements as well.
> This algorithm first sorts the elements that are far away from each other, 
 then it subsequently reduces the gap between them. This gap is called as interval.
     
