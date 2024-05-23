class Solution {
public:
    int findmax(vector<int> nums){
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi,nums[i]);
        }
        return maxi;
    }
    int divisor(vector<int> nums,int mid){
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans+=(((nums[i]-1)/mid)+1);
        }
        return ans;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1,high=findmax(nums);
        int fin=INT_MAX;
        while(low<=high){
            int mid=low+(high-low)/2;
            int ans=divisor(nums,mid);
            if(ans>threshold){
                low=mid+1;
            }
            else{
                fin=min(fin,mid);
                high=mid-1;
            }
        }
        return fin;
        
    }
};