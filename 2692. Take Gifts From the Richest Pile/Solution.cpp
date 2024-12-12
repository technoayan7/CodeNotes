class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long n=gifts.size();
        priority_queue<long long> pq;
        for(auto x: gifts){
            pq.push(x);
        }
        long long ans=0;
        while(k--){
            pq.push(sqrt(pq.top()));
            pq.pop();  
        }
        while(!pq.empty()){
            ans+=pq.top();
            pq.pop();
        }
        return ans;
    }
};