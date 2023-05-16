class Solution {
public:
    int search(vector<int>& nums, int target) {
     
        // https://leetcode.com/problems/search-in-rotated-sorted-array/
        int low = 0; 
        int high = nums.size()-1;
        int mid = (low+high)>>1;
        while(low<=high)
        {
            if(nums[mid] == target) return mid;
            if(nums[low] <= nums[mid])
            {
                if(nums[low] <= target && target <= nums[mid])
                {
                    high = mid -1;
                }
                else
                    
                {
                    low = mid + 1;
                }
            }
            else
            {
                if(nums[mid] <= target && target <= nums[high])
                {
                     low = mid + 1;
                }
                else
                {
                     high = mid -1;
                }
            }
              mid = (low+high)>>1;
        }
      
    return -1;  
    }
};
