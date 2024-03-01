class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int c = 0, d = 0;
        for(auto it: s) {
            if(it=='1') c++;
            else d++;
        }
        string ans = string(c - 1, '1') + string(d, '0') + '1';
        return ans;
    }
};