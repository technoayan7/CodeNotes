class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        unordered_map<int,int> mp;
        int n = arr.size();
        int ans = 0;

        for(int i=0;i<n;i++) {
            int prev = arr[i] - diff;
            if(mp.count(prev)) {
                mp[arr[i]] = 1 + mp[prev];
            }
            else {
                mp[arr[i]] = 1;
            }
            ans = max(ans, mp[arr[i]]);
        }
        return ans;
    }
};