class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> ans;
        vector<vector<int>> eleIndex;
        for(int i=0;i<n;i++){
            eleIndex.push_back({nums[i],i});
        }
        sort(eleIndex.begin(), eleIndex.end(), [](const vector<int>& a, const vector<int>& b) {
           return a[0] < b[0]; 
        });
        int left = 0, right = n - 1; 
        while (left < right){
            int sum = eleIndex[left][0] + eleIndex[right][0];
             if (sum == target) {
                ans.push_back(eleIndex[left][1]);
                ans.push_back(eleIndex[right][1]);
                return ans;
                
            } else if (sum < target) {
                left++;
                
            } else {
                right--;
                
            }
        }
        return {-1, -1};


    }
};