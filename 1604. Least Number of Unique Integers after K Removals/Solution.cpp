class Solution {
public:
    static bool cmp(pair<int, int> a, pair<int, int> b) {
        if (a.second == b.second)
            return a.first > b.first;
        return a.second < b.second;
    }
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        for(auto it: arr) mp[it]++;
        vector<pair<int, int>> v;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            v.push_back({it->first, it->second});
        }
        sort(v.begin(), v.end(), cmp);
        set<int> st;
        vector<int> ans;
        for (int i = 0; i < v.size(); i++) {
            while (v[i].second > 0) {
                ans.push_back(v[i].first);
                v[i].second--;
            }
        }
        for(int i=0;i<ans.size();i++) {
            if(k>0) k--;
            else {
                st.insert(ans[i]);
            }
        }
        return st.size();
    }
};