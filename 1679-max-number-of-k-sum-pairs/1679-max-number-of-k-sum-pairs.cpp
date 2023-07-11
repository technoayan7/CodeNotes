class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int l=0, h=n-1, c=0;
        while(l<h) {
            if(nums[l] + nums[h] == k) {
                c++;
                nums[l] = 0;
                nums[h] = 0;
                l++;
                h--;
            }
            else if(nums[l] + nums[h] < k) l++;
            else h--;
        }
        return c;
    }
};