class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(auto it: nums) {
            mp[it]++;
        }
        vector<int> res;
        // pair<first, second>: first is frequency,  second is number
        priority_queue<pair<int,int>> pq; 
        for(auto it: mp){
            pq.push({it.second, it.first});
            if(pq.size() > mp.size() - k){
                res.push_back(pq.top().second);
                pq.pop(); // optional
            }
        }
        return res;
    }
};