class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int cnt=0;
        int p=0,q=0;
        int n = g.size();
        int m=s.size();
        while(p<n && q<m){
            if(s[q]>=g[p]){
                cnt++;
                p++;
            }
            q++;
        }
        return cnt;
       
    }
};