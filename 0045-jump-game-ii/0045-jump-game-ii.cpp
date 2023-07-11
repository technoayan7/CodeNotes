class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        int end = 0;
        int maxReach = 0;
        for (int i = 0; i < n - 1; i++) {
            maxReach = max(maxReach, i + nums[i]);
            if (i == end) {
                ans++;
                end = maxReach;
            }
        }
        return ans;
    }
};