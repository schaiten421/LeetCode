class Solution {
public:
    bool f(int i,int j,int sum,int n,vector<int> piles){
        if(sum>=n)return true;
        if(i>j)return false;
        bool left,right;
        if(piles[i]>=piles[j]){
            left=f(i+2,j,sum+piles[i],n,piles)|f(i+1,j-1,sum+piles[i],n,piles);
        }
        else{
            right=f(i,j-2,sum+piles[j],n,piles)|f(i+1,j-1,sum+piles[j],n,piles);
        }
        return left|right;
    }
    bool stoneGame(vector<int>& piles) {
        int sum=0;
        for(auto it:piles)sum+=it;
        
        return true;
    }
};