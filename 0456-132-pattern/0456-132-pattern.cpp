class Solution {
public:
    bool find132pattern(vector<int>& arr) {
        int n=arr.size();
        int mx2 = INT_MIN;
        stack<int>st;
        for(int i=n-1;i>=0;i--)
        {
            if(arr[i] < mx2) return true;
            while(!st.empty() and st.top() < arr[i]) {
                mx2 = max(mx2, st.top());
                st.pop();  
            }
            st.push(arr[i]);
        }
        return false;
    }
};