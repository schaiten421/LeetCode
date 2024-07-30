class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int el1=INT_MIN,el2=INT_MIN,c1=0,c2=0;
        for(int i=0;i<nums.size();i++){
            if(c1==0 && nums[i]!=el2){
                el1=nums[i];
                c1=1;
            }
            else if(c2==0 && nums[i]!=el1){
                el2=nums[i];
                c2=1;
            }
            else if(nums[i]==el1)c1++;
            else if(nums[i]==el2)c2++;
            else{
                c1--;c2--;
            }
        }
        vector<int> ans;
        int cnt1=0,cnt2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==el1)cnt1++;
            if(nums[i]==el2)cnt2++;
        }
        if(cnt1>nums.size()/3)ans.push_back(el1);
        if(cnt2>nums.size()/3)ans.push_back(el2);
        return ans;
    }
};