class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ans;
        int i=0;
        for(auto it: nums) {
            string str = it;
            ans += str[i] == '1' ? '0' : '1';
            i++;
        }
        return ans;
    }
};