class Solution {
public:
    bool search(vector<int>& nums, int x) {
        int n=nums.size(), low=0, high=n-1;
        while(low<=high) {
            int mid=(high+low)/2;
            if(nums[mid]==x) return true; 
            if((nums[low] == nums[mid]) && (nums[mid] == nums[high])) {
                low++;
                high--;
            }
            else if(nums[low]<=nums[mid]) {
                // left is sorted
                if(x>=nums[low] && x<=nums[mid]) high=mid-1;
                else low=mid+1;
            }
            else {
                if(x>=nums[mid] && x<=nums[high]) low=mid+1;
                else high=mid-1;
            }
        }
        return false;
    }
};