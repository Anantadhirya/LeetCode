class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        int cnt = 0;
        for(const int &i: nums) {
            if(i%2 == 0) cnt++;
            if(cnt > 1) return 1;
        }
        return 0;
    }
};