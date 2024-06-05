class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n=matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=0;i<matrix.size();i++){
            dp[n-1][i]=matrix[n-1][i];
        }
        
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<n;j++){
                int down=matrix[i][j]+dp[i+1][j];
                
                int left_down=matrix[i][j];
                if(j>0){
                    left_down+=dp[i+1][j-1];
                }
                else{
                    left_down+=1e9;
                }
                int right_down=matrix[i][j];
                if(j<n-1){
                    right_down+=dp[i+1][j+1];
                }
                else{
                    right_down+=1e9;
                }
                dp[i][j]=min(down,min(left_down,right_down));
            }
        }
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            mini=min(mini,dp[0][i]);
        }
        return mini;
    }
};