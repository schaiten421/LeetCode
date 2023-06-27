class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end());
        int s=0,e=n-1;
        while(s<e){
            if(v[s].first+v[e].first==target){
                return {v[s].second,v[e].second};
            }
            else if(v[s].first+v[e].first>target){
                e--;
            }
            else{
                s++;
            }
        }
        return {-1,-1};
    }
};