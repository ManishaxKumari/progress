class Solution {
public:
    bool possible(vector<int>& nums,int threshold,int mid){
        int n=nums.size();
        int check=0;
        for(int i=0;i<n;i++){
            check=check+ ceil((double)(nums[i])/(double)(mid));
        }
        return check<=threshold;

    }



    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        if (n >threshold) return -1;
        int low=1;
        int ans=-1;
        int high=*max_element(nums.begin(),nums.end());
        while(low<=high){
            int mid=(low+high)/2;
            if(possible(nums,threshold,mid)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};