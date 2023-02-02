// Time Complexity: O(N log(N)),  
// Auxiliary Space: O(n), 
// for more info https://www.geeksforgeeks.org/merge-sort/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
void merge_sort(vector<int> &v, vector<int> &temp, int low, int mid, int high)
{
    int i = low;
    int j = mid;
    int k = low;
    while (i <= mid - 1 && j <= high)
    {
        if (v[i] < v[j])
            temp[k++] = v[i++];
        else
            temp[k++] = v[j++];
    }
    while (i <= mid - 1)
        temp[k++] = v[i++];
    while (j <= high)
        temp[k++] = v[j++];
    for (int l = low; l <= high; ++l)
        v[l] = temp[l];
}
void merge(vector<int> &v, vector<int> &temp, int low, int high)
{
    if (low >= high)
        return;
    int mid = (low + high) / 2;
    merge(v, temp, low, mid);
    merge(v, temp, mid + 1, high);
    merge_sort(v, temp, low, mid + 1, high);
}
int main()
{
    vector<int> v = {2, 1, 4, 3, 5, 2 , 5 , 9, 6, 8,12};
    int n = v.size();
    vector<int> temp(n);
    cout<<"UnSorted Array : ";
    for (auto x : v)
        cout << x << " ";
    cout << "\n";
    cout<<"  Sorted Array : ";
    merge(v, temp, 0, n - 1);
    for (auto x : v)
        cout << x << " ";
    return 0;
}

// UnSorted Array : 2 1 4 3 5 2 5 9 6 8 12 
//   Sorted Array : 1 2 2 3 4 5 5 6 8 9 12









