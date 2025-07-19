class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> result;
        string prev = "";
        for (auto curr : folder) {
            if (prev.empty() || curr.find(prev + "/") != 0) {
                result.push_back(curr);
                prev = curr;
            }
        }
        return result;
    }
};