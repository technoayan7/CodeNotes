class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;
        for(auto it: s) {
            if(!st.empty() and st.top()>='a' and st.top()<='z' and it>='0' and it<='9') st.pop();
            else {
                st.push(it);
            }
        }
        string ans;
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};