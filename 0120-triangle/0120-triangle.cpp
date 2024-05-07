class Solution {
public:
    int f(int m,int n,vector<vector<int>>& triangle,vector<vector<int>>& dp){
        if(m==triangle.size()-1) return triangle[m][n];
        // if(n>triangle[0].size()-1) return 1e9;
        if(dp[m][n]!=-1) return dp[m][n];
        int down=triangle[m][n]+f(m+1,n,triangle,dp);
        int dr=triangle[m][n]+f(m+1,n+1,triangle,dp);
        return dp[m][n]=min(down,dr);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        int n=triangle[0].size();
        vector<vector<int>> dp(m,vector<int>(m,-1));
        return f(0,0,triangle,dp);
    }
};