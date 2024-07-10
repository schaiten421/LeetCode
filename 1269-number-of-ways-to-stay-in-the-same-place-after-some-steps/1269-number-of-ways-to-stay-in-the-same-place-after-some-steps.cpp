class Solution {
public:
    const int mod=1e9+7;
    int f(int i,int j,int steps,vector<vector<int>> &dp){
        if(i<0 || i>=j)return 0;
        if(steps==0)return i==0;
        if(dp[i][steps]!=-1)return dp[i][steps];
        return dp[i][steps]= ((f(i-1,j,steps-1,dp)%mod+f(i+1,j,steps-1,dp)%mod)%mod+f(i,j,steps-1,dp)%mod)%mod;
    }
    int numWays(int steps, int arrLen) {
        arrLen=min(arrLen,steps);
        vector<vector<int>> dp(arrLen,vector<int>(steps+1,-1));
        return f(0,arrLen,steps,dp);
    }
};