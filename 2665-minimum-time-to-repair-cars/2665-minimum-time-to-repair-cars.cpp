#define ll long long
class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        ll mx=*max_element(ranks.begin(),ranks.end());
        ll l = 0, h = mx*cars*cars;
        ll ans=h;

        while(l<=h){
            ll m = l+(h-l)/2;
            ll count=0;
            for(auto ele: ranks){
                count+=sqrt(m/ele);
            }
            if(count>=cars){
                h=m-1;
                ans=min(ans,m);
            }
            else l=m+1;
        }
        return ans;
    }
};