class Solution {
public:
    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
        long long n  = enemyEnergies.size() , points =0  , j = n -1 ;
        sort(enemyEnergies.begin(), enemyEnergies.end())  ;
        if (enemyEnergies[0] > currentEnergy) return 0 ;
        while ( j >= 0 ){
            if (enemyEnergies[0] <= currentEnergy) {
                points += currentEnergy/ enemyEnergies[0] ;
                currentEnergy  %= enemyEnergies[0] ;
                // Above line finds out the remainder .
            }
            else {
                currentEnergy += enemyEnergies[j] ;
                j-- ;
            }
        }
    return points;
    }
};