class Solution {
public:
    int minimumSize(vector<int>& nums, int k) {
        int s = 1, e = 1e9;
        while(s <= e) {
            int m = s + (e - s) / 2;
            int sum = 0;
            for(int i : nums) {
                sum += ceil(i / m);
                if(i%m==0) sum--;
            }
            if (sum > k)
                s = m + 1;
            else
                e = m - 1;
        }
        return s;
    }
};