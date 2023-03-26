class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& n) {
      int target = 0;
          sort(n.begin(), n.end());
        vector<vector<int>> ans;
        for(int i = 0; i < n.size(); ++i)
        {
            if( i == 0 || i > 0 && n[i-1] != n[i])
            {
                int lo  = i+ 1;
                int hg = n.size() - 1;
                int sum = target - n[i];
                while(lo < hg)
                {
                    if(n[lo]+n[hg] == sum)
                    {
                        vector<int> temp = {n[lo], n[hg], n[i]};
                        sort(temp.begin(), temp.end());
                        ans.push_back(temp);
                        lo++;
                        hg--;
						while(lo<n.size()&&n[lo]==n[lo-1]) lo++;
						while(hg>lo&&n[hg]==n[hg+1]) hg--;

                    }else if(n[lo]+n[hg] < sum) lo++;
                    else hg--;
                }
            }
        }
        return ans; 
    }
};