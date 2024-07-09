class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double ans=0.0000;
        double n=customers.size();
        int time=customers[0][0];
        for(int i=0;i<n;i++){
            if(customers[i][0]>time)time=customers[i][0]+customers[i][1];
            else time+=customers[i][1];
            ans+=time-customers[i][0];
        }
    
        //time=19
        //ans=3+3+7+6+4+2
        return ans/n;
    }
};