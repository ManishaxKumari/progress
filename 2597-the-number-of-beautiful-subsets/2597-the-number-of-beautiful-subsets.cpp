class Solution {
public:
    bool check(vector<int>&v,int k){
        int n=v.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(abs(v[i]-v[j])==k){
                    return false;
                }
            }
        }
        return true;
    }
    void solve(vector<int>& nums,vector<int> &v,int index,int k,int &cnt){
        if(index==nums.size()){
            if(check(v,k) && !v.empty()){
                cnt++;
            }
            return;
        }
        //pick
        v.push_back(nums[index]);
        solve(nums,v,index+1,k,cnt);
        //backtrack;
        v.pop_back();
        //not pick
        solve(nums,v,index+1,k,cnt);
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        int cnt=0;
        vector<int>v;
        solve(nums,v,0,k,cnt);
        return cnt;
    }
};