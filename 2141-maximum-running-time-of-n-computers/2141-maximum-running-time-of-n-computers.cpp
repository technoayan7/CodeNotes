class Solution {
public:
    long long maxRunTime(int n, vector<int>& b) {
        long long low = 0, ans=0;
        long long high = accumulate(begin(b),end(b),0LL)/n;

        while(low <= high){
            long long mid = low + (high-low)/2;
            long long time=0;
            for(int t : b) time += min((long long)t, mid);

            if(mid*n <= time) {
                ans = mid;
                low = mid+1;
            }
            else high = mid-1;
        }
        return ans;
    }
};