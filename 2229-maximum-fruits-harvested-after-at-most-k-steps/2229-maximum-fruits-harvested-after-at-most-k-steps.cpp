class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size(), left = 0, sum = 0, maxFruits = 0;

        for (int right = 0; right < n; ++right) {
            sum += fruits[right][1];

            while (left <= right) {
                int leftPos = fruits[left][0];
                int rightPos = fruits[right][0];

                int goLeftFirst = abs(startPos - leftPos) + (rightPos - leftPos);
                int goRightFirst = abs(startPos - rightPos) + (rightPos - leftPos);

                if (min(goLeftFirst, goRightFirst) <= k) break;

                sum -= fruits[left][1];
                ++left;
            }

            maxFruits = max(maxFruits, sum);
        }

        return maxFruits;
    }
};