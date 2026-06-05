class Solution {
public:
    void merge(vector<int>& nums,int low,int mid,int high){
        vector<int>temp;
        int l=low;
        int r=mid+1;
        while(l<=mid && r<=high){
            if(nums[l]<=nums[r]){
                temp.push_back(nums[l]);
                l++;
            }
            else{
                temp.push_back(nums[r]);
                r++;
            }
        }

        while(l<=mid){
            temp.push_back(nums[l]);
            l++;
        }
        while(r<=high){
            temp.push_back(nums[r]);
            r++;
        }

        for(int i=low;i<=high;i++){
            nums[i]=temp[i-low];
        }
    }
    void divide(vector<int>& nums,int low,int high){
        if(low>=high) return;
        int mid=low+(high-low)/2;
        divide(nums,low,mid);
        divide(nums,mid+1,high);

        merge(nums,low,mid,high);
    }
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        divide(nums,0,n-1);
        return nums;
    }
};