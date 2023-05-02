// https://www.interviewbit.com/problems/matrix-median/

// #include <bits/stdc++.h>
int Solution::findMedian(vector<vector<int> > &A) {
    int h = 1e9+7;
    int l = 1;
    int mid = (h+l) / 2;
    while(l<=h)
    {
        mid = (h+l) / 2;
        int ct = 0;
        for(int i = 0; i < A.size(); ++i)
           ct += upper_bound(A[i].begin(), A[i].end(), mid) - A[i].begin();
        if(ct <= (A[0].size()*A.size()) / 2) l = mid + 1;
        else h = mid - 1;
        
    }
    return l;
    
    
}
