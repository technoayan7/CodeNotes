#define ll long long
class Solution {
public:
    ll f[11];
    vector<ll> genPal(int n) {
        vector<ll> p;
        if (n == 0) return p;
        int half = (n + 1) / 2;
        ll s = pow(10, half - 1), e = pow(10, half) - 1;
        if (n == 1) s = 0;
        for (ll h = s; h <= e; ++h) {
            string sh = to_string(h), sp;
            if (n % 2 == 0) {
                sp = sh + string(sh.rbegin(), sh.rend());
            } else {
                sp = sh + string(sh.rbegin() + 1, sh.rend());
            }
            if (sp.size() == n) p.push_back(stoll(sp));
        }
        return p;
    }

    vector<int> getCounts(ll x, int n) {
        vector<int> c(10, 0);
        string s = to_string(x);
        while (s.size() < n) s = "0" + s;
        for (char ch : s) c[ch - '0']++;
        return c;
    }

    ll countPerms(vector<int> c, int n) {
        ll t = 0;
        for (int d = 1; d <= 9; ++d) {
            if (c[d] == 0) continue;
            vector<int> nc = c;
            nc[d]--;
            bool v = true;
            for (int cnt : nc) if (cnt < 0) { v = false; break; }
            if (!v) continue;
            ll a = f[n - 1];
            for (int i = 0; i < 10; ++i) a /= f[nc[i]];
            t += a;
        }
        return t;
    }

    ll countGoodIntegers(int n, int k) {
        f[0] = 1;
        for (int i = 1; i <= 10; ++i) f[i] = f[i - 1] * i;
        vector<ll> p = genPal(n);
        vector<ll> vp;
        for (auto num : p) if (num % k == 0) vp.push_back(num);
        set<vector<int>> uc;
        for (auto num : vp) uc.insert(getCounts(num, n));
        ll r = 0;
        for (auto &counts : uc) r += countPerms(counts, n);
        return r;
    }
};
