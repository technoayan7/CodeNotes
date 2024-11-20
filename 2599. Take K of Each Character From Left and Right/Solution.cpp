class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size();
        unordered_map<char, int> mp;
        for (auto it : s) mp[it]++;
        if (mp['a'] < k || mp['b'] < k || mp['c'] < k) return -1;
        int i = 0, j = 0;
        int minLength = n;
        while (j < n) {
            mp[s[j]]--;
            while (i<=j and (mp['a'] < k || mp['b'] < k || mp['c'] < k)) {
                mp[s[i]]++;
                i++;
            }
            minLength = min(minLength, n - (j - i + 1));
            j++;
        }
        return minLength;
    }
};
