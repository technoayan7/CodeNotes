#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int distanceSum(int m, int n, int k) {
        const int MOD = 1e9 + 7;

        // Precompute factorials and inverse factorials
        vector<long long> fact(m * n + 1, 1);
        vector<long long> inv_fact(m * n + 1, 1);
        for (int i = 1; i <= m * n; ++i) {
            fact[i] = fact[i - 1] * i % MOD;
        }
        inv_fact[m * n] = modInverse(fact[m * n], MOD);
        for (int i = m * n - 1; i >= 0; --i) {
            inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
        }

        // Function to compute combinations
        auto comb = [&](int a, int b) -> long long {
            if (a < b || b < 0) return 0;
            return fact[a] * inv_fact[b] % MOD * inv_fact[a - b] % MOD;
        };

        // Calculate sum of x distances
        long long sum_x = 0;
        for (int i = 1; i <= m; ++i) {
            sum_x = (sum_x + (long long)i * (m - i)) % MOD;
        }
        sum_x = sum_x * n % MOD * n % MOD;

        // Calculate sum of y distances
        long long sum_y = 0;
        for (int j = 1; j <= n; ++j) {
            sum_y = (sum_y + (long long)j * (n - j)) % MOD;
        }
        sum_y = sum_y * m % MOD * m % MOD;

        // Total sum of distances
        long long total = (sum_x + sum_y) % MOD;

        // Number of ways to choose k positions out of m * n
        long long ways = comb(m * n, k);

        // If k < 2, the distance sum is 0
        if (k < 2) return 0;

        // Number of ways to choose (k - 2) positions out of (m * n - 2)
        long long comb_k_minus_2 = comb(m * n - 2, k - 2);

        // Final result
        long long result = total * comb_k_minus_2 % MOD;
        return static_cast<int>(result);
    }

private:
    // Function to compute modular inverse using Fermat's Little Theorem
    long long modInverse(long long a, int mod) {
        long long res = 1;
        int exponent = mod - 2;
        while (exponent > 0) {
            if (exponent & 1) {
                res = res * a % mod;
            }
            a = a * a % mod;
            exponent >>= 1;
        }
        return res;
    }
};