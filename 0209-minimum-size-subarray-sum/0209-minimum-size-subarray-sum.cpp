class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res=INT_MAX,sum=0;
        int start=0;
        // 7 res=3 start=4, i=5
        for(int i=0;i<nums.size();){
            if(sum>=target){res=min(res,i-start);
                       sum-=nums[start];start++;}
            else sum+=nums[i++];
        }
        for(int i=start;i<nums.size();i++){
            int s=nums.size();
            if(sum>=target){res=min(res,s-i);
                       sum-=nums[start];start++;}
        }
        if(res>target)return 0;
        else return res;
        
    }
};