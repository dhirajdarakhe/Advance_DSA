//https://leetcode.com/problems/delete-and-earn
class Solution {
public:
    int deleteAndEarn(vector<int>& n) {
        int mx = *max_element(n.begin(), n.end());
        vector<int>  fre(mx+1, 0);
        for(auto x : n) fre[x]++;
        vector<int> dx(mx+1, 0);
        for(int i = 1; i <= mx; ++i)
        {
            if(i == 1)
            {
                dx[i] = fre[i]*i;
            }
            else
            {
                if(fre[i-1] == 0) dx[i] = dx[i-1] + fre[i] * i;
                else dx[i] = max(dx[i-1], dx[i-2] + fre[i] * i);
            }
        }
        return dx[mx];
    }
};
