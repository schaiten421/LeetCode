class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int mn=s.length();
        int n=t.length();
        if(mn!=n)return false;
        vector<bool> vis(256,false);
        vector<int> m(256,-1);
        for(int i=0;i<mn;i++){
            if(m[s[i]]==-1){
                if(vis[t[i]])return false;
                vis[t[i]]=true;
                m[s[i]]=t[i];
            }
            else if(m[s[i]]!=t[i])return false;
            
        }
        return true;
        
    }
};