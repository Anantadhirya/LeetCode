class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int tmp;
        for(int &i: nums) {
            for(int j = 0; (i>>j) > 0; j++) {
                if(((i>>j)&1) == 1 && ((i>>(j+1))&1) == 0) {
                    tmp = i - (1<<j);
                    break;
                }
            }
            if((tmp | (tmp+1)) == i) i = tmp;
            else i = -1;
        }
        return nums;
    }
};