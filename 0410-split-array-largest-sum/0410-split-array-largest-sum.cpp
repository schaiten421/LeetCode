class Solution {
public:
    int f(vector<int> nums,int mid){
        int subarr=1,sum=0;
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]<=mid){
                sum+=nums[i];
            }
            else{
                sum=nums[i];
                subarr++;
            }
        }
        return subarr;
    }
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        while(low<=high){
            int mid=(low+high)/2;
            int noofarr=f(nums,mid);
            if(noofarr>k){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
};