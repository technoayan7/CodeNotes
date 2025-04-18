class Solution {
public:
    string countAndSay(int n) {
        if (n <= 0) return "";
        
        string result = "1";
        for (int i = 1; i < n; ++i) {
            string current = "";
            int count = 1;
            char previousChar = result[0];
            
            for (int j = 1; j < result.size(); ++j) {
                if (result[j] == previousChar) {
                    count++;
                } else {
                    current += to_string(count) + previousChar;
                    previousChar = result[j];
                    count = 1;
                }
            }
            current += to_string(count) + previousChar;
            result = current;
        }
        
        return result;
    }
};
