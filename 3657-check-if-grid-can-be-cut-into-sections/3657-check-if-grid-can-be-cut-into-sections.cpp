class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& r) {
        auto f = [](const vector<pair<long long, long long>>& v) {
            int s = v.size();
            if (s < 3) return false;
            vector<long long> pre(s), suf(s);
            pre[0] = v[0].second;
            for (int i = 1; i < s; ++i) pre[i] = max(pre[i - 1], v[i].second);
            suf[s - 1] = v[s - 1].first;
            for (int i = s - 2; i >= 0; --i) suf[i] = min(suf[i + 1], v[i].first);
            vector<int> c;
            for (int i = 0; i < s - 1; ++i) if (pre[i] <= suf[i + 1]) c.push_back(i);
            if (c.size() < 2) return false;
            for (size_t i = 0; i < c.size() - 1; ++i) if (c[i + 1] >= c[i] + 1 && c[i + 1] < s - 1) return true;
            return false;
        };

        vector<pair<long long, long long>> x, y;
        for (const auto& a : r) {
            x.emplace_back(a[0], a[2]);
            y.emplace_back(a[1], a[3]);
        }
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());

        return f(x) || f(y);
    }
};
