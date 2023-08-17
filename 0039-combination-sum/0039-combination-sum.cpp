class Solution {
public:
    vector<vector<int>> ans;
    void findCombination(int ind, int target, vector<int> &arr, vector<int> &ds) {
        if (ind == arr.size()) {
            if (target == 0) {
                ans.push_back(ds);
            }                                   
            return;
        }
        
        // Take -> pick up the element
        if (arr[ind] <= target) {
            ds.push_back(arr[ind]);
            findCombination(ind, target - arr[ind], arr, ds);
            ds.pop_back();
        }

        // notTake
        findCombination(ind + 1, target, arr, ds);

    }
    vector<vector<int>> combinationSum(vector<int>& person, int target) {
        vector<int> ds;
        findCombination(0, target, person, ds);
        return ans;
    }
};