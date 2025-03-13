class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> updates(n + 1,0); 
        int currentDecrement = 0;
        int queryIndex = 0;

        for (int i = 0; i < n; i++) {
            currentDecrement += updates[i]; 

            while (nums[i] > currentDecrement && queryIndex < queries.size()) {
                vector<int>& q = queries[queryIndex];
                int left = q[0], right = q[1], decrement = q[2];

                updates[left] += decrement;
                if (right + 1 < n) {
                    updates[right + 1] -= decrement;
                }

                if (left <= i && i <= right) {
                    currentDecrement += decrement;
                }

                queryIndex++;
            }

            if (nums[i] > currentDecrement) {
                return -1;
            }
        }

        return queryIndex;
    }
};