 class Solution
{//https://leetcode.com/problems/coin-change/
public:
    int f(vector<int> &c, int a, vector<int> &dx)
    {
        int ans = 1e7 + 9;
        if (a == 0)
            return 0;
        if (a < 0)
            return 1e7 + 9;
        if (dx[a] != -1)
            return dx[a];
        for (auto x : c)
            ans = min(ans, f(c, a - x, dx) + 1);
        return dx[a] = ans;
    }
    int coinChange(vector<int> &c, int a)
    {
        // vector<int> dx(amount+10, -1);
        // int ans = f(coins, amount, dx);
        // if(ans == 1e7+9) return -1;
        vector<int> dx(a + 10, 1e7+10);
        for (int j = 0; j <= a; ++j)
            for (int i = 0; i < c.size(); ++i)
                if (j == 0) dx[j] = 0;
                else  
                    if (j - c[i] >= 0) 
                        dx[j] = min(dx[j], dx[j - c[i]] + 1);
        if(dx[a] == 1e7+10) return -1;
        return dx[a];
    }
};
