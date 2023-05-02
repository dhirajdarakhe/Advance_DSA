class Solution{
    public:
//   https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1
    int kthElement(int nums1[], int nums2[], int n, int m, int k)
    {
       int l1 = n;
       int l2 = m;
    //   cout<<l1<<" "<<l2<<endl;
       int low = max(0,k-l2);
       int high = min(l1, k);
       while(low<=high)
       {
           int cut1 = (low+high)/2;
           int cut2 =  k-cut1;
           int left1 = cut1==0 ? INT_MIN : nums1[cut1-1];
           int left2 = cut2==0 ? INT_MIN : nums2[cut2-1];
           int right1 = cut1==l1 ? INT_MAX : nums1[cut1];
           int right2 = cut2==l2 ? INT_MAX : nums2[cut2];
           if(left1<=right2&&left2<=right1)
           {
                return max(left1, left2);
           }
           else
           {
               if(left1 > right2) high = cut1-1;
               else low = cut1 + 1;
           }
           
       }
    }
};
