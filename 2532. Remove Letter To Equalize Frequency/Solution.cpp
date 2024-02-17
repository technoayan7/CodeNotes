class Solution {
public:
    bool chk(string word) {
        unordered_map<char, int> mp;
        for(auto it: word) mp[it]++;
        set<int> st;
        for(auto it: mp) st.insert(it.second);
        if(st.size()==1) return true;
        else return false;
    }
    bool equalFrequency(string word) {
        int n = word.size();
        for(int i=0;i<n;i++) {
            string s = word.substr(0, i) + word.substr(i+1, n);
            if(chk(s)) return true;
        }
        return 0;
    }
};