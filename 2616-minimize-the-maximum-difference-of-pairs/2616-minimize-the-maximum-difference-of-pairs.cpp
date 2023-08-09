class Solution {
public:
    bool possible(int mid, int p, vector<int>&nums) {
        int c = 0, i = 0;
        while(i<nums.size()-1 and c<p) {
            if(nums[i+1] - nums[i] <= mid){
                c++;
                i+=2;
            }
            else {
                i++;
            }
        }
        return c>=p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int l = 0, h = nums[n-1] - nums[0], ans = h;
        while(l<=h) {
            int mid = l + (h-l)/2;
            if(possible(mid, p, nums)) {
                h = mid - 1;
                ans = min(ans,mid);
            }
            else {
                l = mid + 1;
            }
        }
        return ans;
    }
};