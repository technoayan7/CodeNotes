class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int prev = prices[0], profit = 0;
        for(int i=1;i<n;i++) {
            int cost = prices[i] - prev;
            profit = max(profit, cost);
            prev = min(prev, prices[i]);
        }
        return profit;
    }
};