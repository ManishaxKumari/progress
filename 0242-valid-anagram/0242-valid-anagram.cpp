class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> mps,mpt;
        for(int i=0;i<s.size();i++){
            mps[s[i]]++;
        }
        for(int i=0;i<t.size();i++){
            mpt[t[i]]++;
        }
        return mps==mpt;
    }
};