class Solution {
public:
    bool vowel(char x){
        return x=='a' || x=='e' || x=='i'|| x=='o' || x=='u' || x=='A' || x=='E' || x=='I'|| x=='O' || x=='U';
    }
    string reverseVowels(string s) {
        int n=s.size();
        int l=0;
        int r=n-1;
        while(l<r){
            if(vowel(s[l]) && vowel(s[r])){
                swap(s[l++],s[r--]);
            }
            else if(vowel(s[l])){
                r--;
            }
            else{
                l++;
            }
        }
        return s;

    }
};