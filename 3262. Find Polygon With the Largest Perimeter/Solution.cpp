class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        int sides = n;
        sort(nums.begin(), nums.end());
        long long p = 0;
        for(auto it: nums)  p += it;
        for(int i=n-1;i>=2;i--) {
            if(p <= 2*nums[i]) {
                p -= nums[i];
                sides--;
            }
            else break;
        }
        if(sides == 2) return -1;
        return p;
    }
};