class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        unordered_map<char,int>mps,mpt;
        for(int i=0;i<s.size();i++){
            mps[s[i]]++;
            mpt[t[i]]++;
        }
        return mps==mpt;

    }
};