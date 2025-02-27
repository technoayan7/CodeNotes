class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        int n = nums.size();
        for(int i=0;i<n;i++) {
            pq.push(nums[i]);
        }
        int cnt = 0;
        while(pq.size() >= 2) {
            long long a = pq.top();
            if(a >= k) break;
            pq.pop();
            long long b = pq.top();
            pq.pop();
            long long c = min(a,b)*2 + max(a,b);
            pq.push(c);
            cnt++;
        }
        return cnt;
    }
};