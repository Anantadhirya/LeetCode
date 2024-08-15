class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int cnt5 = 0, cnt10 = 0;
        for(const auto &i: bills) {
            if(i == 5) cnt5++;
            else if(i == 10) {
                if(cnt5) cnt5--, cnt10++;
                else return 0;
            } else if(i == 20) {
                if(cnt10 && cnt5) cnt10--, cnt5--;
                else if(cnt5 >= 3) cnt5 -= 3;
                else return 0;
            }
        }
        return 1;
    }
};