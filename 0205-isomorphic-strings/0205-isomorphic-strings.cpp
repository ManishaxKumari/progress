class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> m,y;
        if(s.size()!=t.size())return false;
        for(int i=0;i<s.size();i++){
            if(m.find(s[i])==m.end() && y.find(t[i])==y.end()){
                m[s[i]]=t[i];
                y[t[i]]=s[i];
            }else if (m[s[i]]!=t[i] && y[t[i]]!=s[i]){
                return false;
            }
        }
        return true;
    }
};