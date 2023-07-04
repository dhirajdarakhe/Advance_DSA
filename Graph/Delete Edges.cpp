#include <bits/stdc++.h>
using namespace std;
 https://www.interviewbit.com/problems/delete-edge/
long long mod = 1e9+7;
long long dfs(long long node, vector<vector<long long>> &gp, vector<long long> &visi, vector<int> &A, vector<long long> &sum)
{
    visi[node] = 1;
    long long child_sum = A[node - 1];
    for (auto child : gp[node])
    {
        if (visi[child])
            continue;
        child_sum = ((child_sum) + dfs(child, gp, visi, A, sum));
    }
    sum[node] = (child_sum);
    return sum[node];
}
int Solution::deleteEdge(vector<int> &A, vector<vector<int>> &B)
{
    long long node_no = A.size();
    vector<vector<long long>> gp(node_no + 10);
    for (auto x : B)
    {
        gp[x[0]].push_back(x[1]);
        gp[x[1]].push_back(x[0]);
    }
    vector<long long> visi(node_no + 10
    , 0);
    long long total = 0;
    vector<long long> sum(node_no + 10);int x1 = 0;
    total = dfs((long long)1, gp, visi, A, sum);
    long long ans  = -1;
    for(int i = 1; i <= node_no; ++i)
    {
        long long child_sum = (sum[i]);
        long long parent = (total - sum[i]);
        long long res = (parent * child_sum);
        ans = max(ans, res);
           
    }
     ans = ans % mod;
return ans;
}
