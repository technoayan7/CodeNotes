class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size()!=word2.size()) return false;
        unordered_map<char, int> m1,m2;
        multiset<int> s1,s2;
        set<char> ch;
        for(char c: word1) {m1[c]++; ch.insert(c); }
        for(char c: word2) {m2[c]++; ch.erase(c); }
        for(auto [k,value] : m1) s1.insert(value);
        for(auto [k,value] : m2) s2.insert(value);
        return (ch.empty() && s1==s2);
    }
};