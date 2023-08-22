class Solution {
public:
    string convertToTitle(int columnNumber) {
        int x = columnNumber;
        string s="";
        while(x!=0)
        {
            x=x-1;
            if(x>=0){
                char ch = 'A' + x%26;
                s = ch + s;
            }
            x/=26;
        }
        return s;
    }
};