class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int ans = fruits.size();
        for(const int &i: fruits) {
            for(int &j: baskets) {
                if(j >= i) {
                    ans--, j = -1;
                    break;
                }
            }
        }
        return ans;
    }
};