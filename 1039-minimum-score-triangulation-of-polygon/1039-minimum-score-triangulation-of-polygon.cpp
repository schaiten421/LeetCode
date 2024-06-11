class Solution {
public:
    int f(int i,int j,vector<int> values,vector<vector<int>>& dp){
        if(i==j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int mini=INT_MAX;
        for(int k=i;k<j;k++){
            int ans=f(i,k,values,dp)+f(k+1,j,values,dp)+values[i-1]*values[k]*values[j];
            mini=min(ans,mini);
                
            }
        return dp[i][j]=mini;
    }
    int minScoreTriangulation(vector<int>& values) {
        vector<vector<int>> dp(values.size(),vector<int>(values.size(),-1));
        return f(1,values.size()-1,values,dp);
        
    }
};