class Solution {
public:
   // https://leetcode.com/problems/time-needed-to-inform-all-employees/submissions/
    int dfs(int node, vector<vector<int>> &gp, vector<int> &time, vector<int> &visi)
    {
        visi[node] = 1;
        int ans = 0;
        for(auto child : gp[node])
        {
            if(visi[child]==0)
            {
              ans = max(ans, dfs(child,gp, time, visi));
            }
        }
        ans += time[node];
        return ans;
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& time) {
        vector<vector<int>> graph(n+1);
        for(int i = 0; i < manager.size(); ++i)
        {
           if(manager[i] >= 0) graph[manager[i]].push_back(i);
        }
        vector<int> visi(n+1, 0);
        return dfs(headID, graph, time, visi);
    }
};
