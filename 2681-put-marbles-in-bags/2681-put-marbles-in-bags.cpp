class Solution {
public:
    long long putMarbles(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(int i=0;i<n-1;i++) {
            int a = nums[i];
            int b = nums[i+1];
            int sum = a+b;
            maxHeap.push(sum);
            minHeap.push(sum);
        }
        int x = k-1, y = k-1;
        long long sum1 = 0, sum2 = 0;
        while(x>0) {
            x--;
            sum1+=maxHeap.top();
            maxHeap.pop();
        }
        while(y>0) {
            y--;
            sum2+=minHeap.top();
            minHeap.pop();
        }
        long long ans = sum1-sum2;
        return ans;
    }
};
//8-4