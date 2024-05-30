class Solution {
public:
    bool isSubsequence(string s, string t) {
        int a=s.length();
        int b=t.length();
        int cnt=0;
        for(int i=0;i<b;i++){
            if(t[i]==s[cnt])cnt++;
        }
        if(cnt==a)return true;
        return false;
    }
};