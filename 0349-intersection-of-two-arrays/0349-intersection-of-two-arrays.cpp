class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1,s2;

        for(auto &x : nums1){
            s1.insert(x);
        }

        for(auto &x : nums2){
            if(s1.find(x) != s1.end()){
                s2.insert(x);
            }
        }

        vector<int> ans (s2.begin(), s2.end());
        return ans;
    }
    
};