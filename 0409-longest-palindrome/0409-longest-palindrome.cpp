class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mpp;
        for(int i=0;i<s.length();i++){
            mpp[s[i]]++;
        }int cnt=0,flag=0;
        for(auto it:mpp){
            if(it.second%2==0){
                cnt+=it.second;
            }
            else if(it.second%2){
                cnt+=it.second-1;
                flag=1;
            }
        }
        if(flag)cnt++;
        return cnt;
    }
};