class Solution {
    public:
       	bool f(int i, vector<int> &nums, vector<int> &dp, int n) {
            if (i >= n) return 1;
       	    if (dp[i] != -1) return dp[i];
       	    bool two = 0;
       	    bool three = 0;
       	    bool seq = 0;
                
                
       	    if (i+1 < n && nums[i] == nums[i + 1])
       	        two = f(i + 2, nums, dp, n);
                
       	    if (i+2 < n && nums[i] == nums[i + 1] && nums[i + 1] == nums[i + 2])
       	        three = f(i + 3, nums, dp, n);

       	    if (i+2 < n && nums[i] + 1 == nums[i + 1] && nums[i + 1] + 1 == nums[i + 2])
       	        seq = f(i + 3, nums, dp, n);
            
       	    return dp[i] = two || three || seq;
       	
        }
       	bool validPartition(vector<int> &nums) {
       	    int n = nums.size();
       	    vector<int> dp(n, -1);
       	    return f(0, nums, dp, n);
       	}
};