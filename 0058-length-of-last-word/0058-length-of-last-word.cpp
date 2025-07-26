class Solution {
public:
    int lengthOfLastWord(string s) {
        string str = " " + s + " ";
        int n = str.size();
        int ct = 0;
        for(int i=n-1;i>=0;i--) {
            if(str[i] != ' ') {
                ct++;
                if(str[i-1] == ' ') break;
            }
        }
        return ct;
    }
};