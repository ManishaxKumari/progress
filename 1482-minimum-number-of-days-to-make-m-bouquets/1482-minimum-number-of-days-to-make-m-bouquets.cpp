class Solution {
public:
    int func(vector<int>& bloomDay,int mid,int k){
        int sum=0;
        int cnt=0;
        int n=bloomDay.size();
        for(int i=0;i<n;i++){
            if(bloomDay[i]<=mid){
                cnt=cnt+1;
            }
            else{
                cnt=0;
            }
            if(cnt==k){
                sum+=cnt;
                cnt=0;
            }
        }
        return sum;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low=1;
        int n=bloomDay.size();
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        if((long long)m*k > n) return -1;
        if(k>n || k<1) return -1;
        while(low<=high){
            int mid=(low+high)/2;
            if((long long)func(bloomDay,mid,k)>=((long long )m*k)){
                high=mid-1;
            }
            else low=mid+1;
        }
        return low;
    }
};