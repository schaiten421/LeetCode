class Solution {
public:
    bool check(vector<int>& nums) {
        int cnt=0;
        int size=nums.size();
        for(int i=0;i<nums.size();i++){
            if(nums[i]>nums[(i+1)%size])cnt++;
        }
        if(cnt==0 || cnt==1)return true;
        return false;
    }
};