class Solution {
public:
    int findLucky(vector<int>& arr) {
        int n = arr.size();
        int ans = -1, maxi = -1;
        for(int i=0;i<n;i++) {
            maxi = max(maxi, arr[i]);
        }
        vector<int> v(maxi+1, 0);
        for(int i=0;i<n;i++) {
            v[arr[i]]++;
        }
        for(int i=1;i<=maxi;i++) {
            if(v[i] == i) {
                ans = i;
            }
        }
        return ans;
    }
};