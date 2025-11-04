class Solution {
public:
    int solve(vector<int> &nums, int i, int j, int x) {
        unordered_map<int, int> mp;
        while(i<=j) {
            mp[nums[i]]++;
            i++;
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(auto it: mp) {
            pq.push({it.second, it.first});
            if(pq.size() > x) pq.pop();
        }
        int sum = 0;
        while(!pq.empty()){
            sum += pq.top().second * pq.top().first;
            pq.pop();
        }
        return sum;
    }
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans;
        for(int i=0;i<n-k+1;i++) {
            int sum = solve(nums,i,i+k-1,x);
            ans.push_back(sum);
        }
        return ans;
    }
};