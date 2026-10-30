class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        sort(ranges.begin(), ranges.end());
        for(auto &i: ranges) {
            if(left < i[0]) return 0;
            left = max(left, i[1]+1);
            if(right < left) return 1;
        }
        return right < left;
    }
};