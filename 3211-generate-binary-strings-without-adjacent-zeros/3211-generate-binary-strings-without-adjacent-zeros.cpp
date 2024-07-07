class Solution {
public:
    void f(int ind,int n,vector<char>& ch,string res,vector<string> &ans){
        if(ind==n){
            ans.push_back(res);
            return;
        }
        for(int i=0;i<2;i++){
            if(ind!=0 && res[ind-1]=='0' && i==0)continue;
            res.push_back(ch[i]);
            f(ind+1,n,ch,res,ans);
            res.pop_back();
        }
        return;
    }
    vector<string> validStrings(int n) {
        vector<string> ans;
        string res;
        vector<char> ch{'0','1'};
        f(0,n,ch,res,ans);
        return ans;
    }
};