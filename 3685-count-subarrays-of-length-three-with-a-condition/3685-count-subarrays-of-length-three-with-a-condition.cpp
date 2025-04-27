class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size(), c = 0;
        for (int i = 1; i < n - 1; i++) {
            if (nums[i - 1] + nums[i + 1] == nums[i] / 2.0) c++;
        }
        return c;
    }
};