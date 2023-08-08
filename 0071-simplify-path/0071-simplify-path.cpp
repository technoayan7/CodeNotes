class Solution {
public:
    string simplifyPath(string s) {
        int n = s.size();
        stack<string> st;
        string str="";
        for(int i=0;i<n;i++) {
            if(s[i]=='/') continue;
            string temp="";
            while(i<n and s[i]!='/') {
                temp+=s[i];
                i++;
            }
            if(temp == ".") continue;
            else if(temp == "..") {
                if(!st.empty()) {
                    st.pop();
                }
            }
            else {
                st.push(temp);
            }
        }
        if(st.size() == 0)  str+="/";
        while(!st.empty()) {
            str = "/" + st.top() + str;
            st.pop();
        }
        return str;
    }
};