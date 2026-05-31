class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        long long  curr=mass;
        for(int m : asteroids){
            if(curr<m) return false;

            curr+=m;
        }
        return true;
        
    }
};