class Solution {
    public:
       	bool f(int i, vector<int> &nums, vector<int> &dp) {
            if (i < 0) return 1;
       	    if (dp[i] != -1) return dp[i];
       	    bool two = 0;
       	    bool three = 0;
       	    bool seq = 0;
                
                
       	    if (i >= 1 && nums[i] == nums[i - 1])
       	        two = f(i - 2, nums, dp);
                
       	    if (i >= 2 && nums[i] == nums[i - 1] && nums[i - 1] == nums[i - 2])
       	        three = f(i - 3, nums, dp);

       	    if (i >= 2 && nums[i] == nums[i - 1] + 1 && nums[i - 1] == nums[i - 2] + 1)
       	        seq = f(i - 3, nums, dp);
            
       	    return dp[i] = two || three || seq;
       	
        }
       	bool validPartition(vector<int> &nums) {
       	    int n = nums.size();
       	    vector<int> dp(n, -1);
       	    return f(n - 1, nums, dp);
       	}
};