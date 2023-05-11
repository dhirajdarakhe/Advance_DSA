// https://leetcode.com/problems/house-robber/
class Solution {
public:
    int rob(vector<int>& n) {
        vector<int> dx(n.size()+1, 0);
        for(int i = 0; i < n.size(); ++i)
        {
            if(i == 0)
            {
                dx[i] = n[i];
            }
            else if( i == 1)
            {
                dx[i] = max(dx[i-1], n[i]);
            }
            else
            {
                dx[i] = max(n[i]+dx[i-2], dx[i-1]);
            }
            
        }
        return dx[n.size()-1];
        
    }
};
