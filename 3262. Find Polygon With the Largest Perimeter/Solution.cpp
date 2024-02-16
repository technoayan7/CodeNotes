class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long p = 0;
        for(auto it: nums)  p += it;
        for(int i=n-1;i>=2;i--) {
            p -= nums[i];
            if(p > nums[i]) {
                return p + nums[i];
            }
        }
        return -1;
    }
};