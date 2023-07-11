class Solution {
public:
    string trim(string s) {
        int x,y;
        for(int i=0;i<s.size();i++) {
            if(s[i]!=' '){ 
                x=i;
                break;
            }
        }
        for(int i=s.size()-1;i>=0;i--) {
            if(s[i]!=' '){ 
                y=i;
                break;
            }
        }
        s=s.substr(x,y-x+1);
        return s;
    }
    int lengthOfLastWord(string s) {
        s = trim(s);
        int n = s.size();
        string ans = "";
        int f = 0;
        for(int i=n-1;i>=0;i--) {
            if(s[i]==' ') {
                f = 1;
                ans = s.substr(i+1);
                break;
            }
        }
        if(f==0) return n;
        return ans.size();
    }
};