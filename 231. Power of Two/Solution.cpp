class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n >= INT_MAX || n <= INT_MIN) return false;
        int l = 0;
        int h = n;
        while(l<=h) {
            int mid = (l+h)/2;
            if(pow(2,mid) == abs(n)) return true;
            else if(pow(2,mid) < n) l = mid+1;
            else h = mid-1;
        }
        return false;
    }
};