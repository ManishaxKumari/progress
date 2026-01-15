class Solution {
public:
    string minWindow(string s, string t) {
        int  minlen=INT_MAX;
         int sindex=-1;
         int hash[256]={0};
         for(char c:t){
            hash[c]++;
         }
         int cnt=0;
         int l=0;
         int r=0;
         while(r<s.size()){
            if(hash[s[r]]>0){
                cnt++;
            }
            hash[s[r]]--;
            while(cnt==t.size()){
                if(r-l+1<minlen){
                    minlen=r-l+1;
                    sindex=l;
                }
                hash[s[l]]++;
                if(hash[s[l]]>0){
                    cnt--;
                }
                l++;
            }
            r++;
         }
         return (sindex==-1)? "" : s.substr(sindex,minlen);
    }
};