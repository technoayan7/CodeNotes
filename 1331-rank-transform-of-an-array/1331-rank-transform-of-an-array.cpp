class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        map<int, int> mp;
        for(auto it: arr) mp[it]++;
        int ct = 1;
        for(auto it: mp) mp[it.first] = ct++;
        vector<int> ans(n, 0);
        for(int i=0;i<n;i++) {
            ans[i] = mp[arr[i]];
        }
        return ans;
    }
};