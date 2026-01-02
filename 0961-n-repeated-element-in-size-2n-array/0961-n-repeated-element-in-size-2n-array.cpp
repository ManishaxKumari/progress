class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int,int>mpp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        for(auto &i : mpp){
            if(i.second==n/2){
                return i.first;
            }
        }
        return -1;
    }
};