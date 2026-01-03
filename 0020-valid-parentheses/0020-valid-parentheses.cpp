class Solution {
public:
    bool check(char open,char close){
        if(open == '(' && close == ')'||
        open == '[' && close==']' || 
        open =='{' && close=='}'){
            return true;
        }
        return false;
    }
    bool isValid(string s) {
        stack<char>st;
        for(int i=0 ; i<s.length();i++){
            if(s[i]=='{' || s[i]=='(' || s[i]=='['){
                st.push(s[i]);
            }
            else{
                if(st.empty()) return false;
                char x=st.top();
                if(check(x,s[i])){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }
        return st.empty();

    }
};