class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int prevEnd = 0, len;
        sort(meetings.begin(), meetings.end());
        for(auto it : meetings){
            int st = max(prevEnd + 1, it[0]), end = it[1];
            len = end - st + 1;
            days -= max(len, 0);
            prevEnd = max(prevEnd, end);
        }

        
        return days;
    }
};