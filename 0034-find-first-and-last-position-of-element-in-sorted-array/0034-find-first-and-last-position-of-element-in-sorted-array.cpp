class Solution {
private:
    int first(vector<int> nums,int low,int high,int target){
        int f=-1;
        //2
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){f=mid;high=mid-1;}
            else if(nums[mid]>target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return f;
    }
    int last(vector<int> nums,int low,int high,int target){
        int f=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){f=mid;low=mid+1;}
            else if(nums[mid]>target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return f;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first_occurence= first(nums,0,nums.size()-1,target);
        int last_occurence= last(nums,0,nums.size()-1,target);
        return {first_occurence,last_occurence};
    }
};