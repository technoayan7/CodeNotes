class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int, int> mp;
        for(auto it: arr) mp[it]++;
        for(auto it: arr) {
            if(it == 0) {
                if(mp[it] >= 2) return true;
                else continue;
            }
            else if(mp.find(it*2) != mp.end()) return true;
        } 
        return false;
    }
};