class Solution {
public:
    int findMin(vector<int> &a) {
        int low=0,high=a.size()-1;
        int mini = INT_MAX;

         while(low<=high){
             int mid = (low+high)/2;

             if(a[low] <= a[mid]){
                 mini = min(a[low], mini);
                 low = mid+1;
             }
             else {
                 mini = min(a[mid], mini);
                 high = mid-1;
             }
         }
         return mini;
    }
};