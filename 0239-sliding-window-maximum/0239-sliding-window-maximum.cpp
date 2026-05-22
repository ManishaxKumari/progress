class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size(); // this is the size of input array
        vector<int>ans; // this array store ans -> max element of each window
        deque<int>dq; // need to both side operations, we store index in dq
        for(int i=0;i<n;i++){ // now to do traversal of array one by one
            //deque only contain k size element -> when size exceed pop out the element from front
            if(!dq.empty() && dq.front()<=i-k){
                dq.pop_front(); // remove element for maintain size
            }
            while(!dq.empty()&& nums[dq.back()]<=nums[i]){
                dq.pop_back(); // remove smaller element
            }
            dq.push_back(i);
            if(i>=(k-1)){ // store ans at each new window
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};