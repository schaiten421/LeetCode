class Solution {
public:
    int f(int ind,int k,vector<int> &energy,vector<int> &dp){
        if(ind>=energy.size())return 0;
        if(dp[ind]!=INT_MIN)return dp[ind];
        int take=energy[ind]+f(ind+k,k,energy,dp);
        return dp[ind]=take;
    }
    int maximumEnergy(vector<int>& energy, int k) {
        int maxi=INT_MIN;
        vector<int> dp(energy.size(),INT_MIN);
        for(int i=0;i<energy.size();i++){
            maxi=max(maxi,f(i,k,energy,dp));
        }
        return maxi;
    }
};