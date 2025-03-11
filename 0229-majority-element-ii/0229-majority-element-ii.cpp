class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
    
    // Extended Moore's Voting Algorithm
    int cnt1 = 0, cnt2 = 0;
    int el1 = INT_MIN, el2 = INT_MIN;
    
    for (int i = 0; i < n; i++) {
        if (cnt1 == 0 && el2 != nums[i]) {
            cnt1 = 1;
            el1 = nums[i];
        } 
        else if (cnt2 == 0 && el1 != nums[i]) {
            cnt2 = 1;
            el2 = nums[i];
        } 
        else if (nums[i] == el1) {
            cnt1++;
        } 
        else if (nums[i] == el2) {
            cnt2++;
        } 
        else {
            cnt1--;
            cnt2--;
        }
    }

    // Second pass to verify actual occurrences
    cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] == el1) cnt1++;
        if (nums[i] == el2) cnt2++;
    }

    int limit = n / 3;
    vector<int> ans;
    if (cnt1 > limit) ans.push_back(el1);
    if (cnt2 > limit && el1 != el2) ans.push_back(el2);  // Avoid duplicates

    return ans;

     
    }
};