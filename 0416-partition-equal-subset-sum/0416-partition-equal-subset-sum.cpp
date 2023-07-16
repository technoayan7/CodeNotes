class Solution {
public:
    bool subsetSum(int ind, int target, vector<int>& arr, vector<vector<int>> &dp) {
        if(target==0) return true;
        if(ind == 0) return arr[0] == target;
        if(dp[ind][target]!=-1) return dp[ind][target];
            
        bool notTaken = subsetSum(ind-1,target,arr,dp);
        
        bool taken = false;
        if(arr[ind]<=target)
            taken = subsetSum(ind-1,target-arr[ind],arr,dp);
            
        return dp[ind][target]= notTaken||taken;
    }
    
    bool canPartition(vector<int>& nums) {
        int totSum=0;
        int n = nums.size();
        for(int i=0; i<n;i++){
            totSum+= nums[i];
        }
        if (totSum%2==1) return 0;
        else {
            int k = totSum/2;
            vector<vector<int>> dp(n,vector<int>(k+1,-1));
            return subsetSum(n-1,k,nums,dp);
        }
    }
};
