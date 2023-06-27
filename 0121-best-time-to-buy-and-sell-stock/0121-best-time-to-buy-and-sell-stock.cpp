class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0,n=prices.size();
        int min_price=INT_MAX;
        for(int i=0;i<n;i++){
            min_price=min(prices[i],min_price);
            profit=max(profit,prices[i]-min_price);
        }
        return profit;
    }
};