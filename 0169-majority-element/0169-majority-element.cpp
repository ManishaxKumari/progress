class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int candidates;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(cnt==0){
                candidates=nums[i];
                cnt++;
            }
            else if(nums[i]==candidates){
                cnt++;
            }
            else{
                cnt--;
            }
        }
        return candidates;

    }
};