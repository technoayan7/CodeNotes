class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int maxi = -1;
        vector<int> pre(n, nums[0]), suff(n, nums[n-1]);
        for(int i=1;i<n;i++) {
            pre[i] = min(pre[i-1], nums[i]);
        }
        for(int i=n-2;i>=0;i--) {
            suff[i] = max(suff[i+1], nums[i]);
        }
        for(int i=1;i<n;i++) {
            maxi = max(maxi, suff[i]-pre[i-1]);
        }
        return maxi<=0?-1:maxi;
    }
};