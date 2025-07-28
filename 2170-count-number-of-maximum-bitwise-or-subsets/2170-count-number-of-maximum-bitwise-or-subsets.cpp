class Solution {
public:
    vector<vector<int>> ans;
    void findSubsets(int ind, vector<int> &nums, vector<int> &ds) {
        if (ind == nums.size()) {
            ans.push_back(ds);
            return;
        }
         
        ds.push_back(nums[ind]);
        findSubsets(ind + 1, nums, ds);
        ds.pop_back();

        findSubsets(ind + 1, nums, ds);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();

        int maxOR = 0;
        for(int i=0;i<n;i++){
            maxOR = maxOR | nums[i];
        }
        vector<int> ds;
        sort(nums.begin(), nums.end());
        findSubsets(0, nums, ds);
        int cnt = 0;
        for(auto it: ans) {
            int tot = 0;
            for(auto it1: it) {
                tot |= it1;
            }
            if(tot == maxOR) cnt++;
        }
        return cnt;
    }
};