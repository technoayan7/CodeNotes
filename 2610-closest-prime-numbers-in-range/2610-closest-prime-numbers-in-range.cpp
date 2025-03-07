class Solution {
public:
    bool isPrime(int n) {
        if (n <= 1) return false;
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) return false;
        }
        return true;
    }
    bool pairPrime(vector<int> &temp) {
        int n = temp.size();
        if(temp[n-1] - temp[n-2] <= 2) return true;
        return false; 
    }

    vector<int> closestPrimes(int left, int right) {
        vector<int> temp;
        for (int i = left; i <= right; i++) {
            if (isPrime(i) == true) {
                temp.push_back(i);
            }
            if(temp.size() >= 2) {
                if(pairPrime(temp)) {
                    int num1 = temp.back();
                    temp.pop_back();
                    int num2 = temp.back();
                    return {num2, num1};
                }
            }
        }
        if(temp.size() >= 2) {
            return {temp[0], temp[1]};
        }
        return {-1, -1};
    }
};