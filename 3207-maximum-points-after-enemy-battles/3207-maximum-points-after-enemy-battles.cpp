class Solution {
public:
    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
        sort(enemyEnergies.begin(),enemyEnergies.end());
        if(enemyEnergies[0]>currentEnergy)return 0;
        int j=enemyEnergies.size()-1;
        long long points=0;
        while(j>=0){
            if(currentEnergy-enemyEnergies[0]>=0){
                points+=currentEnergy/enemyEnergies[0];
                currentEnergy=currentEnergy%enemyEnergies[0];
                
            }
            else{
                currentEnergy+=enemyEnergies[j];
                j--;
            }
        }
        return points;
    }
};