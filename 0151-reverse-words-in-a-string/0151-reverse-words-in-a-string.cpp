class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        //reverse whole string
        reverse(s.begin(),s.end()); 
        //reverse the each word
        int i=0;
        while(i<n){
            while(i<n && s[i]==' ') i++;
            int j=i;
            while(j<n && s[j]!=' ') j++;
            reverse(s.begin()+i,s.begin()+j);
            i=j;
        }
       //remove extra spaces->slow and fast pointer
        i=0;
        int j=0;
        
        while(i<n){
            while(i<n && s[i]==' ') i++;
            while(i < n && s[i] != ' '){
                s[j++] = s[i++];
            }
            while(i<n && s[i]== ' ') i++;
            if(i < n) s[j++] = ' ';
        }
        
        s.resize(j);
        return s;
    }
};