class Solution {
public:
    bool matching(char a, char b){
        return ((a=='[' && b==']') || (a=='{' && b=='}') || (a=='(' && b==')'));
    }
    bool isValid(string s) {
        int a=s.length();
        stack<char> para;
        for(int i=0;i<a;i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
                para.push(s[i]);
            else{
                if(para.empty()==true)return false;
                else if(matching(para.top(),s[i])==false)return false;
                else para.pop();

            }
        }
        return para.empty()==true;
    }
};