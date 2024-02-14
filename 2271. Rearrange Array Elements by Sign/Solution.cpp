class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos, neg;
        for(auto it: nums) {
            if(it>=0) pos.push_back(it);
            else neg.push_back(it);
        }
        int n = pos.size();
        vector<int> ans;
        for(int i=0;i<n;i++) {
            ans.push_back(pos[i]);
            ans.push_back(neg[i]);
        }
        return ans;
    }
};