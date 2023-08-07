class Solution {
public:
    bool isPalindrome(string s) {
        string str;
        int n = s.size();
        for(auto it: s) {
            if(it >= 'a' and it <='z') {
                str.push_back(it);
            }
            if(it>='A' and it<='Z') {
                str.push_back(tolower(it));
            }
            if(it>='0' and it<='9'){
                str.push_back(it);
            }
        }
        string res = str;
        reverse(res.begin(), res.end());
        return str==res;
    }
};