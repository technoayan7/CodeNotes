class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& points) {
        int arrow=0;

        sort(points.begin(),points.end());
        int end = points[0][1];
        int n = points.size();

        for(int i=1;i<points.size();i++){
            int start = points[i][0];
            if(start < end){
                arrow++;
                end=min(end,points[i][1]);
            }
            else 
                end = points[i][1];
        }

        return arrow;
    }
};