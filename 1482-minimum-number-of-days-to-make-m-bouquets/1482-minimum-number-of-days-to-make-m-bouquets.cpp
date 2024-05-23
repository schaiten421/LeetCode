class Solution {
public:
    int findmax(vector<int> bloomDay){
        int maxi=INT_MIN;
        for(int i=0;i<bloomDay.size();i++){
            maxi=max(maxi,bloomDay[i]);
        }
        return maxi;
    }
    long long bouq(vector<int> bloomDay,int k,int mid){
        //1, 5
        long long totbouq=0,k1=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=mid) k1++;
            else k1=0;
            if(k1==k){
                totbouq++;
                k1=0;
            } 
        }
        return totbouq;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low=1,high=findmax(bloomDay);
        if((long long)m*k>bloomDay.size())return -1;
        long long ans=LONG_MAX;
        while(low<=high){
            long long mid=low+(high-low)/2;
            //5
            long long bouquets=bouq(bloomDay,k,mid);
            
            if(bouquets>=m){ans=min(ans,mid);high=mid-1;}
            else low=mid+1;
        }
        if(ans==LONG_MAX)return -1;
        return ans;
    }
};