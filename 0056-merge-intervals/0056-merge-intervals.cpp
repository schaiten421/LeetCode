class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        int ind=0;
        for(int i=1;i<intervals.size();i++){
            if(ans[ind][1]<intervals[i][0]){
                ans.push_back(intervals[i]);
                ind++;
            }
            else{
                ans[ind][1]=max(ans[ind][1],intervals[i][1]);
            }
        }
        return ans;
    }
};