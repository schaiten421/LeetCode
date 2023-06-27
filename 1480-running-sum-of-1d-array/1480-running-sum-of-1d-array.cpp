class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n=nums.size();
        int c=nums[0];
        for(int i=1;i<n;i++){
            nums[i]+=c;
            c=nums[i];
        }
        return nums;
    }
};