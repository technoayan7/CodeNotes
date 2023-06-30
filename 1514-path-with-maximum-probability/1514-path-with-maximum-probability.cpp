class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& e, vector<double>& p, int s, int end) {
        vector<pair<int,double>> adj[n+1];
        for(int i=0;i<e.size();i++) {
            adj[e[i][0]].push_back({e[i][1], p[i]});
            adj[e[i][1]].push_back({e[i][0], p[i]});
        }
        priority_queue<pair<double, int>> pq;
        vector<double> distTo(n, 0);
        distTo[s] = 0.0;
        pq.push({1.0, s});
        // Now, pop the max distance node first from the max-heap
        // and traverse for all its adjacent nodes.
        while (!pq.empty())
        {
            double dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            // Check for all adjacent nodes of the popped out
            // element whether the prev dist is larger than current or not.
            for (auto it : adj[node])
            {
                int v = it.first;
                double w = it.second;
                double pp = dis * w;
                if (pp > distTo[v])
                {
                    distTo[v] = pp;
                    // If current distance is larger,
                    // push it into the queue.
                    pq.push({pp, v});
                }
            }
        }
        return distTo[end];
    }
};
