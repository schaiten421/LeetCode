class Solution {
public:
    int f(string &s,string t,int k){
        int tot=0,ind=0;
        
        for(int i=0;i<s.length();i++){
            s[ind++]=s[i];
            
            if(ind>1 && s[ind-2]==t[0] && s[ind-1]==t[1]){
                ind-=2;
                tot+=k;
            }
        }
        s.erase(s.begin()+ind,s.end());
        return tot;
    }
    int maximumGain(string s, int x, int y) {
        int ans=0;
        if(x>y){
            ans+=f(s,"ab",x);
            ans+=f(s,"ba",y);
        }
        else{
            ans+=f(s,"ba",y);
            ans+=f(s,"ab",x);
        }
        return ans;
    }
};