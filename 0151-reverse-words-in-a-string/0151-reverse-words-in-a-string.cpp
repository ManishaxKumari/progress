class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        stack<string> st;
        int i=0;
        while(i<n){
            while(i<n && s[i]==' ')i++;
            if(i>=n) break;
            int j=i;
            while(j<n && s[j]!=' ') j++;
            st.push(s.substr(i,j-i));
            i=j;
        }
        string ans="";
        while(!st.empty()){
            ans=ans+st.top();
            st.pop();
            if(!st.empty()) ans+=" ";
        }
        return ans;
        }
};