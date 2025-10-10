class Solution {
private:
    int ispossible(vector<int>& nums,int mid){
        int n=nums.size();
        int sum=0;
        int cnt=1;
        for(int i=0;i<n;i++){
            if(sum+nums[i]<=mid){
                sum+=nums[i];
            }
            else{
                cnt++;
                sum=nums[i];
            }
        }
        return cnt;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        if(k>n) return -1;
        if(k==1) return high;
        if(k==n) return low;
        while(low<=high){
            int mid=(low+high)/2;
            int cnt=ispossible(nums,mid);
            if(cnt<=k){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};