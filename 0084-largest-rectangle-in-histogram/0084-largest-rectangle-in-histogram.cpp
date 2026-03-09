class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int>st;
        int maxarea=0;
        int area,nse,pse;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                nse=i;
                int ind=st.top();
                st.pop();
                pse=st.empty() ? -1 : st.top();
                area=heights[ind]*(nse-pse-1);
                maxarea=max(maxarea,area);
            }
            st.push(i);
        }
        while(!st.empty()){
            nse=n;
            int ind=st.top();
            st.pop();
            pse=st.empty()?-1 : st.top();
            area=heights[ind]*(nse-pse-1);
            maxarea=max(maxarea,area);
        }
        return maxarea;
    }
};