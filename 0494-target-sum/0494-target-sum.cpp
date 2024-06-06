class Solution {
private:
    int f(int ind,int sum,vector<int> arr,vector<vector<int>>& dp){
        if(ind==0){
            if(sum==0 && arr[0]==0)return 2;
            if(sum==0 || arr[ind]==sum)return 1;
            return 0;
        }
        if(dp[ind][sum]!=-1)return dp[ind][sum];
        
        int nottake=f(ind-1,sum,arr,dp);
        int take=0;
        if(arr[ind]<=sum)take=f(ind-1,sum-arr[ind],arr,dp);
        return dp[ind][sum]=take+nottake;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        for(auto it:nums)sum+=it;
        if(sum<target ||  (sum-target)%2==1)return 0;
        int targetsum=(sum-target)/2;
        vector<vector<int>> dp(nums.size(),vector<int>(targetsum+1,-1));
        return f(nums.size()-1,targetsum,nums,dp);
        
        
        
    }
};