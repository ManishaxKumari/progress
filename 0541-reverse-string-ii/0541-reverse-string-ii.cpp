class Solution {
public:
    void rev(int l,int r,string &str){
        while(l<=r){
            swap(str[l],str[r]);
            l++;
            r--;
        }
    }
    string reverseStr(string s, int k) {
        string str=s;
        int n=str.size();
        int l=0;
        int r=k-1;
        while(l<n && r<n){
            rev(l,r,str);
            l=l+(2*k);
            r=r+(2*k);
        }
        if(l<n){
            rev(l,n-1,str);
        }
        return str;
    }
};