class Solution {
public:
      vector<int> findNSE(vector<int>& arr) {
        int n=arr.size();
        stack<int>st;
        vector<int>ans(n);
        for (int i=n-1;i>=0;i--) {
            while(!st.empty() && arr[st.top()]>=arr[i]) {
                st.pop();
            }
            ans[i]=st.empty() ? n : st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> findPSE(vector<int>& arr) {
        int n = arr.size();
        stack<int>st;
        vector<int>ans(n);
        for (int i=0; i<n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            ans[i]=st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse = findNSE(arr);
        vector<int> pse = findPSE(arr);
        long long mod = 1e9 + 7;
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            long long left = i - pse[i];
            long long right = nse[i] - i;
            sum = (sum + arr[i] * left % mod * right % mod) % mod;
        }
        return sum;
    }
};