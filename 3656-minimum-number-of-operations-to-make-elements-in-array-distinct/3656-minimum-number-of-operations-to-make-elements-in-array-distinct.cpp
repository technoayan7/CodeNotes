class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        auto chk = [](const vector<int>& arr, int st) {
            unordered_set<int> s;
            for (int i = st; i < (int)arr.size(); i++) {
                if (s.find(arr[i]) != s.end()) {
                    return false;
                }
                s.insert(arr[i]);
            }
            return true;
        };

        int sz = nums.size();
        if (chk(nums, 0)) {
            return 0;
        }

        int ops = (sz + 2) / 3;
        for (int p = 1; p <= ops; p++) {
            int lo = min(3 * (p - 1) + 1, sz);
            int hi = min(3 * p, sz);
            for (int st = lo; st <= hi; st++) {
                if (chk(nums, st)) {
                    return p;
                }
            }
        }
        return ops;
    }
};