class Solution {
public:
    static bool comparator(const vector<int>&a , const vector<int>&b){
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end(),comparator);
        int cnt=1;
        int limit=intervals[0][1];
        for(int i=0;i<n;i++){
            if(intervals[i][0]>=limit){
                cnt++;
                limit=intervals[i][1];
            }
        }
        return n-cnt;

    }
};