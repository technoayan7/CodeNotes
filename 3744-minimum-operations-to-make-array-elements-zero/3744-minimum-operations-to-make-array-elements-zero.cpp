#define fi first
#define se second
#define pb push_back
#define in insert
#define ub upper_bound
#define lb lower_bound
#define ll long long
#define vi vector<int>
#define bs binary_search
#define pii pair<int, int>
#define mii map<int, int>
#define all(a) a.begin(), a.end()
#define f(i, n) for (int i = 0; i < n; i++)
#define foe(i, a, b) for (int i = a; i <= b; i++)

class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        ll ans = 0;
        vector<ll> p(16);
        p[0] = 1;
        for (int i = 1; i < 16; i++)
            p[i] = p[i - 1] * 4;
        for (auto& q : queries) {
            ll l = q[0], r = q[1], sum = 0;
            foe(t,1,15){
                ll L = max(l, p[t - 1]), R = min(r, p[t] - 1);
                if (L <= R)
                    sum += t * (R - L + 1);
            }
            ans += (sum + 1) / 2;
        }
        return ans;
    }
};