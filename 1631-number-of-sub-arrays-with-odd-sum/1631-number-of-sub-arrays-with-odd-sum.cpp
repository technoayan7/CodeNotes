class Solution {
public:
    int numOfSubarrays(vector<int>& a) {
        long long odd = 0, even = 0, sum = 0, ans=0;
        for (int i : a) {
            sum+=i;
            if (sum % 2==0) {
                even++;
                ans += odd;
            }
            else {
                odd++;
                ans += 1 + even;
            }
            ans  = ans % 1000000007;
                
        }
        return ans;
    }
};