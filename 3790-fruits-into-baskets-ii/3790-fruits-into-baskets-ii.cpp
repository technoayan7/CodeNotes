class Solution {
public:
    int numOfUnplacedFruits(vector<int>& f, vector<int>& b) {
        int n = f.size();
        int ct = n;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(f[i] <= b[j]) {
                    b[j] = -1;
                    ct--;
                    break;
                }
            }
        }
        return ct;
    }
};