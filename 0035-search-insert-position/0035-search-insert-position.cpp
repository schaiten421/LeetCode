class Solution {
public:
    int f(vector<int> nums,int low,int high,int target){
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target)return mid;
            if(nums[mid]>target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
    int searchInsert(vector<int>& nums, int target) {
        return f(nums,0,nums.size()-1,target);
    }
};