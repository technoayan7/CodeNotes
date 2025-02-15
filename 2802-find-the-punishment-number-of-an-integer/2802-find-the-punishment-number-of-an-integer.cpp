class Solution {
public:
    int f; 
    void func(int i, string& s, int sum, int& num){
        int n = s.size();
        if(i==n and sum == num) {
            f=1;
            return;
        }
        for(int j=i;j<n;j++) {
            int len = j-i+1;
            string str = s.substr(i, len);
            int nval = stoi(str);
            func(j+1, s, sum + nval, num);
        }
    }
    
    int punishmentNumber(int n) {
        int ans = 0;
        for(int i = 1;i<=n;i++){
            int val = i*i;
            string s = to_string(val);
            f = 0;  
            func(0, s, 0, i);
            if(f==1) ans += val;
        }
        return ans;       
    }
};