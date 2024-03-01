class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int c = 0, d = 0;
        for(auto it: s) {
            if(it=='1') c++;
            else d++;
        }
        string ans="";
        for(int i=0;i<c-1;i++) {
            ans += '1';
        }
        for(int i=0;i<d;i++) {
            ans += '0';
        }
        ans += '1';
        return ans;
    }
};