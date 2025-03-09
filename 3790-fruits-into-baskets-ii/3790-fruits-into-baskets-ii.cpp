class Solution {
public:
    int numOfUnplacedFruits(vector<int>& f, vector<int>& b) {
        int n = f.size();
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(f[i] <= b[j]) {
                    b[j] = -1;
                    break;
                }
            }
        }
        int ct = 0;
        for(auto it: b) {
            if(it != -1) ct++;
        }
        return ct;
    }
};