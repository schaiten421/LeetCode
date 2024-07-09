class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int> mpp;
        for(int i=0;i<s.length();i++){
            mpp[s[i]]++;
        }
        for(int i=0;i<t.length();i++){
            if(mpp.find(t[i])!=mpp.end()){
                mpp[t[i]]--;
                if(mpp[t[i]]==0)mpp.erase(t[i]);
            }
        }
        int ans=0;
        for(auto it:mpp){
            ans+=it.second;
        }
        return ans;
    }
};