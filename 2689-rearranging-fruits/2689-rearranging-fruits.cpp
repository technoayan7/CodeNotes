class Solution {
public:
    long long minCost(vector<int>& b1, vector<int>& b2) {
        long long cost = 0;
        sort(b1.begin(), b1.end());
        sort(b2.begin(), b2.end());
        unordered_map<int, int> mp;
        int mini = min(b1[0], b2[0]);
        for(int i=0;i<b1.size();i++) {
            mp[b1[i]]++;
            mp[b2[i]]--;
        }
        vector<int> arr;
        for(auto it: mp) {
            int k = it.first;
            int v = it.second;
            if(v%2 != 0) return -1;

            for(int i=0;i<abs(v/2);i++) {
                arr.push_back(k);
            }
        }
        sort(arr.begin(), arr.end());
        for(int i=0;i<arr.size()/2;i++) {
            cost += min(2*mini, arr[i]);
        }
        return cost;
    }
};