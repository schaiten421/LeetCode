class Solution {
public:
    int eat(vector<int> piles,long long mid){
        int h=0;
        for(int i=0;i<piles.size();i++){
            if(piles[i]%mid==0)h+=piles[i]/mid;
            else h+=(piles[i]/mid)+1;
        }
        return h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long tot=0;
        for(int i=0;i<piles.size();i++)tot+=piles[i];
        long long low=1,high=tot;
        while(low<=high){
            long long mid=(low+high)/2;
            if(eat(piles,mid)>h){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
};