class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n=nums.size();
        if(n<5)return 0;
        sort(nums.begin(),nums.end());
        return min(nums[n-1]-nums[3],min(nums[n-2]-nums[2],min(nums[n-3]-nums[1],nums[n-4]-nums[0])));
    }
};