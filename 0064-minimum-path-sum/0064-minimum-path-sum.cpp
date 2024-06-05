class Solution {
public:
    int f(int row,int col,vector<vector<int>> grid,vector<vector<int>>& dp){
        if(row==0 && col==0)return grid[0][0];
        if(row<0 || col<0)return 0;
        if(dp[row][col]!=-1)return dp[row][col];
        int up=INT_MAX,left=INT_MAX;
        if(row>0)up=f(row-1,col,grid,dp);
        if(col>0)left=f(row,col-1,grid,dp);
        return dp[row][col]=grid[row][col]+min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0){
                    dp[i][j]=grid[i][j];
                    continue;
                }
                int up=INT_MAX,left=INT_MAX;
                if(i>0)up=dp[i-1][j];
                if(j>0)left=dp[i][j-1];
                dp[i][j]=grid[i][j]+min(up,left);
            }
        }
        
        return dp[n-1][m-1];
    }
};