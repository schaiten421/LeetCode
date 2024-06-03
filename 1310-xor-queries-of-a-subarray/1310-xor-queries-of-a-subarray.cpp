class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        for(int i=1;i<arr.size();i++){
            arr[i]=arr[i]^arr[i-1];
        }
        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            int a=queries[i][0]==0?0:arr[queries[i][0]-1];
            int b=arr[queries[i][1]];
            ans.push_back(a^b);
        }
        return ans;
    }
};