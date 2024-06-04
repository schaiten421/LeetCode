class Solution {
private:
    int f(string s,int ind,vector<int> &dp){
        if(ind==s.length())return 1;
        if(dp[ind]!=-1)return dp[ind];
        int ans=0;
        if(s[ind]!='0') ans+=f(s,ind+1,dp);
        if(ind+1<s.length() && (s[ind]=='1' || s[ind]=='2' && s[ind+1]<='6'))
            ans+=f(s,ind+2,dp);
        return dp[ind]=ans;
    }
public:
    int numDecodings(string s) {
        vector<int> dp(s.length()+1,-1);
        return f(s,0,dp);
    }
};
