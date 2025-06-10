class Solution {
public:
    int maxDifference(string s) {
        vector<int> mp(26, 0);
        for(auto it: s) {
            mp[it-'a']++;
        }
        sort(mp.begin(), mp.end());
        int a1 = 0, a2 = 0;
        for(int i=0;i<26;i++) {
            if(mp[i]!=0 and mp[i]%2==0) {
                a2 = mp[i];
                break;
            }
        }
        for(int i=25;i>=0;i--) {
            if(mp[i]%2==1) {
                a1 = mp[i];
                break;
            }
        }
        return a1-a2;
    }
};