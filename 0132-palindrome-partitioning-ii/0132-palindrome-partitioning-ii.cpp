class Solution {
public:
    bool isPalindrome(string &s,int i,int j){
        while(i<j){
            if(s[i]!=s[j])return false;
            i++;
            j--;
        }
        return true;
    }
    int f(int ind,int n,string &s,vector<int> &dp){
        if(ind==n)return 0;
        if(dp[ind]!=-1)return dp[ind];
        int mini=INT_MAX;
        for(int i=ind;i<n;i++){
            if(isPalindrome(s,ind,i)){
                int num=1+f(i+1,n,s,dp);
                mini=min(mini,num);
            }  
        }
        return dp[ind]=mini;
    }
    int minCut(string s) {
        int n=s.length();
        vector<int> dp(n,-1);
        return f(0,n,s,dp)-1;
    }
};