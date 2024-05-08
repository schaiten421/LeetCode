class Solution {
public:
    int f(int m,int n,string &s1, string &s2,vector<vector<int>>&dp){
        if(m<0 || n<0) return 0;
        if(dp[m][n]!=-1) return dp[m][n];
        if(s1[m]==s2[n]) return dp[m][n]=1+f(m-1,n-1,s1,s2,dp);
        else return dp[m][n]=max(f(m-1,n,s1,s2,dp),f(m,n-1,s1,s2,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size();
        int n=text2.size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return f(m-1,n-1,text1,text2,dp);
    }
};