class Solution {
public:
    string minWindow(string s, string t) {
        int l=0,r=0,n=s.size(),cnt=0,m=t.size(),mini=1e9,startindex=-1;
        unordered_map<int,int> mpp;
        for(int i=0;i<m;i++){
            mpp[t[i]]++;
        }
        while(r<n){
            if(mpp[s[r]]>0)cnt++;
            mpp[s[r]]--;
            while(cnt==m){
                if(r-l+1<mini){
                    mini=r-l+1;
                    startindex=l;
                }
                mpp[s[l]]++;
                if(mpp[s[l]]>0)cnt--;
                l++;
            }
            r++;
        }
        return startindex==-1?"":s.substr(startindex,mini);
    }
};