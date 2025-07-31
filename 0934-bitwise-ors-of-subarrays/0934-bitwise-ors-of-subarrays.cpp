class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int> ans, st;
        for (auto it : arr) {
            unordered_set<int> st1;
            st1.insert(it);
            for(auto it1: st) {
                st1.insert(it1 | it);
            }
            st = st1;
            ans.insert(st.begin(), st.end());
        }
        return ans.size();
    }
};