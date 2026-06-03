class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()){
            return findMedianSortedArrays(nums2,nums1);
        }
        int m=nums1.size();
        int n=nums2.size();
        int tLeft=(m+n+1)/2; //totalLeftElement

        int low=0; // either pick 0 element from nums1
        int high=m; // or pick all element from nums1

        //start binary search for choose how many element to pick from nums1 and nums2 for left side of partition
        while(low<=high){
            int p1= low+(high-low)/2 ; //pickFromNums1
            int p2= tLeft-p1; //pickFromNums2 = totalLeftElement - pickFromNums1;

            //lefthalf element -> SMALLER, agar 0 element pick kiya toh
            int x1=(p1==0)? INT_MIN : nums1[p1-1]; //last element of nums1 ,according to 0-indexing , total pick - 1
            int x2=(p2==0) ? INT_MIN : nums2[p2-1];  //last element of nums2

            //right half element-> LARGER
            //agar sare element left half mai le liye toh 
            int x3=(p1==m)?INT_MAX : nums1[p1]; //first element of nums1
            int x4=(p2==n)?INT_MAX :nums2[p2]; //first element of nums2

            if(x1<=x4 && x2<=x3){ //found partition
                if((m+n)%2==1){ //odd lenght
                    return max(x1,x2);
                }
                return (max(x1,x2)+ min(x3,x4))/2.0;
            }

            if(x1>x4) high=p1-1;
            else low=p1+1;

        }

        return -1;


    }
};