class Solution {
public:

   bool possible(vector<int> piles,int hour,int h){
       int n=piles.size();
       long long hr=0;
       for(int i=0;i<n;i++){
         hr=hr+ceil((double)(piles[i])/(double)(hour));
       }
        return hr<=h;
       
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();

        //find low and high
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            maxi=max(piles[i],maxi);
        }
        int low=1;
        int high=maxi;

        //binary serach

        while(low<=high){
            int mid = low + (high - low) / 2;
            
            if(possible(piles,mid,h)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};