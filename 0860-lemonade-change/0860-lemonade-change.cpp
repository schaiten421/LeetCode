class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int amt1=0,amt2=0,amt3=0;
        for(auto it:bills){
            if(it==5){
                amt1++;
            }
            else if(it==10){
                if(amt1>=1){amt1--;amt2++;}
                else return false;
            }
            else{
                if(amt2>=1 && amt1>=1){amt1--;amt2--;amt3++;}
                else if(amt1>=3){amt1-=3;amt3++;}
                else return false;
            }
        }
        return true;
    }
};