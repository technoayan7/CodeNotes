class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        stack<int> st;
        vector<int> nse(n, 0);
        for(int i=n-1;i>=0;i--) {
            while(!st.empty() and st.top() > prices[i]) {
                st.pop();
            }
            nse[i] = st.empty()?prices[i]:prices[i]-st.top();
            st.push(prices[i]);
        }
        return nse;
    }
};