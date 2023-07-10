class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int left[n], right[n];
        int sum=0;
        for(int i=n-1;i>=0;i--) {
            sum+=nums[i];
            right[i] = sum;
            
        }
        sum=0;
        for(int i=0;i<n;i++) {
            sum+=nums[i];
            left[i] = sum;
            if(left[i] == right[i]) return i;
        }
        return -1;
    }
};