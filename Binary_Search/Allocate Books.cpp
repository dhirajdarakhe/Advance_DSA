// https://www.interviewbit.com/problems/allocate-books/

bool f(int mid, vector<int>& A, int b)
{
    int ct = 0;
    int ans = 0;
    for(int i = 0;i < A.size() ; ++i)
    {
        if(A[i] > mid) return 0;
        if(ans + A[i] <= mid) ans+=A[i]; 
        else
        {
            ans=A[i];
            ct++;
        }
    }
    if(ct<b) return 1;
    return 0;
}
int Solution::books(vector<int> &A, int B) {
    
    int low = 0;
    int high = 1e8;
    int ans = INT_MAX;
    if(B>A.size()) return -1;
    while(low<=high)
    {
        int mid = (low+high)/2;
        if(f(mid, A, B))
        {
            ans  = min(mid, ans);
            high  = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}
