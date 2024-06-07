class Solution {
public:
    bool isValid(string s) {
        int n=s.length();
        stack<char> st;
        int i=0;
        while(i<n){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
                i++;
            }
            else if(!st.empty() && ((s[i]==')' && st.top()=='(') || (s[i]==']' && st.top()=='[') || (s[i]=='}' && st.top()=='{'))){i++;st.pop();}
            else break;
        }
        return (i==n) && st.empty();
    }
};