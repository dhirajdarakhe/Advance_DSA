//https://leetcode.com/problems/median-of-two-sorted-arrays/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       if(nums2.size() < nums1.size())  swap(nums1, nums2);
       int l1 = nums1.size();
       int l2 = nums2.size();
       cout<<l1<<" "<<l2<<endl;
       int low = 0;
       int high = l1;
       while(low<=high)
       {
           int cut1 = (low+high)/2;
           int cut2 =  (l1+l2+1)/2-cut1;
           int left1 = cut1==0 ? INT_MIN : nums1[cut1-1];
           int left2 = cut2==0 ? INT_MIN : nums2[cut2-1];
           int right1 = cut1==l1 ? INT_MAX : nums1[cut1];
           int right2 = cut2==l2 ? INT_MAX : nums2[cut2];
           if(left1<=right2&&left2<=right1)
           {
               if((l1+l2)&1)
               {
                   return max(left1, left2);
               }
               else
               {
                   int mx = max(left1, left2);
                   int mn = min(right1, right2);
                   double ans = mx + mn;
                   ans = ans / (2 * 1.0);
                   return ans;
               }
           }
           else
           {
               if(left1 > right2) high = cut1-1;
               else low = cut1 + 1;
           }
           
       }
        return 0.0;
    }
};
