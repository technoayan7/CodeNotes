class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int c1 = 0, c2 = 0;
        long long sum1 = 0, sum2 = 0;
        for(auto it: nums1) {
            sum1 += it;
            if(it == 0) c1++;
        }
        for(auto it: nums2) {
            sum2 += it;
            if(it==0) c2++;
        }
        if(c1==0 && sum1<sum2+c2) return -1;
        if(c2==0 && sum2<sum1+c1) return -1;
        return max(sum1+c1,sum2+c2);
    }
};