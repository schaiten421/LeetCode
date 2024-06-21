class Solution {
public:
    bool dictcontains(vector<string> &wordDict,string s){
        if(find(wordDict.begin(),wordDict.end(),s)!=wordDict.end()){
            return true;
        }
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        if(n==0)return true;
        
        vector<int> dp(n+1,0);
        for(int i=0;i<=n;i++){
            if(dp[i]==0 &&dictcontains(wordDict,s.substr(0,i))){
                dp[i]=1;
            }
            if(dp[i]==1){
                if(i==n)return true;
                
                for(int j=i+1;j<=n;j++){
                    if(dp[j]==0 && dictcontains(wordDict,s.substr(i,j-i)))
                        dp[j]=true;
                    if(j==n && dp[j]==true)
                        return true;
                }
            }
        }
        return false;
    }
};