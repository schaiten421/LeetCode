class Solution {
public:
    bool rotateString(string s, string goal) {
        int m=s.length();
        int n=goal.length();
        if(m!=n)return false;
        for(int i=0;i<m;i++){
            if(s[0]==goal[i]){
                int cnt=0;
                for(int j=0;j<n;j++){
                    if(goal[(i+j)%m]!=s[j])break;
                    cnt++;
                }
                if(cnt==m)return true;
            }
        }
        return false;
    }
};