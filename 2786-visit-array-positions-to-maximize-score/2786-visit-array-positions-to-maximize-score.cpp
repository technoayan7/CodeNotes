typedef long long ll;
class Solution {
public:
    ll dp[100005][2];
    
    ll fun(int i, bool isOdd, int x, vector<int>& nums) {
        if(i == nums.size()) return 0;
        if(dp[i][isOdd] != -1) return dp[i][isOdd];
        
        ll skip = fun(i+1, isOdd, x, nums);
        ll pick = 0;
        if(nums[i]%2 == isOdd)
            pick = nums[i] + fun(i+1, isOdd, x, nums);
        else
            pick = nums[i] - x + fun(i+1, !isOdd, x, nums);
        
        return dp[i][isOdd] = max(pick, skip);
    }
    
    long long maxScore(vector<int>& nums, int x) {
        memset(dp, -1, sizeof(dp));
        return nums[0] + fun(1, (nums[0] % 2), x, nums);
    }
};