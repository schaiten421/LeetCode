class Solution {
private:
    void f(int ind,string digits,string output,vector<string> &ans, vector<string> nums){
        if(ind>=digits.length()){
            ans.push_back(output);
            return;
        }
        int number=digits[ind]-'0';
        string value=nums[number];
        for(int i=0;i<value.length();i++){
            output.push_back(value[i]);
            f(ind+1,digits,output,ans,nums);
            output.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits=="")return ans;
        string output;
        vector<string> nums={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        f(0,digits,output,ans,nums);
        return ans;
    }
};