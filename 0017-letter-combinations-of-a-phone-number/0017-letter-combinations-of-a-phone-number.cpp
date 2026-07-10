class Solution {
public:
    vector<string> ans;
    map<char,string>mpp;

    void solve(string digits,int idx,string str){
        if(idx>=digits.size()){
            ans.push_back(str);
            return;
        }
        char ch=digits[idx];
        string s=mpp[ch];
        for(int i=0;i<s.size();i++){
            str.push_back(s[i]);
            solve(digits,idx+1,str);
            str.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        mpp['2']="abc";
        mpp['3']="def";
        mpp['4']="ghi";
        mpp['5']="jkl";
        mpp['6']="mno";
        mpp['7']="pqrs";
        mpp['8']="tuv";
        mpp['9']="wxyz";

        string str="";
        solve(digits,0,str);
        return ans;

    }
};