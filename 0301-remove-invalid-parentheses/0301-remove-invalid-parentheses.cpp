class Solution {
public:
    bool isparenthesis(char ch){
        return ch=='(' || ch==')';
    }
    bool isvalidstr(string str){
        int cnt=0;
        for(int i=0;i<str.length();i++){
            if(str[i]=='('){
                cnt++;
            }
            else if(str[i]==')')cnt--;
            if(cnt<0)return false;
        }
        return cnt==0;
    }
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        bool level=false;
        queue<string> q;
        q.push(s);
        unordered_set<string> vis;
        vis.insert(s);
        while(!q.empty()){
            string str=q.front();
            q.pop();
            if(isvalidstr(str)){
                ans.push_back(str);
                level=true; 
            }
            if(level)continue;
            for(int i=0;i<str.size();i++){
                if(isparenthesis(str[i])==false)continue;
                string s=str.substr(0,i)+str.substr(i+1);
                if(vis.find(s)==vis.end()){
                    q.push(s);
                    vis.insert(s);
                }
            }
        }
        return ans;
        
    }
};