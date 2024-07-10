class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans=0;
        for(auto log:logs){
            if(log=="../")ans=max(ans-1,0);
            else if(log=="./")continue;
            else ans++;
        }
        return ans;
        
    }
};