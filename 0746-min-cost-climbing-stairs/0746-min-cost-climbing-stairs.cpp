class Solution {
    int f(int ind,vector<int> cost,vector<int>& dp){
        if(ind==0 || ind==1)return cost[ind];
        if(dp[ind]!=-1)return dp[ind];
        return cost[ind]+min(f(ind-1,cost,dp),f(ind-2,cost,dp));
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n+1,0);
        for(int i=2;i<=n;i++){
            int onestep=dp[i-1]+cost[i-1];
            int twostep=dp[i-2]+cost[i-2];
            dp[i]=min(onestep,twostep);
        }
        return dp[n];
    }
};