class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,r=0,maxlen=0;
        unordered_map<int,int> mpp;
        while(r<s.length()){
            mpp[s[r]]++;
            while(mpp[s[r]]>1){
                mpp[s[l]]--;
                if(mpp[s[l]]==0)mpp.erase(s[l]);
                l++;
            }
            if(mpp[s[r]]<=1){
                maxlen=max(maxlen,r-l+1);
            }
            r++;
        }
        return maxlen;
    }
};