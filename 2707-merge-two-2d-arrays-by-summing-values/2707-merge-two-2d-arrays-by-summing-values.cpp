class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> ans;
        map<int, int> mp;
        for (auto it : nums1) {
            int a = it[0], b = it[1];
            mp[a] += b;
        }
        for (auto it : nums2) {
            int a = it[0], b = it[1];
            mp[a] += b;
        }
        for(auto it: mp) {
            vector<int> res = {it.first, it.second};
            ans.push_back(res);
        }
        return ans;
    }
};