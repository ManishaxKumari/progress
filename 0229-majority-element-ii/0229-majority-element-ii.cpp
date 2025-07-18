class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int maj1=INT_MIN;
        int maj2=INT_MIN;
        int cnt1=0,cnt2=0;
        for(int i=0;i<n;i++){
            if(nums[i]== maj1){
                cnt1++;
            }
            else if(nums[i]==maj2){
                cnt2++;
            }
            else if(cnt1==0){
                maj1=nums[i];
                cnt1=1;
            }
            else if(cnt2==0){
                maj2=nums[i];
                cnt2=1;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        //verification step
        int freq1=0;
        int freq2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==maj1) freq1++;
            if(nums[i]==maj2) freq2++;
        }
        vector<int>ans;
        int mini=n/3+1;
        if(freq1 >= mini){
            ans.push_back(maj1);
        } 
        if(freq2>=mini && maj1 != maj2){
            ans.push_back(maj2);
        }
        return ans;
        


    }
};