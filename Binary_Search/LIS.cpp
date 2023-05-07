// https://leetcode.com/problems/find-the-longest-valid-obstacle-course-at-each-position/submissions/ 
// nlogn
class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& nums) {
        
        int n = nums.size();
        
        
        vector<int> lis;
        
        
        vector<int> ans;

        for(int i = 0; i < n; i++)
        {
            if(lis.size() == 0 || lis.back() <= nums[i])
            {  
              lis.push_back(nums[i]);
              ans.push_back(lis.size();
            }
            else
            {
                int idx = upper_bound(lis.begin(), lis.end(), nums[i]) - lis.begin();
                ans.push_back(idx + 1);
                lis[idx] = nums[i];
            }
        }
        
        return ans;
    }
};
