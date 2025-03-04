class Solution {
public:
    bool solve(int n, int s, int p) {
        if(n == s) return true;

        if(s > n || pow(3, p) > n) return false;

        if(solve(n, s + pow(3, p), p+1)) return true;

        return solve(n, s, p+1);
    }
    bool checkPowersOfThree(int n) {
        return solve(n, 0, 0);
    }
};