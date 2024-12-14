class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long ans = 0;
        int i = 0; 
        multiset<int> window;

        for (int j = 0; j < nums.size(); ++j) {
           
            window.insert(nums[j]);
            while (*window.rbegin() - *window.begin() > 2) {
                window.erase(window.find(nums[i]));
                i++;
            }
            ans += j - i + 1;
        }
        
        return ans;
    }
};