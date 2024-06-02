class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int l=0,r=0,maxsum=INT_MIN,sum=0,len=0;
        while(r<nums.size()){
            sum+=nums[r];
            if(sum>=maxsum){maxsum=sum; len=r-l+1;}
            if(sum<0){sum=0;l=r+1;}
            r++;
        }
        return maxsum;
        
    }
};