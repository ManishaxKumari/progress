class Solution {
public:
    void countpair(vector<int>& nums,int low,int mid,int high , int &cnt){
        int r = mid + 1;

        for(int l = low; l <= mid; l++){
            while(r <= high && (long long)nums[l] > 2LL * nums[r]){
                r++;
            }
            cnt += (r - mid - 1);
        }
    }

    void merge(vector<int>& nums,int low,int mid,int high){
        vector<int> temp;

        int l = low;
        int r = mid + 1;

        while(l <= mid && r <= high){
            if(nums[l] <= nums[r]){
                temp.push_back(nums[l]);
                l++;
            }
            else{
                temp.push_back(nums[r]);
                r++;
            }
        }

        while(l <= mid){
            temp.push_back(nums[l]);
            l++;
        }

        while(r <= high){
            temp.push_back(nums[r]);
            r++;
        }

        for(int i = low; i <= high; i++){
            nums[i] = temp[i - low];
        }
    }

    void divide(vector<int>& nums,int low,int high,int &cnt){
        if(low >= high) return;

        int mid = low + (high - low) / 2;

        divide(nums, low, mid, cnt);
        divide(nums, mid + 1, high, cnt);

        countpair(nums, low, mid, high, cnt);
        merge(nums, low, mid, high);
    }

    int reversePairs(vector<int>& nums) {
        int cnt = 0;
        divide(nums, 0, nums.size() - 1, cnt);
        return cnt;
    }
};