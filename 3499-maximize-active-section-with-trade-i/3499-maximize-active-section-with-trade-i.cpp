#define fi first
#define se second
#define pb push_back
#define in insert
#define ub upper_bound
#define lb lower_bound
#define vi vector<int>
#define bs binary_search
#define pii pair<int, int>
#define mii map<int, int>
#define all(a) a.begin(), a.end()
#define f(i, n) for (int i = 0; i < n; i++)
#define foe(i, a, b) for (int i = a; i <= b; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl

class Solution
{
public:
    int maxActiveSectionsAfterTrade(string s)
    {
        int n = s.size(), ones = 0;
        f(i, n) if (s[i] == '1') ones++;
        vi LZ(n, 0), RZ(n, 0);
        if (n && s[0] == '0') LZ[0] = 1;
        for (int i = 1; i < n; i++) LZ[i] = (s[i] == '0' ? LZ[i - 1] + 1 : 0);
        if (n && s[n - 1] == '0') RZ[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--) RZ[i] = (s[i] == '0' ? RZ[i + 1] + 1 : 0);
        int mx = 0;
        f(i,n)
        {
            if (s[i] == '1')
            {
                int j = i;
                while (j + 1 < n && s[j + 1] == '1') j++;
                if (i == 0 || j == n - 1) { i = j; continue; }
                if (s[i - 1] != '0' || s[j + 1] != '0') { i = j; continue; }
                int l = LZ[i - 1], r = RZ[j + 1];
                int p = i - l, q = j + r;
                int cand = q - p + 1;
                if (p > 0 && s[p - 1] != '1') cand--;
                if (q < n - 1 && s[q + 1] != '1') cand--;
                int imp = cand - (j - i + 1);
                mx = max(mx, imp);
                i = j;
            }
        }
        return ones + max(0, mx);
    }
};
