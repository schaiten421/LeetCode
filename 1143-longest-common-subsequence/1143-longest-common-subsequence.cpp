class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1=text1.size();
        int len2=text2.size();
        vector<vector<int>> dp(len1+1,vector<int>(len2+1,0));
        for(int i=0;i<=len1;i++)dp[i][0]=0;
        for(int i=0;i<=len2;i++)dp[0][i]=0;
        for(int i=1;i<=len1;i++){
            for(int j=1;j<=len2;j++){
                if(text1[i-1]==text2[j-1])dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
        
        return dp[len1][len2];
    }
};