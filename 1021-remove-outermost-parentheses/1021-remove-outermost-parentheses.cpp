class Solution {
public:
    string removeOuterParentheses(string a) {
        stack<char> st;
        string ans="";
        for(int i=0;i<a.size();i++){
            if(a[i]=='(' ){
                if(st.size()>0){
                    ans+='(';
                }
                st.push(a[i]);
            }
            else{
                if(st.empty()){continue;}
                else{
                    if(st.size()>1){ans+=')';}
                    st.pop();
                }
            }
        }
        return ans;
        
    }
};

