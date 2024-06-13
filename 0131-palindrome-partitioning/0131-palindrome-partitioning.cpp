class Solution {
public:
    bool isPalindrome(string String, int i, int j)
    {
    while (i < j) {
        if (String[i] != String[j])
            return false;
        i++;
        j--;
    }
    return true;
    }
    void f(int ind,string s,string output,vector<string> &temp,vector<vector<string>> &ans){
        if(ind==s.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=ind;i<s.size();i++){
            if(isPalindrome(s,ind,i)){
                temp.push_back(s.substr(ind,i-ind+1));
                f(i+1,s,output,temp,ans);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        string output="";
        f(0,s,output,temp,ans);
        return ans;
        
    }
};