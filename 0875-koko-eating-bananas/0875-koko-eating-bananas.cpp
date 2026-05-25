class Solution {
public:
    using ll=long long;
    ll func(vector<int>& piles,int mid){
        int n=piles.size();
        ll sum=0;
        for(int i=0;i<n;i++){
            sum+=ceil((double)piles[i]/(double)mid);
        }
        return sum;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        if(h<piles.size()) return -1;
        while(low<=high){
            int mid=(low+high)/2;
            if((ll)func(piles,mid)<=(ll)h){
                high=mid-1;
            }
            else low=mid+1;
        }
        return low;
    }
};