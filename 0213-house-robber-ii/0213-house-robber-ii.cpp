class Solution {
public:
    int rob1(vector<int>& A, vector<int>& dp1, int i) {
        if(i >= size(A) - 1) return 0;
        if(dp1[i] != -1) return dp1[i];
        int notTake = 0 + rob1(A, dp1, i+1);
        int take = A[i] + rob1(A, dp1, i+2);
        return dp1[i] = max(notTake, take);
    }
    
    int rob2(vector<int>& A, vector<int>& dp2, int i) {
        if(i >= size(A)) return 0;
        if(dp2[i] != -1) return dp2[i];
        int notTake = 0 + rob2(A, dp2, i+1);
        int take = A[i] + rob2(A, dp2, i+2);
        return dp2[i] = max(notTake, take);
    }
    
    int rob(vector<int>& A) {
        vector<int> dp1(size(A), -1);
        vector<int> dp2(size(A), -1);
        int ans1 = rob1(A, dp1, 0);
        int ans2 = rob2(A, dp2, 1);
        if(A.size() == 1) return A[0];
        return max(ans1, ans2);
    }
};