class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        long long m = mass;
        for(int &a:asteroids){
            if(a>m){
                return false;
            }
            m+=a;
        }
        return true;
    }
};