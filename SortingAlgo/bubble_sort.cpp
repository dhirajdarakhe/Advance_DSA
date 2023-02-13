// Roll NO :- 21118

#include <bits/stdc++.h>
using namespace std;
void bubble_sort(int a[])
{
    int size = 5;
    for (int i = 0; i < size -1; i++)
    {
       for (int j = 0; j < size -i -1; j++)
       {
           if(a[j] > a[j+1])
           {
               swap(a[j],a[j+1]);
           }
       }
       
    }
    
}
int main()
{

    int a[] = {1, 4, 3, 5, 2};
    bubble_sort(a);
        int size = 5;

    for (int i = 0; i < size; i++)
    {
       cout<<a[i]<<" ";
    }
    
    return 0;
}