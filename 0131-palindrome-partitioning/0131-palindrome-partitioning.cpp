class Solution {
public:
    vector<vector<string>> ans;
    bool isPalindrome(string s, int start, int end) {
        while (start <= end) {
            if (s[start++] != s[end--])
                return false;
            }
        return true;
    }
    
    void partitionHelper(int ind, string s, vector<string> &path) {
        if (ind == s.size()) {
            ans.push_back(path);
            return;
        }
        for (int i = ind; i < s.size(); i++) {
            if (isPalindrome(s, ind, i)) {
                path.push_back(s.substr(ind, i - ind + 1));
                partitionHelper(i + 1, s, path);
                path.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<string> path;
        partitionHelper(0, s, path);
        return ans;
    }
};