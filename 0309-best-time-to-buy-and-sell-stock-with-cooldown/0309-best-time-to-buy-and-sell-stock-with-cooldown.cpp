class Solution {
public:
    int f(int i,int j,int buy,vector<int> &prices,vector<vector<int>>& dp){
        if(i>=j)return 0;
        if(dp[i][buy]!=-1)return dp[i][buy];
        int profit=0;
        if(buy){
            profit=max(-prices[i]+f(i+1,j,0,prices,dp),f(i+1,j,1,prices,dp));
        }
        else{
            profit=max(prices[i]+f(i+2,j,1,prices,dp),f(i+1,j,0,prices,dp));
        }
        return dp[i][buy]= profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return f(0,n,1,prices,dp);
    }
};