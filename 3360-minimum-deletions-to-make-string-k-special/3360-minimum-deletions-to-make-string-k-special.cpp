class Solution {
public:
    int minimumDeletions(string word, int k) {
        #define int long long 
        int d= 26; 
        vector<int> cnt(d);
        for(auto it:word)cnt[it-'a']++; 
        int ans = word.size(); 
        for(int i=0;i<=word.size();i++){
            int cur =0; 
            for(int j=0;j<d;j++){
                if(cnt[j]<i)cur+=cnt[j]; 
                else cur+=max(0LL,cnt[j]-i-k); 
            }
            ans=min(ans,cur);
        }
        return ans; 
        #undef int 
    }
};