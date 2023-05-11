class Solution {
public:
  //https://leetcode.com/problems/find-eventual-safe-states/
    bool dfs(int node, vector<int> & visi, vector<int> &mark, vector<vector<int>> &graph)
    {
        visi[node] = 1;
        mark[node] = 1;
        for(auto child : graph[node])
        {
            if(visi[child] == 0)
            {
                if(dfs(child, visi, mark, graph)) return true;
            }
            else if(visi[child] == 1 && mark[child]) return true;
        }
        mark[node] = 0;
        return 0;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> visi(graph.size()+10, 0);
        vector<int> mark = visi;
        for(int i =0; i < graph.size(); ++i) 
            if(visi[i]==0)
                dfs(i, visi, mark, graph);
        vector<int> ans;
        for(int i=0;i<graph.size();++i)
            if(!mark[i]) ans.push_back(i);
        return ans;
        
    }
};
