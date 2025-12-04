class Solution {
public:
    int countCollisions(string directions) {
        int l = 0, r = directions.size() - 1;
        int ans = 0;
        while(l <= r && directions[l] == 'L') l++;
        while(l <= r && directions[r] == 'R') r--;
        for(int i = l; i <= r; i++) ans += (directions[i] != 'S');
        return ans;
    }
};