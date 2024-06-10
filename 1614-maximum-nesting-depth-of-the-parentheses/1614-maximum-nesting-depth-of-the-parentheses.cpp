class Solution {
public:
    int maxDepth(string s) {
        int n=s.length();
        int i=0;
        int cnt=0;
        int maxlen=0;
        while(i<n){
            if(s[i]=='('){
                cnt++;
            }
            if(s[i]==')'){
                cnt--;
            }
            maxlen=max(maxlen,cnt);
            i++;
        }
        return maxlen;
    }
};