class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int i = 0, j = 0, curr = 0, mx = 0, n = nums.size();
        while(j < n){
            while ((curr & nums[j]) != 0){
                curr ^= nums[i];
                i++;
            }
            curr |= nums[j];
            mx = max(mx, j - i + 1);
            j++;
        }
        return mx;
    }
};