class Solution {
public:
    int findLongestChain(vector<vector<int>>& p) {
        int c=1;

        sort(p.begin(), p.end());
        int last = p[0][1];

        for(int i=1; i<p.size(); i++){
            if(p[i][0] > last){
                c++;
                last = p[i][1];
            }
            else last = min(last, p[i][1]);
        }

        return c;
    }
};