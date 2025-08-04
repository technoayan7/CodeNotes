class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();

        for(int i = 0; i < n; i++){
            int fruit = fruits[i];

            for(int j=0;j<n;j++){
                if(baskets[j] >= fruit){
                    baskets[j] = -1;
                    break;
                }
            }
        }
        int cnt = 0;
        for(auto it : baskets){
            if(it != -1) cnt++;
        }

        return cnt;
    }
};