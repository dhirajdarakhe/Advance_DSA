class Solution {
public:
  //https://leetcode.com/problems/single-element-in-a-sorted-array/
    int singleNonDuplicate(vector<int>& nums) {
        
        int i = 0;
        int j = nums.size()-1;
        int mid = (i + j) / 2;
        while(i<j)
        {
            if(mid&1)
            {
                mid--;
            }
            if(nums[mid] != nums[mid+1])
            {
                j = mid;
            }else
            {
                 i = mid + 2;
            }
            mid = (i + j) / 2;
        }
        return nums[mid];
    }
};
