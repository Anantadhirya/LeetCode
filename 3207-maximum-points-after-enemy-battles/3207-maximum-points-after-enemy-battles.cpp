class Solution {
public:
    long long maximumPoints(vector<int>& energy, int currentEnergy) {
        int n = energy.size();
        int mn = 0;
        long long sm = 0;
        for(int i = 0; i < n; i++) {
            if(energy[i] < energy[mn]) mn = i;
            sm += (long long)energy[i];
        }
        if(currentEnergy < energy[mn]) return 0;
        return (sm - energy[mn] + currentEnergy) / energy[mn];
    }
};