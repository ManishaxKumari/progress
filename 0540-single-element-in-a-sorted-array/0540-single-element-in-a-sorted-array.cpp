class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            // Check if mid is the single element
            if ((mid == 0 || nums[mid - 1] != nums[mid]) &&
                (mid == n - 1 || nums[mid + 1] != nums[mid])) {
                return nums[mid];
            }

            // Determine which side to search
            if ((mid % 2 == 0 && nums[mid] == nums[mid + 1]) || 
                (mid % 2 == 1 && nums[mid] == nums[mid - 1])) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return nums[low];
    }
};
