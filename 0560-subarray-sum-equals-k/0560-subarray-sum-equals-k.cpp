class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int sum=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            sum=nums[i];
            if(sum==k)cnt++;
            for(int j=i+1;j<n;j++){
                sum=sum+nums[j];
                if(sum==k) cnt++;
            }
        }
        return cnt;

        
    }
};