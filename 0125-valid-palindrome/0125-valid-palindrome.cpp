class Solution {
public:
    bool isPalindrome(string s) {
        string news="";
        for(char c : s){
            if(isalnum(c)){
                news+=tolower(c);
            }
        }
        return news== string(news.rbegin(),news.rend());
    }
};