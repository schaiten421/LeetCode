class Solution {
public:
    void f(int ind,vector<int>&temp, vector<int> nums, vector<vector<int>> &ans){
        ans.push_back(temp);
        for(int i=ind;i<nums.size();i++){
            temp.push_back(nums[i]);
            f(i+1,temp,nums,ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        f(0,temp,nums,ans);
        return ans;
    }
};