class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int maxVal = values[0], maxScore = 0, currVal = 0;
        for(int i=1;i<n;i++) {
            currVal = values[i] - i;
            maxScore = max(maxScore, maxVal+currVal);
            maxVal = max(maxVal, values[i] + i);
        }
        return maxScore;
    }
};