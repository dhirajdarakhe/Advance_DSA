class Solution {
public:
// https://leetcode.com/problems/shortest-bridge/submissions/
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    bool vali(int i , int j ,int n)
    {
        return (min(i, j) >= 0 && max(i,j)<n);
    }
    void f(vector<vector<int>> &grid, int i, int j, int n)
    {
        if(!vali(i, j, n)) return;
        if(grid[i][j] != 1) return;
        grid[i][j] = 2;
        for(int l = 0; l < 4; ++l)
        f(grid, i+dx[l], j+dy[l], n);
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
         for(int i =0;i<n;++i)
         {
             for(int j=0;j<n;++j)
             {
                 if(grid[i][j] == 1)
                 {
                     f(grid, i, j, n);
                     queue<pair<int, int>> q;
                     for(int i1 =0;i1<n;++i1)
                         for(int i2 =0;i2<n;++i2) 
                             if(grid[i1][i2] == 2)  
                                 q.push({i1, i2});
                     while(!q.empty())
                     {
                         pair<int,int> tp = q.front();
                         int ii = tp.first;
                         int jj = tp.second;
                         q.pop();
                         for(int l = 0; l < 4; ++l)
                         {
                            if(!vali(ii+dx[l],jj+dy[l], n)) continue;
                            if(grid[ii+dx[l]][jj+dy[l]] == 1) 
                            {
                                return grid[ii][jj] - 2;
                            }
                            if(grid[ii+dx[l]][ jj+dy[l]] == 0)
                            {
                                grid[ii+dx[l]][ jj+dy[l]] = grid[ii][jj] + 1;
                                q.push({ii+dx[l],jj+dy[l] });
                            }
                        }
                     }
                 }
             }
         }
        // dummy
        return 7;
    }
}; 
