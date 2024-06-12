class Solution {
public:
    void f(int ind,vector<int> nums,vector<int> &temp, vector<vector<int>> &ans,vector<bool> &freq){
        if(ind>=nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(freq[i]==false){
            freq[i]=true;
            temp.push_back(nums[i]);
            f(ind+1,nums,temp,ans,freq);
            temp.pop_back();
            freq[i]=false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;
        vector<bool> freq(nums.size(),0);
        f(0,nums,temp,ans,freq);
        return ans;
    }
};