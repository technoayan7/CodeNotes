class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mp;
        int i = 0, j = 0, mx = 0;
        while (j < fruits.size()) {
            mp[fruits[j]]++;
            if (mp.size() > 2) {
                mp[fruits[i]]--;
                if (mp[fruits[i]] == 0) mp.erase(fruits[i]);
                i++;
            }
            if (mp.size() <= 2) {
                mx = max(mx, j - i + 1);
            }
            j++;
        }
        return mx;
    }
};