class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxReach = 0;
        if(n==1) return true;
        for (int i = 0; i < n; i++) {
            if(i > maxReach) return false;
            int jump = i + nums[i];
            if(jump >= maxReach) {
                maxReach = jump;
            }
            if(maxReach >= n-1) return true;
        }
        return false;
    }
};