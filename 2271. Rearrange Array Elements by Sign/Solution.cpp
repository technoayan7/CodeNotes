class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        for(int i=0,j=0,k=1;i<n;i++) {
            if(nums[i]>=0) {
                ans[j]=nums[i];
                j+=2;
            }
            else {
                ans[k]=nums[i];
                k+=2;
            }
        }
        return ans;
    }
};