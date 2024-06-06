class Solution {
public:
    bool f(int n,int m,string& s, string& p,vector<vector<int>>& dp){
        if(n<0 && m<0) return true;
        if(m<0 && n>=0)return false;
        if(n<0 && m>=0){
            for(int i=0;i<=m;i++){
                if(p[i]!='*') return false;
            }
            return true;
        }
        if(dp[n][m]!=-1)return dp[n][m];
        
        if(s[n]==p[m] || p[m]=='?') return dp[n][m]= f(n-1,m-1,s,p,dp);
        if(p[m]=='*') return dp[n][m]=f(n-1,m,s,p,dp) || f(n,m-1,s,p,dp);
        return dp[n][m]=false;
    }
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(n-1,m-1,s,p,dp);
    }
};