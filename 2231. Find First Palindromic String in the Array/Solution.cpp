class Solution {
public:
    bool check(string &s) {
        string t = s;
        reverse(t.begin(), t.end());
        return s==t;
    }
    string firstPalindrome(vector<string>& words) {
        for(auto it: words) {
            string s = it;
            if(check(s) == true) {
                return s;
            }
        }
        return "";
    }
};