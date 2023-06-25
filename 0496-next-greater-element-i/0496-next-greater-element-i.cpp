class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& a) {
        int n = a.size();
        stack<int> st;
        unordered_map<int,int> mp;
        for(int i=n-1;i>=0;i--) {
            while(!st.empty() and st.top()<=a[i]) st.pop();
            int ans = (st.empty()) ? -1 : st.top();
            mp.insert({a[i], ans});
            st.push(a[i]);
        }
        vector<int>ans;
        for(auto x:nums1) { 
            ans.push_back(mp[x]);
        }
        return ans;
    }
};