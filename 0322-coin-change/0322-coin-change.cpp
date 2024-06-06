class Solution {
private:
    int f(int ind,int amount,vector<int> coins,vector<vector<int>>& dp){
        if(ind==0) {
            if(amount%coins[0]==0)return amount/coins[ind];
            else return 1e9;
        }
        if(dp[ind][amount]!=-1)return dp[ind][amount];
        
        int nottake=f(ind-1,amount,coins,dp);
        int take=1e9;
        if(coins[ind]<=amount){take=1;take+=f(ind,amount-coins[ind],coins,dp);}
        return dp[ind][amount]=min(take,nottake);
    }
public:
    int coinChange(vector<int>& coins, int n) {
        // creating the base dp array, with first value set to 0
        int dp[++n];
        dp[0] = 0;
        // more convenient to have the coins sorted
        sort(begin(coins), end(coins));
        // populating our dp array
        for (int i = 1; i < n; i++) {
            // setting dp[0] base value to 1, 0 for all the rest
            dp[i] = INT_MAX;
            for (int c: coins) {
                if (i - c < 0) break;
                // if it was a previously not reached cell, we do not add use it
                if (dp[i - c] != INT_MAX) dp[i] = min(dp[i], 1 + dp[i - c]);
            }
        }
        return dp[--n] == INT_MAX ? -1 : dp[n];
    }
};
