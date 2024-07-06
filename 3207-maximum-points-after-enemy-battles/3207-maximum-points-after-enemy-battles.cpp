class Solution {
public:
    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
        sort(enemyEnergies.begin(),enemyEnergies.end());
        if(enemyEnergies[0]>currentEnergy)return 0;
        int i=0,j=enemyEnergies.size()-1;
        long long points=0;
        while(j>=0){
            if(currentEnergy-enemyEnergies[i]>=0){
                points+=currentEnergy/enemyEnergies[i];
                currentEnergy=currentEnergy%enemyEnergies[i];
                
            }
            else{
                currentEnergy+=enemyEnergies[j];
                j--;
            }
        }
        return points;
    }
};