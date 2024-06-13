class Solution {
public:
    string frequencySort(string s) {
        map<char,int> mpp;
        for(int i=0;i<s.length();i++){
            mpp[s[i]]++;
        }
        priority_queue<pair<int,char>> pq;
        for(auto it:mpp){
            pq.push({it.second,it.first});
        }
        string ans="";
        while(!pq.empty()){
            auto iter=pq.top();
            pq.pop();
            for(int i=0;i<iter.first;i++)ans+=iter.second;
        }
        return ans;
        
    }
};