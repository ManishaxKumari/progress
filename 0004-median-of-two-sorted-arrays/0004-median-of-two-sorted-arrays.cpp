class Solution {
public:
    vector<int> merge2sortedarray(vector<int>& nums1, vector<int>& nums2){
        int m=nums1.size();
        int n=nums2.size();
        int p=0;
        int q=0;
        vector<int> ans;
        while(p<m && q<n){
            if(nums1[p]<=nums2[q]){
                ans.push_back(nums1[p]);
                p++;
            }
            else{
                ans.push_back(nums2[q]);
                q++;
            }
        }
        while(p<m){
            ans.push_back(nums1[p]);
            p++;
        }
        while(q<n){
            ans.push_back(nums2[q]);
            q++;
        }
        return ans;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> mergearray= merge2sortedarray(nums1,nums2);
        int n=mergearray.size();
        if(n==1) return mergearray[0];
        if(n%2==1){
            return (double)mergearray[n/2];
        }
        double median=((double)mergearray[n/2]+(double)mergearray[(n/2)-1])/2.0;
        return median;
    }
};