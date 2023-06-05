class Solution {
// https://leetcode.com/contest/weekly-contest-348/problems/count-of-integers/
public:
    int mod = 1000000000+7;
    int f(string num, int mn, int mx, int sum, int i, int tight,vector<vector<vector<int>>> &dx)
          {
              if(i == num.size())  return (sum >= mn && sum <= mx);
              if(dx[sum][i][tight] != -1) return dx[sum][i][tight];
              long long ans = 0;
              int st = 0;
              int ed = (tight) ? (num[i] - '0') : 9;
             for(int j = st; j <= ed; ++j)
             {
                 int new_tight = (j == ed && tight == 1) ? 1 : 0;
                 ans += f(num, mn, mx, sum + j, i+1, new_tight, dx);
                 ans %= mod;
             }
           ans %= mod;
           return dx[sum][i][tight] = ans;
          }
    int sumd(string s)
    {
        int ans = 0;
        for(auto x : s) ans += (x - '0');
        return ans;
    }
    int count(string num1, string num2, int min_sum, int max_sum) {
         vector<vector<vector<int>>> dx1(200, vector<vector<int>> (30, vector<int> (5, -1)));
         long long ans = 0;
         ans += f(num2,min_sum,max_sum,0, 0, 1, dx1); 
         cout<<ans<<" ";
         ans %= mod;
         vector<vector<vector<int>>> dx2(200, vector<vector<int>> (30, vector<int> (5, -1)));
         ans -= f(num1,min_sum,max_sum,0, 0, 1, dx2);
         ans %= mod;
         if(sumd(num1) >= min_sum && sumd(num1) <= max_sum) ans++;
         ans %= mod;
         return ans;
    } 
};
