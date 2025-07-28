class Solution {
public:
    int cnt = 0;
    void findSubsets(int ind, vector<int> &nums, vector<int> &ds, int &maxOR) {
        if (ind == nums.size()) {
            int tot = 0;
            for(auto it1: ds) {
                tot |= it1;
            }
            if(tot == maxOR) cnt++;
            return;
        }
         
        ds.push_back(nums[ind]);
        findSubsets(ind + 1, nums, ds, maxOR);
        ds.pop_back();

        findSubsets(ind + 1, nums, ds, maxOR);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int maxOR = 0;
        for(int i=0;i<n;i++){
            maxOR = maxOR | nums[i];
        }
        vector<int> ds;
        sort(nums.begin(), nums.end());
        findSubsets(0, nums, ds, maxOR);
        return cnt;
    }
};