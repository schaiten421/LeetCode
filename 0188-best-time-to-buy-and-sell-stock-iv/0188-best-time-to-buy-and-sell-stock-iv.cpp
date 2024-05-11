class Solution {
public:
    int f(int i,int j,int buy,int k, vector<int>& prices,vector<vector<vector<int>>>& dp){
        if(i==j || k==0)return 0;
        int profit=0;
        if(dp[i][buy][k]!=-1)return dp[i][buy][k];
        if(buy){
            profit=max(-prices[i]+f(i+1,j,0,k,prices,dp),f(i+1,j,1,k,prices,dp));
        }
        else{
            profit=max(prices[i]+f(i+1,j,1,k-1,prices,dp),f(i+1,j,0,k,prices,dp));
        }
        return dp[i][buy][k]=profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return f(0,n,1,k,prices,dp);
    }
};