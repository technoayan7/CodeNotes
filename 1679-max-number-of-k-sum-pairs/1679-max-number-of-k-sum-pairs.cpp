class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
      unordered_map<int, int> mp;
      for (auto &it: nums) mp[it]++; 
      int ans = 0;
  
      for(auto it: nums) {
          int res = k - it;
          if(mp.find(res) != mp.end()) {
              ans++;
              mp[res]--;
          }
          if(mp[res]==0) mp.erase(res);
      }
      return ans/2;
    }
};