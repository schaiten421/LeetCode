class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxlen=0,l=0,r=0,n=nums.size(),zeroes=0;
        while(r<n){
            if(nums[r]==0)zeroes++;
            if(zeroes<=k){
                maxlen=max(maxlen,r-l+1);
            }
            else{
                if(nums[l]==0)zeroes--;
                l++;
            }
            r++;
        }
        return maxlen;
    }
};