class Solution {
public:
    int numberOfChild(int n, int k) {
        int a=k%(2*(n-1));
        if(a<n){return a;}
        else{
            return 2*n-a-2;
        }
    }
};