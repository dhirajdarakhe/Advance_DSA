class Solution {
public:
    int maximalSquare(vector<vector<char>>& mtx) {
       int n = mtx.size();
       int m = mtx[0].size();
        vector<vector<int>> dx(n+1, vector<int>(m+1, 0));
        int mx = 0;
        for(int i=0;i <n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(i==0||j==0)  dx[i][j] = mtx[i][j]-'0';
                else if(mtx[i][j]-'0' == 1) dx[i][j] = min({dx[i-1][j-1], dx[i-1][j], dx[i][j-1]})+1;
                mx = max(dx[i][j], mx);
            }
        }
        return mx*mx;
    }
};
