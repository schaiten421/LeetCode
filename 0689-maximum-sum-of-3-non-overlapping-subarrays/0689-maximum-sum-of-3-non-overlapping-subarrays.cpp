class Solution {
public:
    vector<vector<long long>> dp{20002,vector<long long>(4,-1)};
    long long solve(vector<int> presum,int k,int ind,int m){
        int n=presum.size();
        if(ind>=n){
            if(m==0)return 0;
            else return INT_MIN;
        }
        if(m<0)return INT_MIN;
        if(dp[ind][m]!=-1)return dp[ind][m];
        long long take=presum[ind]+solve(presum,k,ind+k,m-1);
        long long nottake=solve(presum,k,ind+1,m);
        return dp[ind][m]=max(take,nottake);
        
    }
    void f(int ind,int m,int k,vector<int> presum,vector<int>& ans){
        int n=presum.size();
        if(ind>=n || m<=0)return;
        
        long long take=presum[ind]+solve(presum,k,ind+k,m-1);
        long long nottake=solve(presum,k,ind+1,m);
        
        if(take>=nottake){
            ans.push_back(ind);
            f(ind+k,m-1,k,presum,ans);
        }
        else{
            f(ind+1,m,k,presum,ans);
        }
    }
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> presum(n+1-k,0);
        for(int i=0;i<k;i++)presum[0]+=nums[i];
        for(int i=1;i<presum.size();i++){
            presum[i]=presum[i-1]+nums[k+i-1]-nums[i-1];
        }
        vector<int> left(n+1-k,0);
        int best=0;
        for(int i=0;i<left.size();i++){
            if(presum[i]>presum[best])best=i;
            left[i]=best;
        }
        vector<int> right(n+1-k,0);
        best=presum.size()-1;
        for(int i=presum.size()-1;i>=0;i--){
            if(presum[i]>=presum[best])best=i;
            right[i]=best;
        }
        vector<int> ans(3,-1);
        for(int j=k;j<presum.size()-k;j++){
            int i=left[j-k],l=right[j+k];
            if(ans[0]==-1 || presum[i]+presum[j]+presum[l]>presum[ans[0]]+presum[ans[1]]+presum[ans[2]]){
                ans[0]=i;
                ans[1]=j;
                ans[2]=l;
            }
        }
        return ans;
    }
};