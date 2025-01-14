class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        unordered_map<char, int> mp;
        for(int i=0;i<n;i++) {
            mp[s[i]]++;
        }
        int cnt = 0;
        for(auto it: mp) {
            if(it.second == 1 || it.second == 2) {
                cnt  += it.second;
                continue;
            }
            if(it.second%2==0) cnt += 2;
            else cnt += 1;
        }
        return cnt;
    }
};