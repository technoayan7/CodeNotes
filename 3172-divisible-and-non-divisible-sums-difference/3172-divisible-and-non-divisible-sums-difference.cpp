class Solution {
public:
    int differenceOfSums(int n, int m) {
        int num1 = n*(n+1)/2;
        int num2 = m*(n/m)*(n/m+1);
        return num1-num2;
    }
};