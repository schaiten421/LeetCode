class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        vector<int> cnt(n,1);
        int maxi=-1;
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(nums[i]>nums[prev] && 1+dp[prev]>dp[i]){
                    dp[i]=dp[prev]+1;
                    cnt[i]=cnt[prev];
                }
                else if(nums[i]>nums[prev] && 1+dp[prev]==dp[i]){
                    cnt[i]+=cnt[prev];
                }
            }
            if(dp[i]>maxi)maxi=dp[i];
        }
        int LIS=0;
        for(int i=0;i<n;i++){
            if(dp[i]==maxi){
                LIS+=cnt[i];
            }
        }
        return LIS;
    }
};