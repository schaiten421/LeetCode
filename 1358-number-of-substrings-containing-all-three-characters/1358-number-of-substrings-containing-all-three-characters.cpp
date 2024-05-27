class Solution {
public:
    int numberOfSubstrings(string s) {
        int l=0,r=0,count=0;
        vector<int> v(3,-1);
        while(r<s.length()){
            v[s[r]-'a']=r;
            if(v[0]!=-1&&v[1]!=-1&&v[2]!=-1){
                count+=(1+min(v[0],min(v[1],v[2])));
            }
            r++;
        }
        return count;
    }
};