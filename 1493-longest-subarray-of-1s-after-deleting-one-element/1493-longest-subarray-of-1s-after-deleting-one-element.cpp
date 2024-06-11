class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l=0,r=0,cnt=0;
        int maxi=0;
        while(r<nums.size()){
            if(nums[r]==0)cnt++;
            if(cnt<=1){
                maxi=max(maxi,r-l+1);
            }
            else{
                if(nums[l]==0)cnt--;
                l++;
            }
            r++;
        }
        return maxi-1;
    }
};