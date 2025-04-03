class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        int mx = INT_MIN;
        vector<int> pre(n), post(n);

        for (int i = 0; i < n; i++) {
            mx = max(mx, nums[i]);
            pre[i] = mx;
        }

        mx = INT_MIN;

        for (int i = n - 1; i >= 0; i--) {
            mx = max(mx, nums[i]);
            post[i] = mx;
        }

        long long ans = 0; 

        for (int i = 1; i < n-1; i++) {
            long long s = (long long)(pre[i-1] - nums[i]) * post[i+1];
            ans = max(ans, s);
        }
        return ans;
    }
};
