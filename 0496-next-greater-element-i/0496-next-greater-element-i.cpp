class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>next;
        stack<int>st;
        int n2=nums2.size();
        for(int i=n2-1;i>=0;i--){
            int x=nums2[i];
            while(!st.empty() && st.top()<=x ){
                    st.pop();
            }
            if(st.empty()){
                next[nums2[i]]=-1;
            }
            else{
                next[nums2[i]]=st.top();
            }
            st.push(x);

        }
        vector<int>ans;
        for(int i : nums1){
            ans.push_back(next[i]);
        }
        return ans;
    }
};