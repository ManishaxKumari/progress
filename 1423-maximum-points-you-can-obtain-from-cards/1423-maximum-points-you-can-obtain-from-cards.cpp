class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int lsum=0,rsum=0,maxsum=0;
        for(int i=0;i<k;i++){
            lsum+=cardPoints[i];
        }
        int l=k-1;
        int r=n-1;
        maxsum=lsum;
        while(l>=0){
            lsum-=cardPoints[l];
            l--;
            rsum+=cardPoints[r];
            r--;
            maxsum=max(maxsum,lsum+rsum);
        }
        return maxsum;
        
        
    }
};