int findPeakElement(vector<int> &arr) {
// peak elemnt in array

    // Write your code here
    int n = arr.size();
    if(n==1) return 1;
    if(arr[0] > arr[1]) return  0;
    if(arr[n-1] > arr[n-2]) return n-1;
    int l = 1;
    int h = n-2;
    while(l<h)
    {
        int mid = (l+h)/2;
        if(arr[mid-1]<arr[mid]&&arr[mid]>arr[mid+1]) return mid;
        if(arr[mid]>=arr[mid-1] && arr[mid+1]>=arr[mid]) l=mid+1;
        else h = mid;
    }
return l;

}
