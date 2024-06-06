class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,0));
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0)dp[0][i]=1;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=amount;j++){
                int nottake=dp[i-1][j];
                int take=0;
                if(coins[i]<=j)take=dp[i][j-coins[i]];
                dp[i][j]=take+nottake;
            }
        }
        return dp[n-1][amount];
    }
};