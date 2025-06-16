class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int diff = -1;
        int mini= nums[0];

        for(int i=1;i<nums.size();i++){
            if(nums[i] > mini){
                diff = max({nums[i] - mini, diff});
            }
            if(nums[i] < mini){mini = nums[i];}
        }

        return diff;
    }
};