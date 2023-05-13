class Solution {
public:
    void dfs(int node, vector<vector<int>> &gp, vector<int> &ans, vector<vector<int>>&res)
    {
        ans.push_back(node);
        if(ans.back() == gp.size()-1)
        {
            res.push_back(ans);
            ans.pop_back();
            return;
        }
        for(auto child : gp[node])
        {
            dfs(child, gp, ans, res);
        }
        ans.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> ans;
        queue<vector<int>> q;
        q.push({0});
        while(!q.empty())
        {
            vector<int> path = q.front();
            q.pop();
            if(path.back()+1==graph.size())
            {
                res.push_back(path);
                continue;
            }
            for(auto child : graph[path.back()])
            {
                path.push_back(child);
                q.push(path);
                path.pop_back();
            }
        }
        // dfs(0,graph, ans, res);
        return res;
    }
};
