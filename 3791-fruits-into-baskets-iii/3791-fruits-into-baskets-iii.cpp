#define ll long long 
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& f, vector<int>& b) {
        int n = f.size();
        int size = 1;
        while (size < n) {
            size *= 2;
        }
        vector<ll> seg(2 * size, -1);

        for (int i = 0; i < n; i++) {
            seg[size + i] = b[i];
        }
        for (int i = size - 1; i > 0; i--) {
            seg[i] = max(seg[2 * i], seg[2 * i + 1]);
        }

        auto update = [&](int pos, ll val) {
            pos += size;
            seg[pos] = val;
            for (pos /= 2; pos; pos /= 2)
                seg[pos] = max(seg[2 * pos], seg[2 * pos + 1]);
        };

        auto query = [&](ll x) -> int {
            if (seg[1] < x)
                return -1;
            int idx = 1;
            while (idx < size) {
                if (seg[2 * idx] >= x)
                    idx = 2 * idx;
                else
                    idx = 2 * idx + 1;
            }
            return idx - size;
        };

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int pos = query(f[i]);
            if (pos == -1)
                ans++;
            else
                update(pos, -1);
        }
        return ans;
    }
};