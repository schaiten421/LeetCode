class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        n=(n*(n+1))/2;
        for(int i=0;i<nums.size();i++){
            n-=nums[i];
        }
        return n;
    }
};