class Solution {
public:
    int f(int i,int j,int buy,vector<int>& prices,int t,vector<vector<vector<int>>>& dp){
        if(t==0)return 0;
        if(i==j) return 0;
        if(dp[i][buy][t]!=-1)return dp[i][buy][t];
        int profit=0;
        if(buy){
            profit=max(-prices[i]+f(i+1,j,0,prices,t,dp),0+f(i+1,j,1,prices,t,dp));
        }
        else{
            profit=max(prices[i]+f(i+1,j,1,prices,t-1,dp),f(i+1,j,0,prices,t,dp));
        }
        return dp[i][buy][t]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        return f(0,n,1,prices,2,dp);
    }
};