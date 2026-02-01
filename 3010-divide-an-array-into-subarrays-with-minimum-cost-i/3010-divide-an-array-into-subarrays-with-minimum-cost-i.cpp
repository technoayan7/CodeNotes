class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        int a = nums[0];
        int mi1 = INT_MAX;
        int mi2 = INT_MAX;
        int ind = 0;
        for(int i=n-1;i>=1;i--) {
            if(nums[i] <= mi1) {
                mi1 = nums[i];
                ind = i;
            }
        }
        int b = mi1;
        for(int i=n-1;i>=1;i--) {
            if(i != ind) {
                if(nums[i] <= mi2) {
                    mi2 = nums[i];
                }
            }
        }
        int c = mi2;
        return a+b+c;
    }
};