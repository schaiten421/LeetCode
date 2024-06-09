class Solution {
public:
    const int MOD=1e9+7;
    int valueAfterKSeconds(int n, int k) {
        vector<vector<int>> dp(k+1,vector<int>(n,0));
        for(int i=0;i<n;i++)dp[0][i]=1;
        for(int i=0;i<=k;i++)dp[i][0]=1;
        for(int i=1;i<=k;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=(dp[i][j-1]+dp[i-1][j])%MOD;
            }
        }
        return dp[k][n-1];
        
    }
};