class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxlndex=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i>maxlndex){
                return false;
            }
            maxlndex=max(maxlndex,i+nums[i]);
        }
        return true;
    }
};