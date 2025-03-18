class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            int a = nums[i];
            int len = 1;
            for(int j = i+1; j < nums.size(); j++) {
                int b = nums[j];
                if((a + b) == (a xor b)) {
                    a+=b;
                    len++;
                }
                else 
                    break;
            }
            ans = max(ans, len);
        }
        return ans;
    }
};