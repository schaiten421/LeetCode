class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int customers=accounts.size(),banks=accounts[0].size(),wealth=INT_MIN;
        for(int i=0;i<customers;i++){
            int res=0;
            for(int j=0;j<banks;j++){
                res+=accounts[i][j];
                
            }
            wealth=max(wealth,res);
        }
        return wealth;
    }
};