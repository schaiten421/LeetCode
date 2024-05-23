class Solution {
public:
    int findmin(vector<int> weights){
        int maxi=INT_MIN;
        for(int i=0;i<weights.size();i++){
            maxi=max(maxi,weights[i]);
        }
        return maxi;
    }
    int findmax(vector<int> weights){
        int maxi=0;
        for(int i=0;i<weights.size();i++){
            maxi+=weights[i];
        }
        return maxi;
    }
    int counter(vector<int> weights,int mid){
        int ans=0,cnt=0;
        for(int i=0;i<weights.size();i++){
            if(ans+weights[i]<=mid){
            ans+=weights[i];}
            else{
                cnt++;ans=weights[i];
            }  
        }
        return cnt+1;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=findmin(weights),high=findmax(weights);
        //32
        
        while(low<=high){
            int mid=low+(high-low)/2;
            int noofdays=counter(weights,mid);
            if(noofdays>days){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
        
    }
};