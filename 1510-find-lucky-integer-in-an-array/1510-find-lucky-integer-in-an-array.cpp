class Solution {
public:
    int findLucky(vector<int>& arr) {
        int n = arr.size();
        vector<int> v(501, 0);
        for(int i=0;i<n;i++) {
            v[arr[i]]++;
        }
        int ans = -1;
        for(int i=1;i<501;i++) {
            if(v[i] == i) {
                ans = i;
            }
        }
        return ans;
    }
};