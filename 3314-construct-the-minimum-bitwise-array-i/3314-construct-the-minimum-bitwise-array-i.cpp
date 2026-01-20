class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int tmp = 0;
        for(int &i: nums) {
            for(int j = 0; j <= 10; j++) {
                if(((i>>j)&1) == 1 && ((i>>(j+1))&1) == 0) {
                    tmp = i - (1<<j);
                    break;
                }
            }
            if((tmp | (tmp + 1)) != i) i = -1;
            else i = tmp;
        }
        return nums;
    }
};