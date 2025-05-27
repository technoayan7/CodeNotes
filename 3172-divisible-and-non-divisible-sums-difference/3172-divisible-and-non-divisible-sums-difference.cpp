class Solution {
public:
    int differenceOfSums(int n, int m) {
        int num1 = n*(n+1)/2;
        if(m > n) return num1;
        int num2 = 0;
        for(int i=m;i<=n;i+=m) {
            num2 += i;
        }
        num1 -= num2;
        return num1-num2;
    }
};