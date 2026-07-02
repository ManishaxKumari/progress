class Solution {
public:
    unordered_map<char,string>mp;
    vector<string>ans;

    void solve(string digits,int idx,string &temp){
        if(idx>=digits.size()){
            ans.push_back(temp);
            return;
        }
        char ch=digits[idx]; //2
        string s=mp[ch]; //abc
        for(int i=0;i<s.size();i++){
            temp.push_back(s[i]);
            solve(digits,idx+1,temp);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
        string temp="";
        solve(digits,0,temp);
        return ans;
    }
};