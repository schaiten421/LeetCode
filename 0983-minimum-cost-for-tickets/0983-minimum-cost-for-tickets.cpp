class Solution {
public:
    set<int> traveldays;
    int f(vector<int> days,vector<int> costs,vector<int>& dp,int currday){
        if(currday>days[days.size()-1])return 0;
        if(!traveldays.count(currday)){
            return f(days,costs,dp,currday+1);
        }
        if(dp[currday]!=-1)return dp[currday];
        
        int oneday=costs[0]+f(days,costs,dp,currday+1);
        int sevenday=costs[1]+f(days,costs,dp,currday+7);
        int thirtyday=costs[2]+f(days,costs,dp,currday+30);
        
        return dp[currday]=min(oneday,min(sevenday,thirtyday));
        
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int lastday=days[days.size()-1];
        vector<int> dp(lastday+1,-1);
        for(auto it:days){
            traveldays.insert(it);
        }
        return f(days,costs,dp,1);
    }
};