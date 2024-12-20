class Solution {
public:
    bool possible(vector<int>& bloomDay,int m,int k,int mid){
        int n=bloomDay.size();
        int cnt=0;
        int bouq=0;
        for(int i=0;i<n;i++){
            if(bloomDay[i]<=mid){
                cnt++;
            }
            else{
                bouq=bouq+(cnt/k);
                cnt=0;
            }
        }
        bouq=bouq+(cnt/k);
        return bouq>=m;

    }


    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if((long long)(m)*(long long)(k) > n ) return -1;
        //min and max ele
        int low=*min_element(bloomDay.begin(),bloomDay.end());
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        int ans=-1;
       

        while(low<=high){
            int mid=(low+high)/2;
            if(possible(bloomDay,m,k,mid)){
                ans=mid;
                //try for smaller day
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};