class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> mpp; //store frequency
        mpp[0]=1; 
        int cnt=0;
        int prefix=0;
        
        for(auto x : nums){
            prefix+=x;
            cnt+=mpp[prefix-k];
            mpp[prefix]++;
        }
        return cnt;
    }
};