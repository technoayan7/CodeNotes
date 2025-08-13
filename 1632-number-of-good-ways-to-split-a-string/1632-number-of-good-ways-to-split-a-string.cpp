class Solution {
public:
    int numSplits(string s) {
        unordered_set<char> a, b;
        unordered_map<int, int> mp;
        int cnt = 0;
        for (auto it : s) {
            mp[it - 'a']++;
            b.insert(it);
        }

        for (auto it : s) {
            a.insert(it);
            mp[it - 'a']--;
            if (mp[it - 'a'] == 0)
                b.erase(it);
            if (a.size() == b.size())
                cnt++;
        }
        return cnt;
    }
};