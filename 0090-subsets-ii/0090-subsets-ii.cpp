class Solution {
public:
    vector<vector<int>> ans;
    void f(int ind,int n,vector<int>&temp,vector<int> nums){
        ans.push_back(temp);
        for(int i=ind;i<n;i++){
            if(i!=ind && nums[i]==nums[i-1])continue;
            temp.push_back(nums[i]);
            f(i+1,n,temp,nums);
            temp.pop_back();
        }
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        f(0,n,temp,nums);
        return ans;
    }
};