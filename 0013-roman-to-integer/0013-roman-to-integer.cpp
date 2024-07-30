class Solution {
public:
    int val(char c){
        if(c=='I')return 1;
        else if(c=='V')return 5;
        else if(c=='X')return 10;
        else if(c=='L')return 50;
        else if(c=='C')return 100;
        else if(c=='D')return 500;
        else if(c=='M')return 1000;
        else return -1;
    }
    int romanToInt(string s) {
        int n=s.length();
        int res=0;
        for(int i=0;i<n;i++){
            int s1=val(s[i]);
            if(i+1<n){
                int s2=val(s[i+1]);
                if(s1>=s2){
                    res+=s1;
                }else{
                    res+=(s2-s1);
                    i++;
                }
            }else{
                res+=s1;
            }
        }
        return res;
    }
};