class Solution {
public:
  // https://leetcode.com/problems/unique-paths-ii/
    int uniquePathsWithObstacles(vector<vector<int>>& d) {
        int n = d.size();
        int m = d[0].size();
        if(d[0][0]==1 || d[n-1][m-1]) return 0;
        for(int i =0; i <n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(d[i][j] == 1) d[i][j] = -1;
                else if(i==0&&j==0) d[i][j] = 1;
                else if(i==0)
                {
                    if(d[i][j-1] == -1) continue;
                    else d[i][j] = d[i][j-1];
                }
                else if(j==0)
                {
                    if(d[i-1][j] == -1) continue;
                    else d[i][j] = d[i-1][j];
                }
                else 
                {
                    int res = 0;
                    if(d[i-1][j] != -1) res+=d[i-1][j];
                     if(d[i][j-1] != -1) res+=d[i][j-1];
                     d[i][j] = res;
                }
            }
        }
        return d[n-1][m-1];
    }
};
