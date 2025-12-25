class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>next;
        int n=nums2.size();
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            int currele=nums2[i];
            while(!st.empty()&& st.top()<=currele){
                st.pop();
            }
            if(st.empty()){
                next[nums2[i]]=-1;
            }
            else{
                next[nums2[i]]=st.top();
            }
            st.push(currele);
        }
        vector<int>ans;
        for(int i : nums1){
            ans.push_back(next[i]);
        }
        return ans;
    }
};