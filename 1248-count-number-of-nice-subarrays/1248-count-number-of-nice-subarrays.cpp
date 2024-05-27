class Solution {
private: 
    int f(vector<int> nums,int k){
        int l=0,r=0,count=0,sum=0;
        while(r<nums.size()){
            sum+=(nums[r]%2);
            while(sum>k){
                sum-=(nums[l]%2);
                l++;
            }
            if(sum<=k){
                count+=(r-l+1);
            }
            r++;
        }
        return count;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return f(nums,k)-f(nums,k-1);
    }
};