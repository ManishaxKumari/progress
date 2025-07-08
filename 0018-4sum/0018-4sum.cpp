class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>> ans;
        for(int i=0;i<n-3;i++){
            //handle duplicates
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<n-2;j++){
                //handle duplicates
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                int l=j+1;
                int r=n-1;
                while(l<r){
                    long long sum=(long long)nums[i] + (long long)nums[j] + (long long)nums[r] + (long long)nums[l];
                    if(sum<target){
                        l++;
                    }
                    else if(sum>target){
                        r--;
                    }
                    else{
                        vector<int>temp={nums[i],nums[j],nums[l],nums[r]};
                        ans.push_back(temp);
                        //handle duplicates
                        while(l<r && nums[l]==nums[l+1]) l++;
                        while(l<r && nums[r]==nums[r-1]) r--;
                        l++;
                        r--;

                    }
                }
            }
        }
        return ans;
    }
};