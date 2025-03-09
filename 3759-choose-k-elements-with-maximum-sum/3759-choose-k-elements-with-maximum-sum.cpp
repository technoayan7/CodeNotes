#define ll long long
class Solution {
public:
    vector<ll> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<ll> ans(n, 0);
        vector<array<int, 3>> arr;
        for (int i = 0; i < n; i++) {
            arr.push_back({nums1[i], nums2[i], i});
        }
        sort(arr.begin(), arr.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        ll sum = 0;
        int i = 0;
        while (i < n) {
            int cur = arr[i][0];
            int j = i;
            while (j < n && arr[j][0] == cur) {
                ans[arr[j][2]] = sum;
                j++;
            }
            for (int t = i; t < j; t++) {
                int x = arr[t][1];
                if (pq.size() < k) {
                    pq.push(x);
                    sum += x;
                } else if (pq.top() < x) {
                    sum -= pq.top();
                    pq.pop();
                    pq.push(x);
                    sum += x;
                }
            }
            i = j;
        }
        return ans;
    }
};