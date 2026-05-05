class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        bitset<101> b;
        int p = 0, c = 0;
        for(int &i: nums) {
            if(!b[i]) {
                b[i] = 1;
                c++;
            } else {
                b[i] = 0;
                c--;
                p++;
            }
        }
        return {p, c};
    }
};