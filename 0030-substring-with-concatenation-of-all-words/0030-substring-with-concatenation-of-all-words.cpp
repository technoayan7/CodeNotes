class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if (words.empty() || s.empty()) return ans;

        int wordLen = words[0].size();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;
        int n = s.size();

        unordered_map<string, int> originalMp;
        for (auto& w : words) originalMp[w]++;

        for (int offset = 0; offset < wordLen; offset++) {
            int left = offset, count = 0;
            unordered_map<string, int> windowFreq;

            for (int right = offset; right + wordLen <= n; right += wordLen) {
                string word = s.substr(right, wordLen);
                if (originalMp.find(word) == originalMp.end()) {
                    // reset
                    windowFreq.clear();
                    count = 0;
                    left = right + wordLen;
                } else {
                    windowFreq[word]++;
                    count++;

                    while (windowFreq[word] > originalMp[word]) {
                        string leftWord = s.substr(left, wordLen);
                        windowFreq[leftWord]--;
                        count--;
                        left += wordLen;
                    }

                    if (count == wordCount) {
                        ans.push_back(left);
                        string leftWord = s.substr(left, wordLen);
                        windowFreq[leftWord]--;
                        count--;
                        left += wordLen;
                    }
                }
            }
        }
        return ans;
    }
};
