class Solution {
public:
    int strStr(string haystack, string needle) {
        int len=needle.length();
        int l=haystack.length();
        for(int i=0;i<l-len+1;i++){
            if(needle==haystack.substr(i,len))return i;
        }
        return -1;
    }
};