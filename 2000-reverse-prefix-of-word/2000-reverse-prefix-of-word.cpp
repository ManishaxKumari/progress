class Solution {
public:
    string reversePrefix(string word, char ch) {
        int l=0;
        int n=word.size();
        int r=-1;
        for(int i=0;i<n;i++){
            if(word[i]==ch){
                r=i;
                break;
            }
        }
        if(r!=-1){
            while(l<r){
            swap(word[l++],word[r--]);
            }
        }
        return word;
    }
};