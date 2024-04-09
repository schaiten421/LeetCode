class Solution {
public:
    int f(int M, int N, vector<vector<int>> &dp){
        if(M==0 && N==0){
            return 1;
        }
        if(M<0 || N<0)return 0;
        if(dp[M][N]!=-1)return dp[M][N];
        
        int up=f(M-1,N,dp);
        int left=f(M,N-1,dp);
        return dp[M][N]=up+left;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return f(m-1,n-1,dp);
    }
};