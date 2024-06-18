class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi=0,maxisofar=0;
        for(int i=1;i<prices.size();i++){
            maxi=max(0,maxi+=prices[i]-prices[i-1]);
            maxisofar=max(maxi,maxisofar);
        }
        return maxisofar;
    }
};