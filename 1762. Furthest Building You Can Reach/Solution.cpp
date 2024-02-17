class Solution {
public:
    int furthestBuilding(vector<int>& a, int bricks, int ladders) {
        int n = a.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=0;i<n-1;i++) {
            int d = a[i+1] - a[i];
            if(d <= 0) continue;
            if(d > 0) pq.push(d);
            if(pq.size() > ladders) bricks -= pq.top(),pq.pop();
            if(bricks < 0) return i;
        }
        return n-1;
    }
};