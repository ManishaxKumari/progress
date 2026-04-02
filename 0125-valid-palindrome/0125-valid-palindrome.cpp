class Solution {
public:
    bool isPalindrome(string s) {
       int n=s.size();
       int j=0;
       for(int i=0;i<n;i++){ //remove all special char and change case into lower
        if(isalnum(s[i])){
            s[j++]=tolower(s[i]);
        }
       }
       s.resize(j);
       string rev=s;
       reverse(rev.begin(),rev.end());
       return s==rev;



    }
};