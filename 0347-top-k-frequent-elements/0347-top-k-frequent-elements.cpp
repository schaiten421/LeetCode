class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        for(auto it:nums)mpp[it]++;
        priority_queue<pair<int,int>> pq;
        for(auto [num,freq]: mpp)pq.push({freq,num});
        vector<int> ans;
        while(k>0){
            auto it=pq.top();
            pq.pop();
            ans.push_back(it.second);
            k--;
            
        }
        return ans;
    }
};