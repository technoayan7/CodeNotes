class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int i=0, j=0, n=nums.size();
        long long ans = 0;
        while(j<n) {
            long long c = 0;
            while(j<n && nums[j] == 0) {
                j++;
                c++;
            }
            ans += (c*(c+1))/2;
            j++;
        }
        return ans;
    }
};