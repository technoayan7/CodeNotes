class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& d) {
        double maxDiagonal = 0;
        int maxArea = 0;

        for (const auto& rect : d) {
            int length = rect[0];
            int width = rect[1];

            double diagonal = sqrt(length * length + width * width);
            int area = length * width;

            if (diagonal > maxDiagonal || (diagonal == maxDiagonal && area > maxArea)) {
                maxDiagonal = diagonal;
                maxArea = area;
            }
        }

        return maxArea;
    }
};