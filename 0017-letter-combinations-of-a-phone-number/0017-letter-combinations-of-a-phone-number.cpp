class Solution {
public:
    void solve(int index,vector<string> &result,string &temp,string &digits,unordered_map<char,string> &mp){
        //store all possible string
        if(index>=digits.length()){
            result.push_back(temp);
            return;
        }
        //take string from map
        char ch=digits[index];
        string str=mp[ch];
        //loop-recursion in str
        for(int i=0 ;i<str.size();i++){
            //pick
            temp.push_back(str[i]);
            solve(index+1,result,temp,digits,mp);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string> mp;
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
        vector<string> result;
        string temp="";
        solve(0,result,temp,digits,mp);
        return result;
    }
};