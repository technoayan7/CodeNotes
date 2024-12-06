class Solution {
public:
    static bool compare(pair<int,int>& a, pair<int,int>& b){
        if(a.first == b.first) return a.second > b.second;
        return a.first < b.first;
    }
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto it: nums) mp[it]++;
        vector<pair<int, int>> p;
        for(auto it: mp) {
            p.push_back({it.second, it.first});
        }
        sort(p.begin(), p.end(), compare);
        vector<int> ans;
        for(auto it: p) {
            int k = it.first;
            while(k--) {
                ans.push_back(it.second);
            }
        }
        return ans;
    }
};