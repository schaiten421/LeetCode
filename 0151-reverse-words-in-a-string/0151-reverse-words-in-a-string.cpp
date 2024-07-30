class Solution {
public:
    string reverseWords(string s) {
        string temp="";
        string ans="";
        int left=0;
        int right=s.length()-1;
        while(left<=right){
            if(left>0 && s[left-1]==s[left] && s[left]==' '){left++;continue;}
            if(s[left]!=' '){
                temp+=s[left];
            }
            else{
                if(ans!="")ans=temp+" "+ans;
                else ans=temp;
                temp="";
            }
            left++;
        }
        if(temp!=""){
            if(ans!="")ans=temp+" "+ans;
            else ans=temp;
        }
        return ans;
    }
};