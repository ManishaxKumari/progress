class Solution {
public:
    bool canpick(vector<int> &v,int num,int k){
        for(auto x :v){
            if(abs(x-num)==k) return false;
        }
        return true;
    }
    
    void solve(vector<int>& nums,vector<int> &v,int index,int k,int &cnt){
        if(index==nums.size()){
            if(!v.empty()){
                cnt++;
            }
            return;
        }
        //pick
        if(canpick(v,nums[index],k)){
            v.push_back(nums[index]);
            solve(nums,v,index+1,k,cnt);
            //backtrack;
            v.pop_back();
        }

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