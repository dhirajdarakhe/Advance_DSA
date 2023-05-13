class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int c = grid[0].size()-1;
        int r = 0;
        int ans = 0;
        while(r <  grid.size() && c >= 0)
        {
            if(grid[r][c]<0)
            {
                ans++;
                c--;
                if(c < 0)  ans += grid[0].size() * (grid.size()-r-1);
            }
            else
            {
                r++;
                if(r <  grid.size()) ans += (grid[0].size()-c-1);
            }
        }
        return ans;
    }
};
