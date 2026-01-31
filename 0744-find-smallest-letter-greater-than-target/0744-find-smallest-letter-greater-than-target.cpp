class Solution {
public:
    char nextGreatestLetter(vector<char>& nums, char target) {
        int n = nums.size();
        int low = 0, high=n-1;
        if(nums[0] > target)
          return nums[0];
        
        else if(target >= nums[n-1]) return nums[0];  
        
        char ans;  
        
        while( low <= high) {
            int mid=(low+high)/2;
            if(nums[mid] > target){
                ans = nums[mid];
                high = mid-1;
            }
            else
             low = mid+1;
        }
        return ans;
    }
};