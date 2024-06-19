class Solution {
public:
    string reverseVowels(string s) {
        string ans=s;
        string vowels="aeiouAEIOU";
        int l=0,r=s.length()-1;
        while(l<r){
            while(l<r && vowels.find(s[l])==string::npos){
                l++;
            }
            while(l<r && vowels.find(s[r])==string::npos){
                r--;
            }
            swap(ans[l],ans[r]);
            l++;r--;
        }return ans;
    }
};