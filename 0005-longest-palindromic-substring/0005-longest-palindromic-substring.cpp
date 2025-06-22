class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int low, high;
        int st=0;
        int len = 0;
        for (int i = 0; i < n; i++) {
            low = i;
            high = i+1;
            while (low >= 0 and high < n and s[low] == s[high]) {
                if(high-low+1 > len){
                    st = low;
                    len = high-low+1;
                }
                low--;
                high++;
            }
            low = i;
            high = i;
            while (low >= 0 and high < n and s[low] == s[high]) {
                if(high-low+1 > len){
                    st = low;
                    len = high-low+1;
                }
                low--;
                high++;
            }
        }
        return s.substr(st, len);
    }
};