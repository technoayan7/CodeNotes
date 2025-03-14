class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int s = 1, e = 1e9, ans = 0;
        while(s <= e) {
            long m = s + (e - s) / 2;
            long sum = 0;
            for(int i : candies) {
                sum +=  (i / m);
            }
            if (sum >= k)
                s = m + 1, ans = m;
            else
                e = m - 1;
        }
        return ans;
    }
};
