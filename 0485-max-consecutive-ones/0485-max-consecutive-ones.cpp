class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size(),c=0,maxlen=INT_MIN;
        for(int i=0;i<n;i++){
            if(nums[i]==1)c++;
            else c=0;
            maxlen=max(c,maxlen);
        }
        return maxlen;
    }
};