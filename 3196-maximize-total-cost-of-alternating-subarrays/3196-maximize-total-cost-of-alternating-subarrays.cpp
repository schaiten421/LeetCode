class Solution {
public:
    long long f(int i,vector<int> &nums,bool flag,vector<vector<long long>> &dp){
        if(i==nums.size())return 0;
        if(dp[i][flag]!=LLONG_MIN)return dp[i][flag];
        long long old=0;
        if(flag){
            old=nums[i]+f(i+1,nums,false,dp);
        }
        else{
            old=-(nums[i])+f(i+1,nums,true,dp);
        }
        long long new_val=nums[i]+f(i+1,nums,false,dp);
        return dp[i][flag]= max(old,new_val);
    }
    long long maximumTotalCost(vector<int>& nums) {
        int n=nums.size();
        vector<vector<long long>> dp(n+1,vector<long long>(2,LLONG_MIN));
        return f(0,nums,true,dp);
    }
};