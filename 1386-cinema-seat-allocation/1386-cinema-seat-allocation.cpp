class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int ans = 2*n;
        map<int, vector<bool>> m;
        for(auto &i: reservedSeats) {
            if(!m.count(i[0])) m[i[0]] = vector<bool>(10, 1);
            m[i[0]][i[1]-1] = 0;
        }
        for(auto &[row, vec]: m) {
            ans -= 2;
            if(vec[1] && vec[2] && vec[3] && vec[4] && vec[5] && vec[6] && vec[7] && vec[8]) ans += 2;
            else if(vec[1] && vec[2] && vec[3] && vec[4]) ans += 1;
            else if(vec[3] && vec[4] && vec[5] && vec[6]) ans += 1;
            else if(vec[5] && vec[6] && vec[7] && vec[8]) ans += 1;
        }
        return ans;
    }
};