class Solution {
public:
    int maxSum(vector<int>& a) {
        set<int> u;
        int s = 0;
        for (int x : a) {
            if (x > 0 && !u.count(x)) {
                u.insert(x);
                s += x;
            }
        }
        if (s > 0) return s;
        bool z = 0;
        for (int x : a) {
            if (x == 0)
                z = 1;
        }
        if (z) return 0;
        int mn = -101;
        for (int x : a) {
            if (x < 0) {
                mn = max(mn, x);
            }
        }
        return mn;
    }
};