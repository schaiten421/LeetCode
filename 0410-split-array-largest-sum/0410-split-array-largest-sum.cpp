class Solution {
private:
    int split(vector<int> nums,int mid){
        int subarrays=1,sum=0;
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]<=mid){
                sum+=nums[i];
            }
            else{
                subarrays++;
                sum=nums[i];
            }
        }
        return subarrays;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int low= *max_element(nums.begin(),nums.end()); //10
        int high= accumulate(nums.begin(),nums.end(),0); //32
        while(low<=high){
            int mid=low+(high-low)/2;
            int ans=split(nums,mid);
            if(ans>k){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
};