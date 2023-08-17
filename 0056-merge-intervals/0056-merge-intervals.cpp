class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        vector<vector<int>> ans;
        ans.push_back(points[0]);
        for(int i=1;i<points.size();i++)
        {
            if(ans.back()[1] >= points[i][0]) 
                ans.back()[1] = max(ans.back()[1] , points[i][1]);
            else 
                ans.push_back(points[i]); 
        }
        return ans;
    }
};
