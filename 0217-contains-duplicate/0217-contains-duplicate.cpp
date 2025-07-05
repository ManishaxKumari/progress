class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for(auto it : nums){
            if(seen.count(it)){
                return true;
            }
            seen.insert(it);
        }
        return false;
    }
};