class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0;
        int n = nums.size();
        int i = 0;
        int mx = INT_MIN;
        for(int j=0;j<n;j++) {
            sum+=nums[j];
            if(j - i == k-1) {
                mx = max(mx, sum);
                sum-=nums[i];
                i++;
            }
        }
        cout<<mx<<endl;
        double ans = (double)mx / (double)k;
        return ans;
    }
};