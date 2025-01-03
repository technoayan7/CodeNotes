class Solution {
public:
    int waysToSplitArray(vector<int>& a) {
        long long total_sum = 0;
        for(auto i: a) 
            total_sum+=i;
        long long ans = 0, sum = 0;
        for(int i=0;i<a.size()-1;i++) {
            sum+=a[i];
            if(sum>=(total_sum-sum))
                ans++;
        }
        return ans;
    }
};