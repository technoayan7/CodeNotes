class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> arr;
        for (auto it : grid) {
            for (auto it1 : it) {
                arr.push_back(it1);
            }
        }
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int mid = 0;
        if(n%2==0) mid = arr[n/2-1];
        else mid = arr[n/2];
        int cnt = 0;
        for(auto it: arr) {
            if(abs(it-mid)%x) return -1;
            if(it > mid) {
                cnt += (it-mid)/x;
            }
            else if(it < mid) {
                cnt += (mid-it)/x;
            }
        }
        return cnt;
    }
};