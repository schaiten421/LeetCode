class Solution {
public:
    bool canplace(vector<int> position,int mid,int m){
        int cnt=1,last=position[0];
        for(int i=1;i<position.size();i++){
            if(position[i]-last>=mid){
                cnt++;
                last=position[i];
            }
        }
        if(cnt>=m)return true;
        else return false;
    }
    int maxDistance(vector<int>& position, int m) {
        int n=position.size();
        sort(position.begin(),position.end());
        int low=1,high=position[n-1]-position[0];
        while(low<=high){
            int mid=low+(high-low)/2;
            if(canplace(position,mid,m)){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return high;
    }
};