class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int mx = INT_MIN;
        int sum=0;
        for(int i=0;i<n;i++) {
            sum+=nums[i];
            sum = max(nums[i], sum);
            mx = max(mx, sum);
        }
        return mx;
    }
};