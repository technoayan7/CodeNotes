class Solution {
public:
    int check1(string &s, int x, int y) {
        int n = s.size();
        stack<char> st;
        int cnt = 0;
        for(int i=0;i<n;i++) { 
            if(!st.empty() && st.top() == 'b' and s[i] == 'a') {
                cnt += y;
                st.pop();
            }
            else {
                st.push(s[i]);
            }
        }
        string str = "";
        while(!st.empty()) {
            str += st.top();
            st.pop();
        }
        reverse(str.begin(), str.end());
        s = str;
        return cnt;
    }
    int check2(string &s, int x, int y) {
        int n = s.size();
        stack<char> st;
        int cnt = 0;
        for(int i=0;i<n;i++) {
            if(!st.empty() && st.top() == 'a' and s[i] == 'b') {
                cnt += x;
                st.pop();
            }
            else {
                st.push(s[i]);
            }
        }
        string str = "";
        while(!st.empty()) {
            str += st.top();
            st.pop();
        }
        reverse(str.begin(), str.end());
        s = str;
        return cnt;
    }
    int maximumGain(string s, int x, int y) {
        int tot = 0;
        if(y > x) tot += check1(s,x,y) + check2(s,x,y);
        else tot += check2(s,x,y) + check1(s,x,y);
        return tot;
    }
};