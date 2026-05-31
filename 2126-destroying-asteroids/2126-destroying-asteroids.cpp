class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long x = mass;
        sort(asteroids.begin(), asteroids.end());
        for(auto &i: asteroids) {
            if(i > x) return 0;
            x += (long long)i;
        }
        return 1;
    }
};