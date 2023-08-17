class Solution {
public:
    int firstMissingPositive(vector<int>& a) {
        int n = a.size();
        for(int i=0;i<n;) {
            if(a[i]>0 and a[i]<=n and a[i]!=a[a[i]-1]) {
                swap(a[i], a[a[i]-1]); // 1 jayega zero index pe 2 jayega 1 pe
            }
            else
                i++;
        }
        int i=0;
        for(i=0;i<n;i++) {
            if(a[i]!=i+1) {
                break;
            }
        }
        return i+1;
    }
};