class Solution {
private:
    int binarysearch(vector<int> nums,int low,int high,int target){
        while(low<=high){
            int mid=low+(high-low)/2;
            
            if(nums[mid]==target)return mid;
            
            else if(nums[mid]>target)high=mid-1;
            else low=mid+1;
        }
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        return binarysearch(nums,0,nums.size()-1,target);
    }
};