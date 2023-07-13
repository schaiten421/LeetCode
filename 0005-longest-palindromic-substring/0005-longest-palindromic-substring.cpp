class Solution {
public:
    /*bool ispalindrome(string &s,int i,int j){
        int low=i,high=j;
        while(low<=high){
            if(s[low]!=s[high])return false;
            low++;high--;
        }
        return true;
    }*/
    int expand(int i,int j,string &s){
        int left=i;int right=j;
        while(left>=0 && right<s.length() && s[left]==s[right]){
            left--;
            right++;
        }
        return right-left-1;
    }
    string longestPalindrome(string s) {
        /*int n=s.length(),start=0,len=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(ispalindrome(s,i,j))
                    if(j-i+1>len){
                        len=j-i+1;start=i;
                    }
            }
        }
        return s.substr(start,len);*/
     int ans[]={0,0};
        for(int i=0;i<s.length();i++){
            int oddlength=expand(i,i,s);
            if(oddlength>ans[1]-ans[0]+1){
                int dist=oddlength/2;
                ans[0]=i-dist;
                ans[1]=i+dist;
            }
            int evenlength=expand(i,i+1,s);
            if(evenlength>ans[1]-ans[0]+1){
                int dist=(evenlength/2)-1;
                ans[0]=i-dist;
                ans[1]=i+1+dist;
            }
        }
        int i=ans[0];
        int j=ans[1];
        return s.substr(i,j-i+1);
        
    }
};