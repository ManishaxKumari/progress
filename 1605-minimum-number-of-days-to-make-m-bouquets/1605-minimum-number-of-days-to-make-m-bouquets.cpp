class Solution {
private:
    bool ispossible(int mid,vector<int>& bloomDay,int m,int k){
        int n=bloomDay.size();
        int cnt=0;
        int res=0;
        for(int i=0;i<n;i++){
            if(bloomDay[i]<=mid){
                cnt++;
            }
            else if(cnt>0){
                cnt=0;
            }
            if(cnt==k){
                res++;
                cnt=0;
            }
        }
        return res>=m;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low=*min_element(bloomDay.begin(),bloomDay.end());
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        if((long long)m*(long long)k>bloomDay.size()) return -1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(ispossible(mid,bloomDay,m,k)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;



    }
};