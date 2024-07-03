class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int,int> mpp;
        int cnt=0;
        for(auto num:nums){
            mpp[num]++;
            if(mpp[num]>cnt){
                cnt=mpp[num];
            }
        }
        int ans=0;
        for(auto it:mpp){
            if(it.second==cnt){
                ans+=cnt;
            }
        }
        return ans;
    }
};