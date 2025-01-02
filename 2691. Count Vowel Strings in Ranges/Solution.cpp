class Solution {
public:
    const vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};

    bool isVowel(char c) {
        return find(vowels.begin(), vowels.end(), c) != vowels.end();
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> prefixSum(n + 1);
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + (isVowel(words[i][0]) && isVowel(words[i][words[i].size() - 1]));
        }
        vector<int> res;
        for (auto it : queries) {
            res.push_back(prefixSum[it[1] + 1] - prefixSum[it[0]]);
        }
        return res;
        }
};