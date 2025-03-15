class Solution {
public:
    int minCapability(vector<int>& a, int k) {
        int l = 1, r = 1e9, ans = r;
        while (l <= r) {
            int mid = (l + r) / 2, cnt = 0;
            for (int i = 0; i < a.size(); i++) {
                if (a[i] <= mid) {
                    cnt++;
                    i++;
                }
            }
            if (cnt >= k) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};