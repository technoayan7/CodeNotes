class Solution {
public:
    bool canPlaceFlowers(vector<int>& a, int n) {
        int c = 0, sz = a.size();
        for(int i=0;i<sz;i++) {
            if (a[i] == 0) {
                if((i == 0 || a[i-1] == 0) && (i == a.size()-1 || a[i+1] == 0)) {
                    a[i] = 1;
                    c++;
                }
            }
        }
        if(n<=c) return true;
        else return false;
    }
};