class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> b(banned.begin(), banned.end());
        int count = 0;
        for (int i = 1; i <= n; i++) {
            if (b.count(i)) 
            {
                continue;
            }
            if (i <= maxSum) 
            {
                count++;
                maxSum -= i;
            } 
            else 
            {
                break;
            }
        }
        return count;
    }
};