class Solution {
public:
    bool ispalindrome(string &s,int i,int j){
        int low=i,high=j;
        while(low<=high){
            if(s[low]!=s[high])return false;
            low++;high--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int n=s.length(),start=0,len=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(ispalindrome(s,i,j))
                    if(j-i+1>len){
                        len=j-i+1;start=i;
                    }
            }
        }
        return s.substr(start,len);
    }
};