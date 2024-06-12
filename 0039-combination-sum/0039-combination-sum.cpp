class Solution {
public:
    vector<vector<int>> temp;
    void f(int ind,int target,vector<int>&ans,vector<int> candidates){
        if(target==0){
            temp.push_back(ans);
            return;
        }
        if(target<0)return;
        if(ind==candidates.size())return;
        f(ind+1,target,ans,candidates);
        
        ans.push_back(candidates[ind]);
        f(ind,target-candidates[ind],ans,candidates);
        ans.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ans;
        int n=candidates.size();
        f(0,target,ans,candidates);
        return temp;
        
    }
};