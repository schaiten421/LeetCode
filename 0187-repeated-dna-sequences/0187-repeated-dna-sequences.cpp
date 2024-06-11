class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string,int> ans;
        if(s.length()<=10)return {};
        for(int i=0;i<=s.length()-10;i++){
            ans[s.substr(i,10)]++;
        }
        vector<string> a;
        for(auto it:ans){
            if(it.second>1){
            a.push_back(it.first);}
        }
        return a;
    }
};