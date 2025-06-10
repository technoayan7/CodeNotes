class Solution {
public:
    int maxDifference(string s) {
        vector<int> mpp(26, 0);
        for(auto it: s) {
            mpp[it-'a']++;
        }
        int maxi = 0, mini = s.size();
        for (int i = 0 ; i < 26; i++) {
            if (mpp[i] % 2 == 1) maxi = max(maxi, mpp[i]);
            if (mpp[i] % 2 == 0 && mpp[i] > 0) mini = min(mini, mpp[i]);
        } 
        return maxi - mini;
    }
};